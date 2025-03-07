# Maze Solver Program (README)

## Genel Açıklama
Bu program, 5x5 boyutunda bir labirent haritası üzerinde bir yol bulma algoritması uygular. Program, başlangıç noktasından (0,0) hedef noktasına (4,4) ulaşmaya çalışır. Geçilebilir yollar `1`, engeller `0` ile temsil edilir. Eğer hedefe ulaşılırsa, izlenen yol kaydedilir ve ekrana yazdırılır.

## Programın Çalışma Mantığı
1. `map` değişkeni labirentin mevcut durumunu saklar. `1` değerleri geçilebilir yolları, `0` değerleri engelleri ifade eder.
2. `savedmap`, çözülen yolu ve ziyaret edilen noktaları gösterir.
3. `isValid(x, y)` fonksiyonu, verilen koordinatların harita sınırları içinde olup olmadığını kontrol eder.
4. `pathfind(x, y)` fonksiyonu, derinlik öncelikli arama (DFS) algoritmasıyla yolu bulmaya çalışır:
   - Eğer hedefe ulaşılırsa (`x == 4 && y == 4`), çözüm tamamlanmış kabul edilir.
   - Geçerli bir hücrede bulunuluyorsa, hücre ziyaret edilmiş olarak işaretlenir.
   - Dört farklı yönde (`sağ, aşağı, sol, yukarı`) hareket edilerek yol aranır.
   - Eğer bir yol bulunamazsa, hücre eski haline getirilir ve geri dönülür.

## Kod Açıklamaları

### isValid Fonksiyonu
```c
int isValid(int x, int y){
    return (x >= 0 && x < 5 && y >= 0 && y < 5);
}
```
Bu fonksiyon, verilen `(x, y)` koordinatlarının harita sınırları içinde olup olmadığını kontrol eder. Eğer koordinatlar 5x5 harita sınırları dışına çıkarsa `false (0)`, aksi halde `true (1)` döndürülür.

### pathfind Fonksiyonu
```c
int pathfind(int x,int y){
    if (x == 4 && y == 4) {
        printf("Maze is completed, path: %d\n", sumpath);
        savedmap[y][x]=2;
        return 1;
    }
    if (!isValid(x, y) || map[y][x] == 0) return 0;

    map[y][x] = 0;
    savedmap[y][x] = 2;
```
- `(4,4)` noktasına ulaşıldığında çözüm bulunmuş demektir ve program tamamlanır.
- Eğer mevcut hücre geçersiz (`isValid == 0`) veya bir engelse (`map[y][x] == 0`), fonksiyon çalışmayı durdurur.
- Mevcut hücre `0` olarak işaretlenir ve `savedmap` içerisine `2` kaydedilir (bu hücrenin geçildiğini gösterir).

#### Hareket Kuralları
```c
    if(isValid(x, y+1) && map[y+1][x] == 1){
        sumpath += 1;
        if(pathfind(x,y+1)) return 1;
        sumpath -= 1;
    }
```
- `isValid(x, y+1)`, bir adım aşağı hareketin mümkün olup olmadığını kontrol eder.
- `map[y+1][x] == 1`, gidilecek hücrenin geçilebilir olup olmadığını inceler.
- Benzer şekilde `isValid(x+1, y)`, `isValid(x-1, y)`, `isValid(y-1, x)` ile sağa, sola ve yukarıya hareketler kontrol edilir.
- Hareket edilebiliyorsa `sumpath` artırılır, geri dönüş olursa azaltılır.

## savedmap Kullanımı
Kod çalıştırıldığında, `savedmap` matrisi çözülen yolu saklar:
- `2`: Geçilen hücreler
- `-1`: Geri dönülen hücreler
- `1`: Orijinal geçilebilir hücreler
- `0`: Engeller

Örneğin, bir çözüm sonrası şu şekilde bir çıktı alınabilir:
```
2   0   2   2   2   
2   2   2   0   2   
0   0   0   0   2   
0   0   0   0   2   
0   0   0   0   2   
```

## Yeni Haritalar Eklemek
Eğer farklı bir harita eklemek isterseniz, aşağıdaki `map` ve `savedmap` matrislerini değiştirerek yeni labirentler oluşturabilirsiniz:

```c
int map[5][5] ={{1,1,1,1,1},
                {0,0,1,0,1},
                {1,1,1,0,1},
                {1,0,0,0,1},
                {1,1,1,1,1}};
```
Bu, farklı bir yol bulma senaryosu oluşturacaktır.

## Çalıştırma
Programı bir C derleyicisi ile çalıştırabilirsiniz:
```sh
gcc maze_solver.c -o maze_solver
./maze_solver
```
Eğer hedefe ulaşılabiliyorsa, çözüm yolu yazdırılacaktır. Aksi halde "There is no path" mesajı görüntülenir.

