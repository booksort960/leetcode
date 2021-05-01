#define CAP 4
typedef char STData;
typedef struct Stack//�ṹ������ά��ջ
{
	int top;//ջ�����
	STData* arr;//ջ��ָ��
	int capacity;//ջ������
}STstack;
void InitStack(STstack* st);//ջ�ĳ�ʼ��
void StackPush(STstack* st, STData n);//Ԫ����ջ
STData StackPop(STstack* st);//Ԫ����ջ
void StackExpansion(STstack* st);//����
int StackEmpty(STstack* st);//�ж�ջ�Ƿ�Ϊ��
void StackDestory(STstack* st);//����ջ����ֹ�ڴ�й©
//void StackPrint(STstack* st);//��ӡջ��Ԫ�أ���ǰ����Ҫ��ջ���ܵõ�Ԫ��
void InitStack(STstack* st)//ջ�ĳ�ʼ��
{
	st->top = 0;
	st->arr = (STData*)malloc(CAP * sizeof(STData));
	st->capacity = CAP;
}
void StackPush(STstack* st, STData n)//Ԫ����ջ
{
	if (st->top == st->capacity)//�ж��Ƿ���Ҫ����
	{
		StackExpansion(st);
	}
	st->arr[st->top] = n;
	st->top++;
}
STData StackPop(STstack* st)//Ԫ����ջ
{
	assert(st);
	assert(!StackEmpty(st));//�ж��Ƿ�Ϊ��ջ
	return st->arr[--st->top];
}
int StackEmpty(STstack* st)//�ж�ջ�Ƿ�Ϊ��
{
	if (st->top == 0)
		return 1;
	return 0;
}
void StackDestory(STstack* st)//����ջ����ֹ�ڴ�й©
{
	free(st->arr);
	st->arr = NULL;
}
void StackExpansion(STstack* st)//����
{
	STData* tmp = (STData*)realloc((STData*)st->arr, sizeof(STData) * (st->capacity) * 2);
	if (tmp == NULL)
	{
		printf("Exparsion Error\n");
		exit(-1);
	}
	st->arr = tmp;
	st->capacity *= 2;
}
bool isValid(char* s)
{
	STstack st;
	InitStack(&st);
	while (*s)
	{
		if (*s == '[' || *s == '(' || *s == '{')
		{
			StackPush(&st, *s);//Ԫ����ջ
			s++;
		}
		else
		{
			if (StackEmpty(&st))
				return false;
			char top = StackPop(&st);
			if (
				(top == '[' && *s != ']') ||
				(top == '(' && *s != ')') ||
				(top == '{' && *s != '}')
				)
			{
				return false;
			}
			else//ƥ������
			{
				s++;
			}
		}

	}
	if (!StackEmpty(&st))
	{
		return false;
	}
	StackDestory(&st);
	return true;

}