using Sem11_12.Model;
using Sem11_12.Repository;

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sem11_12.Service
{
    class AngajatService
    {
        private IRepository<string, Angajat> repo;

        public AngajatService(IRepository<string, Angajat> repo)
        {
            this.repo = repo;
        }


        public List<Angajat> FindAllAngajati() {
            return repo.FindAll().ToList();
        }

        public List<Angajat> FindAllAngajatiGroupedSorted() {
            List<Angajat> result = FindAllAngajati().OrderBy(a => a.Nivel).ThenByDescending(a => a.VenitPeOra).ToList();
            return result;
        }

        public List<Angajat> FindAllAngajatiGroupedSortedSqlLike()
        {
            List<Angajat> angajati = FindAllAngajati();
            var juniors = from angajat in angajati
                         where angajat.Nivel == KnowledgeLevel.Junior
                         orderby angajat.VenitPeOra descending
                         select angajat;
            var mediums = from angajat in angajati
                          where angajat.Nivel == KnowledgeLevel.Medium
                          orderby angajat.VenitPeOra descending
                          select angajat;
            var seniors = from angajat in angajati
                          where angajat.Nivel == KnowledgeLevel.Senior
                          orderby angajat.VenitPeOra descending
                          select angajat;

            return juniors.Concat(mediums).Concat(seniors).ToList();
        }
    }
}

