//
// Created by pawluch on 3/6/19.
//

#include <gtest/gtest.h>

#include <gtest/gtest.h>
#include <map>
#include <unordered_map>

struct A
{
    std::string className;
    int grade;
};

TEST(map, students)
{
    std::map<std::string, A> grades;
    grades["tommy"] = A{"biology", 3};
    grades["tommy"] = A{"geography", 5};
    auto tommysGrades = grades.at("tommy");

    auto expectedValueInMap = A{"geography", 5};
    EXPECT_EQ(expectedValueInMap.className, tommysGrades.className);
    EXPECT_EQ(expectedValueInMap.grade, tommysGrades.grade);
    EXPECT_EQ(1u ,grades.size());
}

TEST(map, multimap)
{
    std::multimap<std::string, A> grades;
    grades.insert(std::make_pair("tommy", A{"biology", 3}));
    grades.insert(std::make_pair("tommy", A{"geography", 5}));
    grades.insert(std::make_pair("tommy", A{"history", 5}));
    grades.insert(std::make_pair("alex", A{"geography", 5}));

    auto tommysGrades = grades.equal_range("tommy");
    EXPECT_EQ(3u, std::distance(tommysGrades.first, tommysGrades.second));
    for(auto it = tommysGrades.first; it != tommysGrades.second; ++it)
    {
        std::cout << "key: "  << (*it).first << ", value {className, grade}: " << (*it).second.className << ", " << (*it).second.grade <<  std::endl;
    }
    EXPECT_EQ(4u ,grades.size());
}