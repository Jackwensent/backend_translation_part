int add(int x,int y)
{
	return x+y;
}

int main()
{
	int a[10],b[10],c[10];
	for(int i=0;i<10;++i)
	{
		a[i]=i;
		b[i]=i;
		c[i]=add(a[i],b[i]);
	}
	return c[5];
}
