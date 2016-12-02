#include<gtest.h>
#include"task.h"
TEST(Ttask, can_create_task_with_positive_length)
{
	ASSERT_NO_THROW(Ttask t(5));
}
TEST(Ttask, can_not_create_task_with_negative_length)
{
	ASSERT_ANY_THROW(Ttask t(-3));
}
TEST(Ttask, can_not_create_task_with_max_length)
{
	ASSERT_ANY_THROW(Ttask t(MAX_TACTS+1));
}
TEST(Ttask, can_get_task)
{
	Ttask t(5);

	EXPECT_EQ(5, t.ReturnTaskTacts());
}