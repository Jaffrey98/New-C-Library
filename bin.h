//Header file bin.h

#include<stdio.h>
#include<stdlib.h>

int power(int , int );

//Function to find the decimal equivalent of a binary number

int bin_to_dec(int a[], int n)
{
	//array must be stored in such a way that MSB is at index 0 and LSB at index n-1
	//n is the length of the array	
	
	int i, dec= 0;
	
	if (n<1)
	{
		printf("Error: invalid array size passed to function bin_to_dec()\n"); //the function will throw an error if the array size is invalid.
		exit(0);
	}

	for(i= n- 1; i>= 0; i--)
	{
		if(a[i]< 0 || a[i]> 1)
		{
			printf("Error: invalid binary number passed to function bin_to_dec().\n"); //Function will throw an error if invalid binary number is passed to it. 
			exit(0);
		}
		
		dec= dec+ a[i]*power(2, n-1-i);
	}
	
	return dec; 
}


//Function to calculate a^b

int power(int a, int b)
{
	if(b == 0)
	return 1;
	
	else 
	return a* power(a, b-1); 
}

// gives 1's complement of a binary number
int * ones_complement(int a[],int array[],int n)
{
	int i;

	if (n<1)
	{
		printf("Error: invalid array size passed to function ones_complement()\n"); //the function will throw an error if array size is invalid.
		exit(0);
	}

	for (i = 0; i < n; i++)
	{
		a[i]=array[i];
	}
	
	for (i = 0; i < n; i++)
	{
		if (array[i]==1)
		{
			a[i]=0;
		}
		else if (array[i]==0)
		{
			a[i]=1;
		}
		else
		{
			printf("Error: invalid binary number passed to function ones_complement()\n"); //the function will throw an error if the binary number is invalid.
			exit(0);
		}
	}

	return (a); 

}


// decimal to binary conversion
int * dec_to_bin(int array[],int nb,int n)
{
	if (n<0)
	{
		printf("Error: cannot pass negative number to function dec_to_bin()\n");
		exit(0);
	}

	int i,j;
	for (i = nb-1; i >=0 ; i--)
	{
		array[i]=n%2;
		n=n/2;
	}
	if (n>=1)
	{
		printf("Error: insufficient size of destination array\n");
		exit(0);
	}

	return array;
}

//Two's Complement of a binary number

int * twos_complement(int a[], int arr[], int n)
{
	if (n<1)
	{
		printf("Error: invalid array size passed to function twos_complement()\n"); //the function will throw an error if array size is invalid.
		exit(0);
	}	
	
	//2's complement of arr
	int flag= 0, j;
	for(j= n- 1; j>= 0; j--)
	{
		if(arr[j] > 1 || arr[j]< 0)
		{
			printf("Error: invalid binary number passed to function twos_complement())\n"); //the function will throw an error if the binary number is invalid.
			exit(0);
		}    
		
		if(flag == 0)
		{
			if(arr[j] == 1)
			flag= 1;
			
			a[j]= arr[j];
		}
				
		else
		a[j]= (arr[j]+1)%2;		
	}
	
	return (a);
}


//bin to hexa

char * bin_to_hexa(char a[], int n,int array[],int n1)
{
	int i,j=n-1,sum=0;
	char new_bit;
	if ((n1%4)!=0)
	{
		printf("Error: source array size passed to function bin_to_hexa() should be an integral multiple of 4.\n"); //Function will throw an error if invalid array size is passed to it. 
		exit(0);	
	}

	// if (n < (n1/4)+1)
	if (n < (n1+1)/4)
	{
		printf("Error: invalid destination array size passed to function bin_to_hexa().\n"); //Function will throw an error if invalid array size is passed to it. 
		exit(0);
	}

	for (i = n1-1; i >=0 ; i--)
	{
		if(array[i]< 0 || array[i]> 1)
		{
			printf("Error: invalid binary number passed to function bin_to_hexa().\n"); //Function will throw an error if invalid binary number is passed to it. 
			exit(0);
		}

		sum = sum + array[i]*power(2, (n1-1-i)%4);

		if (i%4==0)
		{

			if (sum>9)
			{
				if (sum==10)
				{
					new_bit='A';
				}
				else if (sum==11)
				{
					new_bit='B';
				}
				else if (sum==12)
				{
					new_bit='C';
				}
				else if (sum==13)
				{
					new_bit='D';
				}
				else if (sum==14)
				{
					new_bit='E';
				}
				else if (sum==15)
				{
					new_bit='F';
				}
				else
				{
					printf("Error\n");
					exit(0);
				}

			}
			else
			{

				new_bit = sum+48;

			}

			a[j]=new_bit;

			j--;

			new_bit=0;
			sum = 0;
		}
		
	}

		return (a);
}


