#include"queue.h"
#include<gtest.h>

TEST(TQueue, can_create_queue_with_positive_length)
{
	ASSERT_NO_THROW(TQueue<int> q(5));
}
TEST(TQueue, can_not_create_queue_with_negative_length)
{
	ASSERT_ANY_THROW(TQueue<int> q(-5));
}
TEST(TQueue, can_not_create_queue_with_max_length)
{
	ASSERT_ANY_THROW(TQueue<int> q(MAX_SIZE_QUEUE+1));
}
TEST(TQueue, get_size_queue)
{
	TQueue<int> q(10);
	
	EXPECT_EQ(10, q.GetSize());
}
TEST(TQueue, get_size)
{
	TQueue<int> q(10);

	EXPECT_EQ(10, q.GetSize());
}
TEST(TQueue, can_get_push_and_get_elem)
{
	TQueue<int> q(10);
	
	q.Push(5);

	EXPECT_EQ(5, q.Pop());
}
TEST(TQueue, Queue_is_empty_while_creating)
{
	TQueue<int> q(10);

	EXPECT_EQ(true, q.IsEmpty());
}
TEST(TQueue, Queue_is_full)
{
	TQueue<int> q(10);
	
	for (int i = 0; i < 10; i++)
		q.Push(i);

	EXPECT_EQ(true, q.IsFull());
}
TEST(TQueue, can_push_elem_and_pop_elem)
{
	TQueue<int> q(10);

	q.Push(10);
	q.Push(10);
	q.Push(10);

	q.Pop();
	q.Pop();
	q.Pop();

	EXPECT_EQ(true, q.IsEmpty());
}

TEST(TQueue, check_that_the_operating_ring)
{
	TQueue<int> q(3);

	q.Push(2);
	q.Push(2);
	q.Pop();
	q.Push(2);
	q.Push(2);

	EXPECT_EQ(2, q.Pop());
	
}
TEST(TQueue, get_count_queue)
{
	TQueue<int> q(5);

	q.Push(1);
	q.Push(1);

	EXPECT_EQ(2, q.GetCount());
}
TEST(TQueue, can_select_a_new_memory)
{
	TQueue<int> q(MAX_SIZE_QUEUE);
	
	for (int i = 0; i < MAX_SIZE_QUEUE; i++)
		q.Push(i);
	q.Push(2);
	
	int size = MAX_SIZE_QUEUE + 1000;

	EXPECT_EQ(size, q.GetSize());
}
TEST(TQueue, throw_on_an_opportunity_to_show_elem_from_an_empty_stack)
{
	TQueue<int> q(5);

	ASSERT_ANY_THROW(q.Top());
}
TEST(TQueue, throw_on_an_opportunity_to_pop_elem_from_an_empty_stack)
{
	TQueue<int> q(5);

	ASSERT_ANY_THROW(q.Pop());
}
TEST(TQueue, check_on_not_empty_queue)
{
	TQueue<int> q(4);

	q.Push(2);

	EXPECT_NE(true, q.IsEmpty());
}

TEST(TQueue, check_on_not_full_queue)
{
	TQueue<int> q(5);


	EXPECT_NE(true, q.IsFull());
}
TEST(TQueue, can_show_elem_of_queue)
{
	TQueue<int> q(4);

	q.Push(4);

	EXPECT_EQ(4, q.Top());
}
TEST(TQueue, can_push_and_pop_elem)
{
	TQueue<int> q(5);

	q.Push(3);

	q.Pop();

	EXPECT_EQ(true, q.IsEmpty());
}

TEST(TQueue, can_push)
{
	TQueue<int> q(5);

	q.Push(3);

	EXPECT_EQ(false, q.IsEmpty());
}