#include <string.h>
#include <openssl/evp.h>
#include <openssl/rsa.h>
int main()
{
    int ret,ekl[2],npubk,inl,outl,total=0,total2=0;
    unsigned long e=RSA_3;
    char *ek[2],iv[8],in[100],out[500],de[500];
    EVP_CIPHER_CTX ctx,ctx2;
    EVP_CIPHER *type;
    EVP_PKEY *pubkey[2];
    RSA *rkey;
    BIGNUM *bne;
    
    /* 生成RSA 密钥*/
    bne=BN_new();
    ret=BN_set_word(bne,e);
    rkey=RSA_new();
    ret=RSA_generate_key_ex(rkey,1024,bne,NULL);
    
    pubkey[0]=EVP_PKEY_new();
    EVP_PKEY_assign_RSA(pubkey[0],rkey);
    type=EVP_des_cbc();
    
    npubk=1;
    
    EVP_CIPHER_CTX_init(&ctx);
    
    ek[0]=malloc(500);
    ek[1]=malloc(500);
    
    ret=EVP_SealInit(&ctx,type,ek,ekl,iv,pubkey,1); /* 只有一个公钥*/
    if(ret!=1) goto err;
    
    strcpy(in,"openssl 编程");
    inl=strlen(in);
    
    ret=EVP_SealUpdate(&ctx,out,&outl,in,inl);//做加密运算
    if(ret!=1) goto err;
    
    total+=outl;
    
    ret=EVP_SealFinal(&ctx,out+outl,&outl);//做加密运算，制作数字信封。
    if(ret!=1) goto err;
    
    total+=outl;
    
    memset(de,0,500);
    
    EVP_CIPHER_CTX_init(&ctx2);
    
    ret=EVP_OpenInit(&ctx2,EVP_des_cbc(),ek[0],ekl[0],iv,pubkey[0]);
    if(ret!=1) goto err;
    
    ret=EVP_OpenUpdate(&ctx2,de,&outl,out,total);//做解密运算。
    total2+=outl;
    
    ret=EVP_OpenFinal(&ctx2,de+outl,&outl);//做解密运算，解开数字信封。
    total2+=outl;
    
    de[total2]=0;
    
    printf("%s\n",de);
    
err:
    free(ek[0]);
    free(ek[1]);
    EVP_PKEY_free(pubkey[0]);
    BN_free(bne);
    getchar();
    return 0;
}



