/******************************************************************************************

        aes programının encrypt ve decrypt fonksiyonlarında bir önceki şifreyi cipher adlı
        bir matrise atadım.

        IV cipher dosya olarak dışarıdan alındı(initial chipper)



       main fonksiyonda 3 tane aes işlemi 
       Ci = Encrypt(Pi ^ Ci-1)
       CO = IV,
       cbc mode formülünce şifrelendi
       bu 3 aes işlemi için plainText1,2,3 command arguman line ile alındı

       Pi = Decrypt(Ci) ^ Ci-1
       C0=IV
       cbc mode formülünce de şifreler geri çözüldü
       Her aşamada plain textler matris şekilde bastırıldı.



       Note XOR lama işlemleri main de yapıldı.

*********************************************************************************************/




/**********************************************************************************************/
#include "eof.h"
#include "eofmake.c"






int main(int argc, char *argv[])
{
    if(argc < 5) {
        printf("ERROR: expecting 7 paths \"key_file, 3 plaintext_file, sbox_file, inv_sbox_file,Init_Chipper_file\"\n");
        exit(-1);
    }

    char* key_file = NULL, *state_file = NULL, *sbox_file = NULL, *inv_sbox_file = NULL  ,*Init_Chipper_file = NULL;
    key_file = argv[1];
    sbox_file = argv[2];
    inv_sbox_file = argv[3];
    Init_Chipper_file = argv[4];
     state_file = argv[5];
     int count = 5;
    initialize(key_file, state_file, sbox_file, inv_sbox_file,Init_Chipper_file);



/**************************************************************************************************************/
   
       FILE *file;
       if ((file = fopen(argv[count], "r")) == NULL){
        printf("Error! opening file");
        exit(1);
         }
         int blockSize=0;
         unsigned int input_var;
         while(fscanf(file, "%x", &input_var)!=EOF)
         {
          
            blockSize++;
         }
         
         fclose(file);
        



         blockSize=blockSize/16;



      
      for( int a=0;a<blockSize;a++){



        state_file=argv[count];
        initFromFile(a,STATE_SIZE, plainText, state_file);
       
       
        for(int i=0;i<STATE_SIZE;i++){
           for(int j=0;j<STATE_SIZE;j++){
               state[i][j]=initChipper[i][j];
            }
        }
        encrypt();

        for(int i=0;i<STATE_SIZE;i++){
            for(int j=0;j<STATE_SIZE;j++){
                allChipper[a][i][j]=state[i][j] ^ plainText[i][j];
            }
        }
    
    }






         for(int i=0;i<STATE_SIZE;i++){
            for (int j = 0; j < STATE_SIZE; j++)
            {
               o_key_pad[i][j] = initChipper[i][j] ^ (0x5c * 16);
               i_key_pad[i][j] = initChipper[i][j] ^ (0x36 * 16);
            }
         }
          for(int i=0;i<STATE_SIZE;i++){
            for (int j = 0; j < STATE_SIZE; j++)
            {
               
               state[i][j]=i_key_pad[i][j] || state[i][j];
            }
         }




      for( int a=0;a<blockSize;a++){



        state_file=argv[count];
        initFromFile(a,STATE_SIZE, plainText, state_file);
       
        for(int i=0;i<STATE_SIZE;i++){
           for(int j=0;j<STATE_SIZE;j++){
               state[i][j]=initChipper[i][j];
            }
        }
        encrypt();

        for(int i=0;i<STATE_SIZE;i++){
            for(int j=0;j<STATE_SIZE;j++){
                allChipper[a][i][j]=state[i][j] ^ plainText[i][j];
            }
        }
       

    }


  //// hash(ikeypad || message )
        for(int i=0;i<STATE_SIZE;i++){
            for (int j = 0; j < STATE_SIZE; j++)
            {
               
               i_key_pad[i][j]=state[i][j];
            }
         }


         // o_key_pad[i][j]  ||    hash(i_key_pad|| message);
           for(int i=0;i<STATE_SIZE;i++){
            for (int j = 0; j < STATE_SIZE; j++)
            {
               
                state[i][j]=o_key_pad[i][j]  ||    i_key_pad[i][j];
            }
         }





      for( int a=0;a<blockSize;a++){



        state_file=argv[count];
        initFromFile(a,STATE_SIZE, plainText, state_file);
       
        for(int i=0;i<STATE_SIZE;i++){
           for(int j=0;j<STATE_SIZE;j++){
               state[i][j]=initChipper[i][j];
            }
        }
        encrypt();

        for(int i=0;i<STATE_SIZE;i++){
            for(int j=0;j<STATE_SIZE;j++){
                allChipper[a][i][j]=state[i][j] ^ plainText[i][j];
            }
        }
        

    }



    // RESULT HASH
 


    FILE *fileHash= fopen(argv[count+1],"a");

    for(int i=0;i<STATE_SIZE;i++){
      for(int j=0;j<STATE_SIZE;j++){
        fprintf(fileHash, "%x ",state[i][j] );
      }
    }
 fprintf(fileHash, "\n");
    fclose(fileHash);




       if ((file = fopen(argv[count+1], "r")) == NULL){
        printf("Error! opening file");
        exit(1);
         }
         blockSize=0;
         input_var;
         while(fscanf(file, "%x", &input_var)!=EOF)
         {
          
            blockSize++;
         }
         
         fclose(file);
        



         blockSize=blockSize/16;







         int i;
        for( i=0;i<blockSize-1;i++){
          initFromFile(i,STATE_SIZE, plainText, argv[count+1]);
        }
        initFromFile(i,STATE_SIZE, state, argv[count+1]);





        printMatrix(STATE_SIZE,state);
        printMatrix(STATE_SIZE,plainText);










      int flag=0;
    for(int i=0;i<STATE_SIZE;i++){
        for(int j=0;j<STATE_SIZE;j++){
      
            if(state[i][j]!=plainText[i][j]){
              flag=1;
            }
        }
    }


    if(flag==1){
      printf("CHANGED DOCUMENT\n");
    }
    else{
        printf("NOT CHANGED DOCUMENT\n");
    }
  




     
    return 0;
}


/**********************************************************************************************/

