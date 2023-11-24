#include "hash.h"

//SHA_40 Digest


//SHA_40 hash function
unsigned char* SHA_40(const unsigned char* x, size_t size)
{
	unsigned char A = 11;
	unsigned char B = 22;
	unsigned char C = 33;
	unsigned char D = 44;
	unsigned char E = 55;

	for (int i = 0; i < size; i++)
	{
		for (int r = 0; r < 12; r++) {
			unsigned char F = (B & C) ^ D;
			unsigned char newA = A;
			/*Use the diagram to determine what these values should be*/
			A = (F + E) + (A >> 3) + x[i] + r;
			E = D;
			D = C;
			C = (B << 1);
			B = newA;
		}
	}

	unsigned char* digest = (unsigned char*)malloc(DIGEST_SIZE);

	digest[0] = A;
	digest[1] = B;
	digest[2] = C;
	digest[3] = D;
	digest[4] = E;

	return digest;
}
void printDigest(struct Digest* digest)
{
	printf("%d ", digest->hash0);
	printf("%d ", digest->hash1);
	printf("%d ", digest->hash2);
	printf("%d ", digest->hash3);
	printf("%d\n", digest->hash4);
}
//return one (true) or return zero (false)
int digestEqual(struct Digest* digest1, struct Digest* digest2) {
	BYTE digest[5], digestcomp[5];

	digest[0] = digest1->hash0;
	digest[1] = digest1->hash1;
	digest[2] = digest1->hash2;
	digest[3] = digest1->hash3;
	digest[4] = digest1->hash4;
	digestcomp[0] = digest2->hash0;
	digestcomp[1] = digest2->hash1;
	digestcomp[2] = digest2->hash2;
	digestcomp[3] = digest2->hash3;
	digestcomp[4] = digest2->hash4;
	for (int i = 0; i < 5; i++) {
		if (digest[i] != digestcomp[i]) return 0 ;
	}
	return 1;
}