//hexa to bin

int * hexa_to_bin(int a[],int n,char array[],int n1)
{
	int i,j,k,temp,no;

	for(i= 0; i< n; i++)
	a[i]= 0;

	if (n< 4*n1)
	{
		printf("Error: insufficient destination array size passed to function bin_to_hexa() must be an integral multiple of 4.\n"); //Function will throw an error if invalid array size is passed to it. 
		exit(0);
	}
	
	j= 0;
	for (i = n1-1; i >=0 ; i--)
	{
		temp = array[i];
		if (temp>=48&&temp<=57)
		{
			no = temp - 48;

		}
		else
		{
			if (temp==65||temp==97)
			{
				no = 10;
			}
			else if (temp==66||temp==98)
			{
				no = 11;
			}
			else if (temp==67||temp==99)
			{
				no = 12;
			}
			else if (temp==68||temp==100)
			{
				no = 13;
			}
			else if (temp==69||temp==101)
			{
				no = 14;
			}
			else if (temp==70||temp==102)
			{
				no = 15;
			}
			else
			{
				printf("Error: invalid input passed to function bin_to_hexa().\n"); //Function will throw an error if invalid array size is passed to it. 
				exit(0);
			}
		}


		do
		{
			a[n-1-j]=no%2;
			no=no/2;				
			j++;
		}while(((j%4)!=0)&&j< n);
		
	}

	return (a);
}


//dec to hexa
char * dec_to_hexa(char a[], int n,int no)
{
	int temp[4*n],i;
	if (no<0)
	{
		printf("Error: cannot pass negative number to function dec_to_hexa().\n");
		exit(0);
	}
	temp[4*n] = *dec_to_bin(temp,4*n,no);

	a[n] = *bin_to_hexa(a,n,temp,4*n);


	return (a);
}

// hexa to decimal
int hexa_to_dec(char array[],int n1)
{
	int i,dec,temp[n1*4];

	temp[n1*4] = *hexa_to_bin(temp,n1*4,array,n1);
	dec = bin_to_dec(temp,n1*4);
	return (dec);
}


//Function to add two binary numbers
int * bin_add(int a[], int n, int arr1[], int n1, int arr2[], int n2)
{
	//checking whether any of the array sizes are invalid
	
	if(n < n1 || n< n2 || n<= 0 || n1<= 0 || n2<= 0)
	{
		printf("Error: invalid array size passed to function bin_add()\n");
		exit(0);
	}
	
	int C= 0, s, i, j, k;
	
	for(j= 0; j< n; j++)
	a[j]= 0;
	
	//j->  a[], i-> arr1[], k-> arr2[]
	
	for(j= n- 1, i= n1- 1, k= n2- 1; (i>= 0 && k>= 0); j--, i--, k--)
	{
		if(arr1[i] > 1 || arr1[i]< 0 || arr2[k]< 0 || arr2[k]> 1)
		{
			printf("Error: invalid binary number passed to function bin_add()\n"); //the function will throw an error if the binary number is invalid.
			exit(0);
		}
		
		s= arr1[i]+ arr2[k]+ C;
		
		if(s== 1 || s== 0)
		{
			a[j]= s;
			C= 0;
		}

		else if(s == 2)
		{
			a[j]= 0;
			C= 1;
		}

		else if(s == 3)
		{
			a[j]= 1;
			C= 1;
		}
	}
	
	//Copying the elements remaining in arr1[] to a[]
	while(i>= 0)
	{
		if(C == 1)
		{
			s= arr1[i]+ C;
			
			if(s == 1)
			{
				a[j]= 1;
				C= 0;
			}
			
			else 
			a[j]= 0;
		}
		
		else
		a[j]= arr1[i];
		
		i--;
		j--;
	}
	
	//Copying the elements remaining in arr2[] to a[]
	while(k>= 0)
	{
		if(C == 1)
		{
			s= arr2[k]+ C;
			
			if(s == 1)
			{
				a[j]= 1;
				C= 0;
			}
			
			else 
			a[j]= 0;
		}
		
		else
		a[j]= arr2[k];
		
		k--;
		j--;
	}
	
	if(C == 1)
	{
		if(j == -1)
		{
			//if carry is 1 and there is no space left in the destination array, then the function throws an error
			printf("Error: invalid array size passed to function bin_addDDDDD()\n");
			exit(0);
		}
		
		else
		{
			while(C != 0 && j> -1)
			{
				
				s= a[j]+ C;
				if(s == 1)
				{
					a[j]= 1;
					C= 0;
				}
				
				else
				{
					a[j]= 0;
					C= 1; 
				}
				
				j--;
				
			}
		}
	}
	
	return(a);

}


