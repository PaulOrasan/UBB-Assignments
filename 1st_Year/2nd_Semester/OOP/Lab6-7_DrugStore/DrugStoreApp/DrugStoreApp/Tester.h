#ifndef TESTER_H
#define TESTER_H

class Tester {
	private:
		class DomainTester {
			public:
				/*
				* Runs all the current available tests for domain
				*/
				void runTests();
			private:
				/*
				* Runs all the current available tests for getters/setters in domain
				*/
				void testGetterSetter();
		}domainTester;

		class ValidationTester {
		public:
			/*
			* Runs all the current available tests for validation
			*/
			void runTests();
		private:
			/*
			* Runs all the current available tests for validating ID
			*/
			void testValidateID();

			/*
			* Runs all the current available tests for validating price
			*/
			void testValidatePrice();
		}validationTester;

		class VectorTester {
		public:
			/*
			* Runs all the current available tests for testing Vector class
			*/
			void runTests();
		private:

			/*
			* Runs all the current available tests for testing append feature in Vector class
			*/
			void testAppend();

			/*
			* Runs all the current available tests for testing erase feature in Vector class
			*/
			void testErase();

			/*
			* Runs all the current available tests for testing sort feature in Vector class
			*/
			void testSort();

			/*
			* Runs all the current available tests for testing filter feature in Vector class
			*/
			void testFilter();
		}vectorTester;
		class RepositoryTester {
			public:
				/*
				* Runs all the current available tests for repository
				*/
				void runTests();
			private:
				/*
				* Runs all the current available tests for adding Drug feature
				*/
				void testAddDrug();

				/*
				* Runs all the current available tests for deleting Drug feature
				*/
				void testDeleteDrug();

				/*
				* Runs all the current available tests for updating Drug feature
				*/
				void testUpdateDrug();

				/*
				* Runs all the current available tests for searching Drug feature
				*/
				void testSearchDrug();

				/*
				* Runs all the current available tests for getting Drugs feature
				*/
				void testGetDrugs();
		}repositoryTester;

		class ServiceTester {
			public:
				/*
				* Runs all the current available tests for service
				*/
				void runTests();
			private:
				/*
				* Runs all the current available tests for adding Drug feature in Service
				*/
				void testServiceAddDrug();

				/*
				* Runs all the current available tests for deleting Drug feature in Service
				*/
				void testServiceDeleteDrug();

				/*
				* Runs all the current available tests for updating Drug feature in Service
				*/
				void testServiceUpdateDrug();

				/*
				* Runs all the current available tests for searching Drug feature in Service
				*/
				void testServiceSearchDrug();

				/*
				* Runs all the current available tests for getting Drugs feature in Service
				*/
				void testServiceGetDrugs();

				/*
				* Runs all the current available tests for sorting Drugs feature in Service
				*/
				void testServiceSort();

				/*
				* Runs all the current available tests for filtering Drugs feature in Service
				*/
				void testServiceFilter();
		}serviceTester;
	public:
		/*
		* Runs all the current available tests
		*/
		void runTests();
};
#endif
