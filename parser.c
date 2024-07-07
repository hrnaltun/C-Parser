#include<stdio.h>
#include<string.h>
#include <stdint.h>

int index;
int x = 0;
int j = 1;
//if ve '(' kontrolü
int if_par(char kelime[]) {
  if (kelime[index] == 'i' && kelime[index + 1] == 'f') {
    if (kelime[index + 2] == '(') {
      index = index + 3;
      x = 1;
    } else {
      printf("\n %d . satirda '('konulmadi.", j);
      x = 0;
    }

  } else {
    printf("\n %d . satirda if kismi hatalidir.", j);
    x = 0;

  }
  return index;
}
//degisken kontrol
int id_kont(char kelime[]) {
  if (kelime[index] == 'a' || kelime[index] == 'b' || kelime[index] == 'c' || kelime[index] == 'd' || kelime[index] == 'e' || kelime[index] == 'f') {
    index++;
    if (kelime[index] == 'a' || kelime[index] == 'b' || kelime[index] == 'c' || kelime[index] == 'd' || kelime[index] == 'e' || kelime[index] == 'f' || kelime[index] == '0' || kelime[index] == '1' || kelime[index] == '2' || kelime[index] == '3' || kelime[index] == '4' || kelime[index] == '5' || kelime[index] == '6' || kelime[index] == '7' || kelime[index] == '8' || kelime[index] == '9') {
      x = 0;
      printf("\n %d . satirdaki degisken  '%c%c'  tanimlanmamis.", j, kelime[index - 1], kelime[index]);
    } else {
      x = 1;
    }
  } else if (kelime[index] == '0' || kelime[index] == '1' || kelime[index] == '2' || kelime[index] == '3' || kelime[index] == '4' || kelime[index] == '5' || kelime[index] == '6' || kelime[index] == '7' || kelime[index] == '8' || kelime[index] == '9') {
    index++;
    while (kelime[index] == 'a' || kelime[index] == 'b' || kelime[index] == 'c' || kelime[index] == 'd' || kelime[index] == 'e' || kelime[index] == 'f' || kelime[index] == '0' || kelime[index] == '1' || kelime[index] == '2' || kelime[index] == '3' || kelime[index] == '4' || kelime[index] == '5' || kelime[index] == '6' || kelime[index] == '7' || kelime[index] == '8' || kelime[index] == '9') {
      if (kelime[index] == 'a' || kelime[index] == 'b' || kelime[index] == 'c' || kelime[index] == 'd' || kelime[index] == 'e' || kelime[index] == 'f') {
        printf("\n %d . satirdaki degisken  '%c%c'  tanimlanmamis.", j, kelime[index - 1], kelime[index]);
        x = 0;
        break;
      } else if (kelime[index] == '0' || kelime[index] == '1' || kelime[index] == '2' || kelime[index] == '3' || kelime[index] == '4' || kelime[index] == '5' || kelime[index] == '6' || kelime[index] == '7' || kelime[index] == '8' || kelime[index] == '9') {
        index++;
        x = 1;
      }
    }
  }

  return index;
}
//operatör kontrol
int op_kont(char kelime[]) {
  if (kelime[index] == '<' || kelime[index] == '>' || kelime[index] == '=') {
    index++;
    if (kelime[index] == '=') {
      index++;
      x = 1;
    }
  } else {
    printf("\n %d . satirda tanimlanmamis operator var.", j);
    x = 0;

  }
  return index;
}
//')'ve '{' kontrolü
int kapac(char kelime[]) {
  if (kelime[index] == ')') {
    index++;
    if (kelime[index] == '{') {
      index++;
      x = 1;
    } else {
      printf("\n %d . satirda '{'konulmadi.", j);
      x = 0;
    }
  } else {
    printf("\n %d . satirda ')'konulmadi.", j);
    x = 0;

  }
  return index;
}
//a=a-100 bu koddaki esitligin kontrolü
int esitkont(char kelime[]) {
  if (kelime[index] == '=') {
    x = 1;
    index++;

  } else {
    printf(" \n %d . satirda esittir yok.", j);
    x = 0;

  }
  return index;
}
// 4 islem kontrol
int islemkont(char kelime[]) {
  if (kelime[index] == '+' || kelime[index] == '-' || kelime[index] == '*' || kelime[index] == '/') {
    x = 1;
    index++;
  }
  return index;
}
//süslü kapama parantezi  var mi yok mu kontrolü
int suskapa(char kelime[]) {
  if (kelime[index] == '}') {
    x = 1;
    index++;
  } else {
    printf("\n %d . satirda '}'konulmadi.", j);
    x = 0;
  }
  return index;
}
//else if ve '(' açma kontrolü
int elseifackont(char kelime[]) {
  if (kelime[index] == 'e' && kelime[index + 1] == 'l' && kelime[index + 2] == 's' && kelime[index + 3] == 'e' && kelime[index + 4] == 'i' && kelime[index + 5] == 'f') {
    index += 6;
    if (kelime[index] == '(') {
      x = 1;
      index++;

    } else {
      printf(" \n %d . satirda '(' kullanilmadi.", j);
      x = 0;

    }
  } else {
    printf(" \n %d . else if kismi hatalidir.", j);
    x = 0;

  }
  return index;
}
//else ve süslü parantez açma kontrolü
int elsesuskont(char kelime[]) {
  if (kelime[index] == 'e' && kelime[index + 1] == 'l' && kelime[index + 2] == 's' && kelime[index + 3] == 'e') {
    index += 4;
    if (kelime[index] == '{') {
      index++;
      x = 1;
    } else {
      printf("\n %d . satirda '{'konulmadi.", j);
      x = 0;

    }
  } else {
    printf("\n %d . satirdaki else yazimi hatalidir. ", j);
    x = 0;

  }
  return index;
}

