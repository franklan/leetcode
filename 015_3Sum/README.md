## How to remove duplicated resutls?

First ignore this tickets, perhaps we have two ways to add conditions:

Add the condition at the start of loop

```
	int block = 0;
	for (int i = 0;i<100;++i)
	{
		if (block == ***) continue;
		block = ***
	}
```
Or add the condition at the end of loop

```
	for (int i = 0;i<100;)
	{
		if (***)
		{
			// do something
			i++;
		}
		else
		{
			block = ***
			while (block == ***) i++;
		}
	}
```

For the 2nd one, we won't consider the initial value for block. 