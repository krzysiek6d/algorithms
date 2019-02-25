//
// Created by krzysiek on 2/25/19.
//

#include <gtest/gtest.h>
#include <data_structures/versioning.h>
#include <string>

TEST(versioning, tc)
{
    alg::VersionedDB<std::string, int> db{};
    db.add("value1", 666);
    EXPECT_EQ(1, db.makeSnapshot());
    EXPECT_EQ(666, db.get("value1",1));
    EXPECT_EQ(666, db.get("value1"));

    db.add("value1", 777);
    EXPECT_EQ(2, db.makeSnapshot());
    EXPECT_EQ(666, db.get("value1",1));
    EXPECT_EQ(777, db.get("value1",2));
    EXPECT_EQ(777, db.get("value1"));

    db.add("value2", 2000);
    db.add("value3", 3000);
    db.add("value2", 2001);

    EXPECT_EQ(2000, db.get("value2", 3));
    EXPECT_EQ(2000, db.get("value2", 4));
    EXPECT_EQ(2001, db.get("value2", 5));

    EXPECT_EQ(3000, db.get("value3", 4));

    try {
        db.get("value3", 3);
        FAIL();
    }
    catch (const std::exception& e)
    {
        ;
    }
}