int main() {
  char kelime[400], isim[30], harf;
  int i, k;

  FILE * fp;
  printf("Dosya adini giriniz: ");
  scanf("%s", & isim);
  fp = fopen(isim, "r");

  if (fp != NULL) {
    harf = fgetc(fp);
    kelime[0] = harf;
    while (harf != EOF) {
      harf = fgetc(fp);
      kelime[i] = harf;
      i++;
    }
  } else {
    printf("Dosya ismini kontrol edin ve tekrar girin.");
  }
  int uzunluk = strlen(kelime);

  //bosluk enter tab silme
  for (i = 0; i < uzunluk; i++) {
    if (kelime[i] == 32) {
      for (k = i; k < uzunluk; k++) {
        kelime[k] = kelime[k + 1];
      }
      uzunluk = uzunluk - 1;
    }
    if (kelime[i] == 10) {
      for (k = i; k < uzunluk; k++) {
        kelime[k] = kelime[k + 1];
      }
      uzunluk = uzunluk - 1;
    }
    if (kelime[i] == 9) {
      for (k = i; k < uzunluk; k++) {
        kelime[k] = kelime[k + 1];
      }
      uzunluk = uzunluk - 1;
    }
  }
  uzunluk = uzunluk - 2;
  //tokenizer
  printf("{ ");
  for (i = 0; i < uzunluk; i++) {
    if (kelime[i] == 42 || kelime[i] == 125 || kelime[i] == 94 || kelime[i] == 40 || kelime[i] == 41 || kelime[i] == 91 || kelime[i] == 34 || kelime[i] == 45 || kelime[i] == 59 || kelime[i] == 61 || kelime[i] == 123 || kelime[i] == 60 || kelime[i] == 62 || kelime[i] == 124 || kelime[i] == 33 || kelime[i] == 37 || kelime[i] == 38 || kelime[i] == 47 || kelime[i] == 43) {
      if (kelime[i] == kelime[i + 1]) {
        if (kelime[i + 2] == 41) {
          printf(",%c", kelime[i]);
          printf("%c,", kelime[i + 1]);
          printf("%c", kelime[i + 2]);
          i += 2;
        } else {
          printf(",%c", kelime[i]);
          printf("%c,", kelime[i + 1]);
          i++;
        }
      } else if (kelime[i + 1] == 61 || kelime[i + 1] == 123) {
        printf(",%c", kelime[i]);
        printf("%c,", kelime[i + 1]);
        i++;
      } else if (kelime[i - 1] == 42 || kelime[i - 1] == 43 || kelime[i - 1] == 45 || kelime[i - 1] == 47 || kelime[i - 1] == 59) {
        printf("%c,", kelime[i]);
        printf("%c", kelime[i + 1]);
        i++;
      } else {
        printf(",%c,", kelime[i]);
      }
    } else if (kelime[i] == 93) {
      if (kelime[i + 1] == 61) {
        printf(",%c", kelime[i]);

      }

    } else {
      printf("%c", kelime[i]);
    }
  }
  printf(" }");

  //if kontrolü

  index = 0;
  if_par(kelime);
  if (x == 0) {
    goto etiket;
  }
  id_kont(kelime);
  if (x == 0) {
    goto etiket;
  }
  op_kont(kelime);
  if (x == 0) {
    goto etiket;
  }
  id_kont(kelime);
  if (x == 0) {
    goto etiket;
  }
  kapac(kelime);
  if (x == 0) {
    goto etiket;
  }
  j++;
  if (kelime[index] == 'i') {
    printf("\n ic ice if kullanilamaz.");
    x = 0;
    goto etiket;
  }
  id_kont(kelime);
  if (x == 0) {
    goto etiket;
  }
  esitkont(kelime);
  if (x == 0) {
    goto etiket;
  }
  id_kont(kelime);
  if (x == 0) {
    goto etiket;
  }
  if (kelime[index] == '+' || kelime[index] == '*' || kelime[index] == '/' || kelime[index] == '-') {
    islemkont(kelime);
    if (x == 0) {
      goto etiket;
    }
    id_kont(kelime);
    if (x == 0) {
      goto etiket;
    }

  }
  j++;
  if (kelime[index] == 'i') {
    printf("\n ic ice if kullanilamaz.");
    x = 0;
    goto etiket;
  }
  suskapa(kelime);
  if (x == 0) {
    goto etiket;
  }
  if (kelime[index] == 'i') {
    printf("\n 2. if kullanilamaz.");
    x = 0;
    goto etiket;
  }

  //else if kontrol

  while (kelime[index] == 'e' && kelime[index + 1] == 'l' && kelime[index + 2] == 's' && kelime[index + 3] == 'e' && kelime[index + 4] == 'i') {
    elseifackont(kelime);
    if (x == 0) {
      goto etiket;
    }
    id_kont(kelime);
    if (x == 0) {
      goto etiket;
    }
    op_kont(kelime);
    if (x == 0) {
      goto etiket;
    }
    id_kont(kelime);
    if (x == 0) {
      goto etiket;
    }
    kapac(kelime);
    if (x == 0) {
      goto etiket;
    }
    j++;
    if (kelime[index] == 'i') {
      printf("\n else if in icinde  if kullanilamaz.");
      x = 0;
      goto etiket;
    }
    id_kont(kelime);
    if (x == 0) {
      goto etiket;
    }
    esitkont(kelime);
    if (x == 0) {
      goto etiket;
    }
    id_kont(kelime);
    if (x == 0) {
      goto etiket;
    }
    if (kelime[index] == '+' || kelime[index] == '*' || kelime[index] == '/' || kelime[index] == '-') {
      islemkont(kelime);
      if (x == 0) {
        goto etiket;
      }
      id_kont(kelime);
      if (x == 0) {
        goto etiket;
      }
    }
    j++;
    if (kelime[index] == 'i') {
      printf("\n else if in icinde  if kullanilamaz.");
      x = 0;
      goto etiket;
    }
    suskapa(kelime);
    if (x == 0) {
      goto etiket;
    }

  }
  //else kontrolü
if(kelime[index]=='e'&&kelime[index+1]=='l'){
  elsesuskont(kelime);
  if (x == 0) {
    goto etiket;
  }
  j++;
  if (kelime[index] == 'i') {
    printf("\n else  in icinde  if kullanilamaz.");
    x = 0;
    goto etiket;
  }
  id_kont(kelime);
  if (x == 0) {
    goto etiket;
  }
  esitkont(kelime);
  if (x == 0) {
    goto etiket;
  }
  id_kont(kelime);
  if (x == 0) {
    goto etiket;
  }
  if (kelime[index] == '+' || kelime[index] == '*' || kelime[index] == '/' || kelime[index] == '-') {
    islemkont(kelime);
    if (x == 0) {
      goto etiket;
    }
    id_kont(kelime);
    if (x == 0) {
      goto etiket;
    }
  }
  j++;
  if (kelime[index] == 'i') {
    printf("\n else in icinde  if kullanilamaz.");
    x = 0;
    goto etiket;
  }
  suskapa(kelime);
  if (x == 0) {
    goto etiket;
  }
  if (kelime[index] == 'e') {
    x = 0;
    printf(" \n 2. else kullanilamaz.");
    goto etiket;
  }
}
  etiket:
    if (x == 1) {
      printf("\n Bu dosya dogru bir dosyadir.");
    } else if (x == 0) {
    printf("\n Bu dosya hatali bir dosyadir.");
  }

  fclose(fp);
}
