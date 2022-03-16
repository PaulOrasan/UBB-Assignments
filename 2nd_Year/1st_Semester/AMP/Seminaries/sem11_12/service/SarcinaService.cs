using Sem11_12.Repository;
using Sem11_12.Model;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sem11_12.Service
{
    class SarcinaService
    {
        private IRepository<string, Sarcina> repo;

        public SarcinaService(IRepository<string, Sarcina> repo)
        {
            this.repo = repo;
        }



        public List<Sarcina> FindAllSarcini()
        {
            return repo.FindAll().ToList();
        }

        public IEnumerable<KeyValuePair<Dificultate, double>> MediumTime()
        {
            var timpi = new Dictionary<Dificultate, double>();
            FindAllSarcini().ForEach(s =>
            {
                if (!timpi.ContainsKey(s.TipDificultate))
                    timpi[s.TipDificultate] = 0;
                timpi[s.TipDificultate] += s.NrOreEstimate;
            });
            foreach (Dificultate tip in Dificultate.GetValues(typeof(Dificultate)))
            {

                if (timpi.ContainsKey(tip))
                    timpi[tip] /= FindAllSarcini().Where(s => s.TipDificultate == tip).ToList().Count;
            }
            return timpi;
        }
    }
}
