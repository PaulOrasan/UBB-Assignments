using Sem11_12.Repository;
using Sem11_12.Model;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sem11_12.Service
{
    class PontajService
    {
        private IRepository<string, Pontaj> repo;

        public PontajService(IRepository<string, Pontaj> repo)
        {
            this.repo = repo;
        }

        public List<Pontaj> FindAllPontaje()
        {
            return repo.FindAll().ToList();
        }



        public List<PontajDTO> Salar(int luna)  //4
        {
            return null;
        }

        public IEnumerable<KeyValuePair<Angajat, double>> getCeiMaiHarniciAngajati()
        {
            var angajatHarnici = new Dictionary<Angajat, double>();
            FindAllPontaje().ForEach(pontaj =>
            {
                var ang = pontaj.Angajat;
                var sarc = pontaj.Sarcina;

                double venitPeOra = ang.VenitPeOra;
                int numarOre = sarc.NrOreEstimate;
                if (!angajatHarnici.ContainsKey(ang))
                {
                    angajatHarnici[ang] = 0;
                }
                angajatHarnici[ang] += venitPeOra * numarOre;

            });

            var sortedDict = from entry in angajatHarnici orderby entry.Value descending select entry;
            return sortedDict.Take(2);

        }

    }
}
