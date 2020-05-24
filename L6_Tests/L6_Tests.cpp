#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Andrei\source\repos\SMara99\L6\L6\Film.h"
#include "C:\Users\Andrei\source\repos\SMara99\L6\L6\Repository.h"
#include "C:\Users\Andrei\source\repos\SMara99\L6\L6\Watchlist.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace L6Tests
{
	TEST_CLASS(Watchlist)
	{
	public:
		
		TEST_METHOD(add_to_vector)
		{
			Film f1("asd", "asd", 1, 0, "asdasdasd"), f2("asjahsvdnasd", "aasdasdbn", 1, 0, "asdasdasoakjsdd"), f3("asdddddd", "asssssd", 1, 0, "asasdasdasdasddasdasd");
			Watchlist w;
			w.add_to_vector(f1);
			Assert::AreEqual(f1.get_titel(), w.add_to_vector()[0].get_titel());
		}

		TEST_METHOD(remove_from_vector)
		{
			Film f1("asd", "asd", 1, 0, "asdasdasd"), f2("asjahsvdnasd", "aasdasdbn", 1, 0, "asdasdasoakjsdd"), f3("asdddddd", "asssssd", 1, 0, "asasdasdasdasddasdasd");
			Watchlist w;
			w.add_to_vector(f1);
			w.add_to_vector(f2);
			w.remove_from_vector(f1);
			Assert::AreEqual(f2.get_titel(), w.remove_from_vector()[0].get_titel());
		}

		TEST_METHOD(update_in_vector)
		{
			Film f1("asd", "asd", 1, 0, "asdasdasd"), f2("asjahsvdnasd", "aasdasdbn", 1, 0, "asdasdasoakjsdd"), f3("asdddddd", "asssssd", 1, 0, "asasdasdasdasddasdasd");
			Watchlist w;
			w.add_to_vector(f1);
			w.add_to_vector(f2);
			w.update_in_vector(f1,f3);
			Assert::AreEqual(f3.get_titel(), w[0].get_titel());
		}

	};
}