//function to return the product of two binary numbers 

int * bin_mult(int a[], int n, int arr1[], int n1, int arr2[], int n2)
{
	//checking whether any of the array sizes are invalid
	
	if(n < (n1+n2) || n<= 0 || n1<= 0 || n2<= 0)
	{
		printf("Error: invalid array size passed to function bin_mult()\n");
		exit(0);
	}
	
	int C= 0, s, i, j, k, l, temp[n2], acc[n1];
	
	for(j= 0; j< n; j++)
	a[j]= 0;
	
	for(j= 0; j< n1; j++)
	acc[j]= 0;
	
	for(j= 0; j< n2; j++)
	temp[j]= arr2[j];
	
	for(k= 0; k< n2; k++)
	{
		if(temp[n2-1] == 1)
		{
			//Add
			
			for(i= n1- 1; i>= 0; i--)
			{
				s= acc[i]+ arr1[i]+ C;
		
				if(s== 1 || s== 0)
				{
					acc[i]= s;
					C= 0;
				}

				else if(s == 2)
				{
					acc[i]= 0;
					C= 1;
				}

				else if(s == 3)
				{
					acc[i]= 1;
					C= 1;
				}
			}
		}
		
		//Shift

		for(j= n2- 1; j>= 1; j--)
		temp[j]= temp[j- 1];

		temp[0]= acc[n1- 1];

		for(j= n1- 1; j>= 1; j--)
		acc[j]= acc[j- 1];

		acc[0]= C;
		C= 0;
	}
	
	//copying temp[] to a[]
	
	for(j= n- 1, l= n2- 1; l>= 0; j--, l--)
	a[j]= temp[l];
	
	for(l= n1- 1; l>= 0; l--, j--)
	a[j]= acc[l]; 
	
	return(a);
}


//function to return the difference between two binary numbers 

int * bin_diff(int a[], int n, int arr1[], int n1, int arr2[], int n2)
{
	//checking whether any of the array sizes are invalid
	
	if(n<= 0 || n1<= 0 || n2<= 0)
	{
		printf("Error: invalid array size passed to function bin_diff()\n");
		exit(0);
	}
	
	int C= 0, s, i, j, k;
	
	for(i= 0; i< n; i++)
	a[i]= 0;
	
	int dec1= bin_to_dec(arr1, n1);
	int dec2= bin_to_dec(arr2, n2);
	
	if(dec1> dec2)
	a[n]= *dec_to_bin(a, n, dec1- dec2);
	
	else
	a[n]= *dec_to_bin(a, n, dec2- dec1);
	
	return(a);
}


//function to return the octal equivalent of a binary number 

int * bin_to_octa(int a[], int n, int array[], int n1)
{
	
	int i, j= n-1, sum= 0;
	
	for(i= 0; i< n; i++)
	a[i]= 0;
	
	if ((n1%3)!=0)
	{
		printf("Error: source array size passed to function bin_to_octa() should be an integral multiple of 3.\n"); //Function will throw an error if invalid array size is passed to it. 
		exit(0);	
	}

	// if (n < (n1/4)+1)
	if (n < (n1+1)/3)
	{
		printf("Error: invalid destination array size passed to function bin_to_octa().\n"); //Function will throw an error if invalid array size is passed to it. 
		exit(0);
	}

	for (i = n1-1; i >=0 ; i--)
	{
		if(array[i]< 0 || array[i]> 1)
		{
			printf("Error: invalid binary number passed to function bin_to_octa().\n"); //Function will throw an error if invalid binary number is passed to it. 
			exit(0);
		}

		sum = sum + array[i]*power(2, (n1-1-i)%3);
	
		if (i%3==0)
		{
			a[j]= sum;
			j--;
			sum = 0;
		}
	}

	return (a);
}


//function to return the binary equivalent of an octal number 

int * octa_to_bin(int a[], int n, int array[], int n1)
{	
	int i, j, k, no;

	for(i= 0; i< n; i++)
	a[i]= 0;

	if (n < 3*n1)
	{
		printf("Error: insufficient destination array size passed to function octa_to_bin() must be an integral multiple of 3.\n"); //Function will throw an error if invalid array size is passed to it. 
		exit(0);
	}
	
	j= 0;
	
	for (i = n1-1; i >=0 ; i--)
	{
		no = array[i];
		if (no > 7 || no < 0)
		{
			printf("Error: invalid octal number passed to function octa_to_bin().\n"); //Function will throw an error if invalid octall number is passed to it. 
			exit(0);
		}

		do
		{
			a[n-j-1]= no%2;
			no= no/2;				
			j++;
		}while(((j%3) != 0) && j < n);
		
	}

	return (a);
}


