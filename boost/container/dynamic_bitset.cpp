/*************************************************************************
	> File Name: dynamic_bitset.cpp
	> Author: He Jieting
    > mail: rambo@mail.ustc.edu.cn
	> Created Time: 2016年03月02日 星期三 14时44分09秒
 ************************************************************************/

#include <boost/dynamic_bitset.hpp>
#include <boost/utility.hpp>
#include <iostream>

int main()
{
    {
        boost::dynamic_bitset<> db1;
        boost::dynamic_bitset<> db2(10);
        //use BOOST_BINARY to creat bitset in complie time
        //better than std::string
        boost::dynamic_bitset<> db3(0x16,BOOST_BINARY(10101));
        //string change to bitset in run time
        boost::dynamic_bitset<> db4(std::string("0100"));
        boost::dynamic_bitset<> db5(db3);
        boost::dynamic_bitset<> db6;
        db6 = db4;

        std::cout << db3.to_ulong() << std::endl;
        std::cout << std::hex << "0x" << db5.to_ulong() << std::endl;
        std::cout << std::dec << db4[0] << db4[1] << db4[2] << std::endl;
    }

    {
        boost::dynamic_bitset<> db;
        db.resize(10,true);
        std::cout << db << std::endl;
        db.resize(5);
        std::cout << db << std::endl;
    }

    {
        boost::dynamic_bitset<> db(5,BOOST_BINARY(01110));
        std::cout << db << std::endl;
        assert(db.size() == 5);

        db.clear();
        assert(db.empty() && db.size() == 0);
    }

    {
        boost::dynamic_bitset<> db(5,BOOST_BINARY(01001));
        //add 1 to the HIGHEST bit
        db.push_back(true);
        assert(db.to_ulong() == BOOST_BINARY_UL(101001));
    }

    {
        boost::dynamic_bitset<> db(5,BOOST_BINARY(01001));
        //append the whole Block to the HIGHEST postion.
        db.append(BOOST_BINARY(101));
        assert(db.size() == sizeof(unsigned long)*8+5);
        std::cout << db << std::endl;
    }

    {
        boost::dynamic_bitset<> db1(4,BOOST_BINARY(1010));
        // and
        db1[0] &= 1;
        // xor
        db1[1] ^= 1;
        std::cout << db1 << std::endl;
        boost::dynamic_bitset<> db2(4,BOOST_BINARY(0101));
        assert(db1 > db2);
        std::cout << (db1 ^ db2) << std::endl;
        std::cout << (db1 | db2) << std::endl;
    }

    {
        boost::dynamic_bitset<> db(4,BOOST_BINARY(0101));

        assert(db.test(0) && !db.test(1));
        assert(db.any() && !db.none());
        assert(db.count() == 2);
    }

    {
        boost::dynamic_bitset<> db(4,BOOST_BINARY(0101));

        db.flip();
        assert(db.to_ulong() == BOOST_BINARY(1010));

        //set all bits as 1
        db.set();
        assert(db.to_ulong() == BOOST_BINARY(1111));

        //set all bits as 0
        db.reset();
        assert(db.to_ulong() == BOOST_BINARY(0000));

        //set db[1] as 1
        db.set(1,1);
        assert(db.to_ulong() == BOOST_BINARY(0010));
    }

    {
        boost::dynamic_bitset<> db(5,BOOST_BINARY(00101));

        //find the first postion equal 1 from the begin.
        auto pos = db.find_first();
        assert(pos == 0);

        //find the next postion equal 1 from the "pos".
        pos = db.find_next(pos);
        assert(pos == 2);
    }

    {
        boost::dynamic_bitset<> db(10,BOOST_BINARY(1010101));
        std::cout << db.to_ulong() << std::endl;
        std::string str;
        boost::to_string(db,str);
        std::cout << str << std::endl;

        db.append(10);
        try
        {
            std::cout << db.to_ulong() << std::endl;
        }
        catch(...)
        {
            std::cout << "catch append exception!" << std::endl;
        }
        boost::to_string(db,str);
        std::cout << str << std::endl;

        db.push_back(1);
        try
        {
            std::cout << db.to_ulong() << std::endl;
        }
        catch(...)
        {
            std::cout << "catch push back exception!" << std::endl;
        }

        boost::to_string(db,str);
        std::cout << str << std::endl;
    }

    {
        boost::dynamic_bitset<> db1(5,BOOST_BINARY(10101));
        boost::dynamic_bitset<> db2(5,BOOST_BINARY(10010));

        std::cout << (db1 | db2) << std::endl;
        std::cout << (db1 & db2) << std::endl;
        std::cout << (db1 - db2) << std::endl;
        std::cout << (db2 - db1) << std::endl;

        boost::dynamic_bitset<> db3(5,BOOST_BINARY(101));
        assert(db3.is_proper_subset_of(db1));

        boost::dynamic_bitset<> db4(db2);
        assert(db4.is_subset_of(db2));
        assert(!db4.is_proper_subset_of(db2));
    }
    return 0;
}
