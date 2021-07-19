# NeoC
Neo C Programming Environment Library

![](https://user-images.githubusercontent.com/85844095/125081210-b6ea7380-e100-11eb-9f34-0871e29de9cc.png)
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;__↑↑↑ examples/Theme.c ↑↑↑__

&emsp;&emsp;&emsp;__↓↓↓ Sample Code (examples/SampleCode.c) ↓↓↓__
```C
#include "NeoC/Environment.h"
#include "NeoC/String.h"
#include "NeoC/Console.h"
#include "NeoC/Exception/Exception.h"
#include "NeoC/Defer.h"
#include "NeoC/Data/Map.h"
#include "NeoC/System.h"

void main() $_ {
   String_t *text = String.New(u8"NeoC is a Neo C Programming Environment Library !");
   Console.WriteLine(text);

   uint8_t target = 'i';
   try {
      defer {
         Map_t *map = Map.New(T(String_t *, int32_t *));

         String_t *s1 = String.New(u8"NeoC!    ");
         String_t *s2 = String.New(u8"NeoC!!!  ");
         String_t *s3 = String.New(u8"NeoC!!!!!");

         int32_t *i1 = (int32_t *)(_Memory.Allocate(sizeof(int32_t)));
         *i1 = 1;
         int32_t *i2 = (int32_t *)(_Memory.Allocate(sizeof(int32_t)));
         *i2 = 3;
         int32_t *i3 = (int32_t *)(_Memory.Allocate(sizeof(int32_t)));
         *i3 = 5;

         map->Put(map, s1, i1);
         map->Put(map, s2, i2);
         map->Put(map, s3, i3);

         for (int32_t i = 0; i < map->GetSize(map); i++) {
            Console.WriteLine(String.NewFormat(
               "%s : %d",
               String.Unpack((String_t *)( map->GetSet(map, i).Key )),
               *(int32_t *)( map->GetSet(map, i).Value )
            ));
         }
      } set

      defer {
         Console.WriteLine(text);
         Console.NewLine();
      } set

      execute {
         int32_t fi = String.FirstIndexOf(text, target);
                   // text->FirstIndexOf(text, target);
         int32_t li = text->LastIndexOf(text, target);
                   // String.LastIndexOf(text, target);

         for (int32_t i = 0; i < String.GetLength(text); i++) {
            Console.WriteChar((i == fi || i == li)? '^' : ' ');
         System.USleep(50 * 1000);
         }
         Console.NewLine();
      } ret
   } catch (String.Failure) {
      Console.WriteErrorLine(String.NewFormat(u8"Target character '%c' not found.", target));
   } fin
} _$
```
<br>

## Build
buildフォルダを作成する。
```fish
$ mkdir build
$ cd build
```

cmakeを使って、以下の中から目的のビルド環境を指定して作成する。

```fish
# コンパイルオプションなし
$ cmake ..

# デバッグするために、-gオプションをつける
$ cmake .. -DCMAKE_BUILD_TYPE=Debug

# 最適化をするために、-O3オプションをつける
$ cmake .. -DCMAKE_BUILD_TYPE=Release
```

ビルドする。

```fish
$ make
```

`build/lib/libNeoC.a` `examples/*`が生成される。
<br><br>


## Clean
```fish
$ cd build
$ make clean
```
<br>

## License
&emsp;[`AGPLv3`](https://www.gnu.org/licenses/agpl-3.0.html)