//function to return the decimal equivalent of an octal number 
int octa_to_dec(int a[], int n)
{
	
	int i, dec= 0;
	
	if (n<1)
	{
		printf("Error: invalid array size passed to function octa_to_dec()\n"); //the function will throw an error if the array size is invalid.
		exit(0);
	}

	for(i= n- 1; i>= 0; i--)
	{
		if(a[i]< 0 || a[i]> 7)
		{
			printf("Error: invalid octal number passed to function octa_to_dec().\n"); //Function will throw an error if invalid octal number is passed to it. 
			exit(0);
		}
		
		dec= dec+ a[i]*power(8, n-1-i);
	}
	
	return dec; 
}

//function to return the octal equivalent of a decimal number
int * dec_to_octa(int a[], int n, int dec)
{	
	if (dec<0)
	{
		printf("Error: cannot pass negative number to function dec_to_octa().\n");
		exit(0);
	}

	if(n< 1)
	{
		printf("Error: invalid array size passed to function dec_to_octa()\n"); //the function will throw an error if the array size is invalid.
		exit(0);
	}
	
	int j;
	
	for(j= 0; j< n; j++)
	a[j]= 0;
	
	j= n- 1;
	
	while(dec> 0)
	{
		if(j == -1)
		{
			printf("Error: insufficient destination array size passed to function dec_to_octa()\n");
			exit(0);
		}
		
		a[j]= dec%8;
		dec= dec/8;
		j--;
	}
	
	return a;
}


//7 bit hamming code
int * hamming_7(int a[], int n, int arr[], int n1, int parity)
{
	if(n != 7 || n1 != 4)
	{
		printf("Error: invalid array size passed to function hamming_7()\n"); //the function will throw an error if the array size is invalid.
		exit(0);
	}
	
	if(parity > 1 || parity < 0)
	{
		printf("Error: invalid parity bit passed to function hamming_7()\n"); //the function will throw an error if the parity bit is invalid.
		exit(0);
	}
	
	int i;
	
	for(i= 0; i< 4; i++)
	{
		if(arr[i]< 0 || arr[i]> 1)
		{
			printf("Error: invalid data bits passed to function hamming_7()\n");
			exit(0);
		}
	}
	
	//D3= arr1[0], D5= arr1[1], D6= arr1[2], D7= arr[3]	
	
	a[0]= arr[0];
	a[1]= arr[1];
	a[2]= arr[2];
	a[4]= arr[3];
	
	a[6]= arr[3]^arr[2]^arr[0]^parity;
	a[5]= arr[3]^arr[1]^arr[0]^parity;
	a[3]= arr[2]^arr[1]^arr[0]^parity;
	
	return a;
}

//12 b =it hamming code
int * hamming_12(int a[], int n, int arr[], int n1, int parity)
{
	if(n != 12 || n1 != 8)
	{
		printf("Error: invalid array size passed to function hamming_12()\n"); //the function will throw an error if the array size is invalid.
		exit(0);
	}
	
	if(parity > 1 || parity < 0)
	{
		printf("Error: invalid parity bit passed to function hamming_12()\n"); //the function will throw an error if the parity bit is invalid.
		exit(0);
	}
	
	int i;
	
	for(i= 0; i< 8; i++)
	{
		if(arr[i]< 0 || arr[i]> 1)
		{
			printf("Error: invalid data bits passed to function hamming_12()\n");
			exit(0);
		}
	}
	
	//D3= arr1[0], D5= arr1[1], D6= arr1[2], D7= arr[3]	
	
	a[0]= arr[0];
	a[1]= arr[1];
	a[2]= arr[2];
	a[3]= arr[3];
	a[5]= arr[4];
	a[6]= arr[5];
	a[7]= arr[6];
	a[9]= arr[7];
	
	a[11]= arr[7]^arr[6]^arr[4]^arr[3]^arr[1]^parity;
	a[10]= arr[7]^arr[5]^arr[4]^arr[2]^arr[1]^parity;
	a[8]= arr[6]^arr[5]^arr[4]^arr[0]^parity;
	a[4]= arr[3]^arr[2]^arr[1]^arr[0]^parity;
	
	return a;
}
