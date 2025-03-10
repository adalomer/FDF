giriş

FDF projesi, 42 Okul müfredatının grafik dalının bir parçası olarak geliştirilen bir 3B Tel Çerçeve Görüntüleyicisidir. Özellikle render alanında grafik programlamaya odaklanan bir yazılım geliştirme projesidir. Projenin temel amacı, bir kabartma manzaranın basitleştirilmiş bir 3B grafik temsilini oluşturmaktır.

Program, uzaydaki noktaları temsil eden bir koordinat kümesi içeren bir dosyayı girdi olarak alır. Her koordinat, ekrandaki bir piksele karşılık gelir; X ve Y değerleri, ekrandaki koordinatları temsil eder ve Z değeri pikselin rengini belirler.

Noktaları çizgilerle birleştirerek program, genellikle üçgenler veya dörtgenler olan çokgenlerden oluşan bir ızgara oluşturan bir tel kafes ağı oluşturur. Bu tel kafes gösterimi manzaranın görsel bir tasvirini sağlar.

FDF projesi C dilinde yazılmıştır ve proje için sağlanan basit bir grafik kütüphanesi olan miniLibX'i kullanır. 3B projeksiyonlar, olay odaklı programlama ve grafik kütüphanelerinin kullanımı hakkında bilgi edinmek için harika bir fırsat sunar. Özellikle matris ve vektör işlemleri olmak üzere matematiğin iyi anlaşılmasını gerektiren zorlu bir projedir.

Genel olarak, FDF projesi öğrencilerin grafik programlama dünyasına dalmalarına ve render ve görselleştirme becerilerini geliştirmelerine olanak tanır. Bilgisayar grafikleri alanında daha karmaşık projeler için bir temel görevi görür.


Genel bakış

FDF projesi, 2B koordinat kümesinden 3B tel kafes modellerini görselleştiren C dilinde yazılmış bir grafik uygulamasıdır. Programın girdisi, 3B uzaydaki noktaları temsil eden koordinatları içeren bir dosyadır. Her nokta, X, Y ve Z değerleriyle tanımlanır; burada X ve Y, ekrandaki piksel koordinatlarına karşılık gelir ve Z, pikselin renk yoğunluğunu belirlemek için kullanılabilen yüksekliği veya derinliği temsil eder.

FDF projesinin temel işlevi, bu koordinatları okumak ve bunları ekranda bir tel kafes ağı olarak işlemektir. Bu ağ, noktaları çizgilerle birleştirerek, genellikle üçgenler veya dörtgenler olan çokgenlerden oluşan bir ızgara oluşturarak oluşturulur. Ortaya çıkan tel kafes, 3B manzaranın görsel bir temsilini sağlar.

Proje, tel kafesin işlenmesi ve görüntülenmesi için basit ama güçlü bir grafik kütüphanesi olan miniLibX'i kullanır. MiniLibX, pencereler oluşturmak, piksel çizmek ve kullanıcı girdisini işlemek için temel işlevler sağlar ve bu da onu bu proje için ideal bir seçim haline getirir.

FDF projesinin temel teknik yönleri şunlardır:

3D Projeksiyonlar : Çeşitli projeksiyon teknikleri kullanılarak 3D koordinatların 2D ekran koordinatlarına dönüştürülmesi.
Matris ve Vektör İşlemleri : Koordinat kümesi üzerinde öteleme, döndürme, ölçekleme gibi dönüşümlerin gerçekleştirilmesi.
Olay Odaklı Programlama : Tel kafesle etkileşime girmek için kullanıcı girdilerini işlemek, örneğin görünümü döndürmek veya yakınlaştırmak.
Grafik Oluşturma : Tel kafes örgüsünü oluşturmak için çizgileri ve çokgenleri etkili bir şekilde çizme.
FDF projesi, bilgisayar grafikleri, matematiksel dönüşümler ve olay odaklı programlama konusundaki anlayışınızı derinleştirmek için mükemmel bir fırsattır. Grafik programlama alanında daha ileri konulara sizi hazırlayan temel bir proje görevi görür.

Proje Gereksinimleri - Zorunlu Parça
Önemli Kurallar:

Projenin Norm kurallarına uygun olarak C dilinde yazılması gerekmektedir.
Fonksiyonlar, segmentasyon hataları veya çift serbest bırakmalar gibi beklenmeyen hatalara sahip olmamalıdır. Tanımsız davranışlardan kaçının.
Gerektiğinde dinamik olarak ayrılmış tüm belleği uygun şekilde serbest bırakın.
Kaynak dosyalarını -Wall, -Wextra ve -Werror bayraklarıyla derleyen bir Makefile ekleyin. cc derleyicisini kullanın. Makefile yeniden bağlanmamalıdır. $(NAME), all, clean, fclean ve re kurallarını içermelidir. Ek kurallar eklenirse bonus puanlar.
İzin verilirse, libft'nizi kullanın. Kaynaklarını ve Makefile'ını bir libft klasörüne kopyalayın. Projenin Makefile'ı, Makefile'ını kullanarak kütüphaneyi derlemeli ve ardından projeyi derlemelidir.
Global değişkenleri kullanmayın.
Pencere ve Grafik Yönetimi

Programın resmi bir pencere içerisinde göstermesi gerekmektedir.
Pencere yönetimi akıcı olmalı, başka bir pencereye geçme veya simge durumuna küçültme gibi işlemlerin sorunsuz bir şekilde yapılabilmesine olanak sağlamalıdır.
ESC tuşuna basıldığında pencere kapanacak ve program temiz bir şekilde sonlandırılacaktır.
MiniLibX imajlarının kullanımı zorunludur. FDF projesinde MiniLibX kütüphanesinin düzgün kullanımını sağlamak için çizim fonksiyonlarının uygulandığı dosyaları doğrulayın ve MiniLibX kütüphane fonksiyonlarını kontrol edin.
Pencerenin çerçevesindeki kapatma düğmesine tıklandığında da pencere kapatılmalı ve program temiz bir şekilde sonlandırılmalıdır.
Program adı
fdf

Kullanım

Programı çalıştırmak için aşağıdaki sözdizimini kullanın:

./fdf <map_name.fdf>
<map_name.fdf>FDF harita dosyanızın yolunu yazın .

Genel bakış

Bu program, bir dosyada saklanan ve parametre olarak sağlanan manzara koordinatlarına dayalı bir modelin izometrik bir projeksiyonunu oluşturur .fdf. Koordinatların nasıl yorumlandığı aşağıdadır:



0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0





Yatay konum x eksenine karşılık gelir.
Dikey konum y eksenine karşılık gelir.
Değer yüksekliğe (z ekseni) karşılık gelir.
Program, dosyadan verileri verimli bir şekilde okumak için tasarlanmıştır ve sağlanan tüm haritaları çökmeden işlemelidir. Okul tarafından sağlanan tüm haritaları burada bulabilirsiniz .

Gönderilecek Dosyalar
Makefile, *.h, *.c

İzin Verilen Harici Fonksiyonlar

Programın çalışması için aşağıdaki fonksiyonlara ve kütüphanelere ihtiyaç vardır:

Dosya G/Ç işlevleri: open, close, read,write
Bellek yönetimi işlevleri: malloc,free
Hata işleme işlevleri: perror, strerror,exit
Matematik kütüphanesi fonksiyonları: Matematik kütüphanesindeki tüm fonksiyonlar (-lm derleyici seçeneği, man man 3 math)
MiniLibX işlevleri: MiniLibX kitaplığındaki tüm işlevler
Özel printf fonksiyonu: ft_printfveya uyguladığınız herhangi bir eşdeğer fonksiyon
Programın okul makinelerinde bulunan MiniLibX kütüphanesini kullanması gerektiğini unutmayınız.

MiniLibX Kütüphanesi
MiniLibX'e Başlarken

MiniLibX kütüphanesi, öğrenciler için tasarlanmış hafif bir X-Window arayüz kütüphanesidir. Kapsamlı bir X-Window programlama bilgisi gerektirmeden grafiksel yazılım oluşturmanın basit ve sezgisel bir yolunu sağlar. MiniLibX ile kolayca pencereler oluşturabilir, grafikler çizebilir, görüntüleri yönetebilir ve temel olayları işleyebilirsiniz. Etkileşimli grafiksel uygulamalar geliştirmenize ve bir pencere içinde görüntüleri görüntülemenize olanak tanıyan çok yönlü bir kütüphanedir. MiniLibX hem macOS hem de Linux sistemleri için kullanılabilir ve projenize sorunsuz bir şekilde entegre edilebilir. MiniLibX'i kullanarak, X-Window sistemiyle çalışma sürecini kolaylaştırabilir, programlama ihtiyaçlarınız için daha erişilebilir ve verimli hale getirebilirsiniz.

MiniLibX'i Kurma

MiniLibX'i kurmak için şu adımları izleyin:

Sisteminize uygun MiniLibX versiyonunu seçin.
Kütüphaneyi çıkartın ve mlxmacOS veya mlx_linuxLinux için olarak yeniden adlandırın.
Ubuntu'da aşağıdaki komutu çalıştırarak MiniLibX için gerekli bağımlılıkları Linux'a yükleyin:
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
configureMiniLibX'i deponun kökündeki betiği çalıştırarak yapılandırın .
./configure
Aşağıdaki mesajı görmelisiniz:

configure [info] : Execute "make all" from file "test/makefile.gen"
gcc -I/usr/include -O3 -I.. -g   -c -o main.o main.c
gcc -o mlx-test main.o -L.. -lmlx -L/usr/include/../lib -lXext -lX11 -lm -lbsd
make allMLX kütüphanesinin yalnızca . komutunu değil, aynı zamanda make. komutunu da kullanması gerektiğini unutmayın .

Bu adımları takip ederek MiniLibX'i kurmuş ve projenizde kullanmaya hazır hale getirmiş olacaksınız.

MiniLibX'i Projenize Dahil Etme

MiniLibX'i projenize entegre etmek için mlx.hbaşlık dosyasını eklemeniz gerekir. Bu dosya MiniLibX fonksiyonları için fonksiyon prototipleri içerir. Ek olarak, yazılımınızı MiniLibX kütüphanesi de dahil olmak üzere gerekli kütüphanelerle bağlamanız gerekir.

MiniLibX'e Giriş

MiniLibX'e başlamak için, yazılımınız ve ekran arasında bir bağlantı kurmanız gerekir. Bu , daha fazla kütüphane çağrısı için mlx_initbir tanımlayıcı döndüren işlevi çağırarak gerçekleştirilebilir .void *

Bağlantı kurulduktan sonra, pencereleri yönetmek, grafik çizmek, görüntüleri düzenlemek ve klavye veya fare olaylarını işlemek için çeşitli MiniLibX işlevlerinden yararlanabilirsiniz. Bu işlevlerden bazıları şunlardır mlx_new_window: , mlx_pixel_put, mlx_new_imageve mlx_loop.

Eğer mlx_init()fonksiyon X sunucusuna bağlantıyı kurmayı başaramazsa, NULL döndürecektir. Aksi takdirde, bağlantı tanımlayıcısı olarak null olmayan bir işaretçi sağlayacaktır.

MiniLibX ile Görüntüleri Düzenleme

mlx_new_image: Bu fonksiyon bellekte yeni bir görüntü oluşturur. Oluşturulacak görüntünün boyutunu ve bağlantı tanımlayıcısını gerektirir. Fonksiyon daha sonra görüntüyü işlemek için kullanılabilecek bir boş işaretçi döndürür.

mlx_put_image_to_window: Bu fonksiyon ekranda bir görüntü görüntüler. Ekrana bağlantı, kullanılacak pencere ve görüntü için tanımlayıcılara ihtiyaç duyar. Ayrıca görüntünün pencereye yerleştirilmesi gereken koordinatlara da ihtiyaç duyar.

mlx_get_data_addr: Bu fonksiyon, oluşturulan görüntü hakkında bilgi döndürür ve daha sonra değiştirmenize olanak tanır. Görüntü işaretçisini ve üç farklı geçerli tam sayının adreslerini gerektirir. Görüntünün depolandığı bellek alanının başlangıcını temsil eden bir char işaretçisi döndürür.

mlx_destroy_image: Bu fonksiyon verilen görüntüyü yok eder.

mlx_get_color_value: Bu fonksiyon, standart bir RGB renk parametresini görüntünün bits_per_pixel gereksinimine uyacak şekilde çevirir ve rengin X-Server tarafından anlaşılabilir olmasını sağlar.

mlx_xpm_to_imageve mlx_xpm_file_to_image: Bu işlevler yeni bir görüntü oluşturur ve belirtilen xpm_data veya dosya adını kullanarak doldurur. Şeffaflığı yönetirler ancak tüm xpm görüntü türlerini okuyamayabilirler.

Görüntüleri oluşturan üç fonksiyon, mlx_new_image, mlx_xpm_to_image, ve mlx_xpm_file_to_image, bir hata oluşursa NULL döndürür. Aksi takdirde, görüntü tanımlayıcısı olarak null olmayan bir işaretçi döndürürler.

MiniLibX'te Olay İşleme

Olay işleme, grafiksel yazılım geliştirmenin temel bir yönüdür. MiniLibX'te, tuş basışları, fare tıklamaları ve pencere gösterimleri gibi olayları kolayca işleyebilirsiniz. İşte MiniLibX tarafından olay işleme için sağlanan bazı işlevler:

mlx_loop: Bu fonksiyon, bir olayı bekleyen ve ardından o olayla ilişkili kullanıcı tanımlı bir fonksiyonu çağıran sonsuz bir döngü oluşturur. Bağlantı tanımlayıcısını gerektirir.

mlx_key_hook, mlx_mouse_hook, mlx_expose_hook: Bu işlevler, kullanıcı tanımlı işlevleri belirli olaylara atamanıza olanak tanır. Örneğin, bir tuşa basıldığında, bir fare düğmesine tıklandığında veya bir pencere açıldığında çağrılacak bir işlev atayabilirsiniz. Bu işlevler, pencere tanımlayıcısını, çağrılacak işleve bir işaretçiyi ve her çağrıldığında işleve geçirilecek bir parametreyi gerektirir.

mlx_loop_hook: Bu fonksiyon, hiçbir olay meydana gelmediğinde çağrılacak kullanıcı tanımlı bir fonksiyon atamanıza olanak tanır. Bağlantı tanımlayıcısı, çağrılacak fonksiyona bir işaretçi ve fonksiyona geçirilecek bir parametre gerektirir.

Bir olay gerçekleştiğinde, MiniLibX sabit parametrelerle karşılık gelen işlevi çağırır. Tuş ve fare olayları için, basılan tuşun tuş kodu, penceredeki fare tıklamasının koordinatları ve hangi fare düğmesine basıldığı gibi ek bilgiler geçirilir.

Ek olarak, MiniLibX, işlev aracılığıyla tüm X-Window olaylarına daha genel bir erişim sağlar mlx_hook. Bu işlev, olay ve maske değerlerini belirterek herhangi bir X-Window olayını işlemenize olanak tanır.

MiniLibX'te Pencere İşleme

mlx_new_window: Bu fonksiyon ekranda yeni bir pencere oluşturur. Bağlantı tanımlayıcısını, pencerenin boyutunu ve pencerenin başlığını gerektirir. Fonksiyon, diğer MiniLibX çağrıları için pencere tanımlayıcısı görevi gören bir boş işaretçi döndürür.

mlx_clear_window: Bu fonksiyon verilen pencereyi siyahla doldurarak temizler. Bağlantı tanımlayıcısı ve pencere tanımlayıcısına ihtiyaç duyar.

mlx_destroy_window: Bu fonksiyon verilen pencereyi yok eder. Aynı parametreleri gerektirir mlx_clear_window.

Bu mlx_new_windowfonksiyon birden fazla ayrı pencere oluşturmanıza olanak tanır. Yeni bir pencere oluşturmada başarısız olursa, NULL döndürür. Aksi takdirde, pencere tanımlayıcısı olarak null olmayan bir işaretçi döndürür.

mlx_clear_windowve fonksiyonları mlx_destroy_windowherhangi bir değer döndürmez.

MiniLibX'te İçerik Çizimi ve Görüntüleme

MiniLibX'te görsel olarak çekici grafikler oluşturmak için aşağıdaki işlevleri kullanabilirsiniz:

mlx_pixel_put: Bu fonksiyon, pencerede belirli koordinatlarda ve renkte bir piksel çizmenize olanak tanır. Köken (0,0), pencerenin sol üst köşesinde bulunur ve x ve y ekseni sırasıyla sağa ve aşağıyı gösterir. Bağlantı tanımlayıcısını, pencere tanımlayıcısını, koordinatları ve rengi parametre olarak sağlamanız gerekir.

mlx_string_put: Bu fonksiyon, pencerede belirtilen koordinatlarda ve renkte bir dize görüntülemenizi sağlar. Parametreler ile aynıdır mlx_pixel_put, ancak bir piksel çizmek yerine belirtilen dize görüntülenecektir.

Her iki fonksiyonun da yalnızca belirtilen pencere içinde çalıştığını ve içeriğin pencerenin dışında veya diğer pencerelerin önünde görüntülenemeyeceğini unutmamak önemlidir.

Renk parametresi, istenen rengi kodlayan bir tam sayıdır. Renk, üç temel rengin karıştırılmasıyla oluşturulur: kırmızı, yeşil ve mavi. Her renk değeri 0 ila 255 arasında değişir ve son renkteki o rengin yoğunluğunu temsil eder. İstenen rengi görüntülemek için, tam sayı içinde uygun değerleri ayarlamanız gerekir.

Bu fonksiyonlarla MiniLibX projenizde çeşitli grafikler ve metinler oluşturabilir ve görüntüleyebilirsiniz.

Teorik Arka Plan

Pikselleri uygun yerlerine yerleştirme : FDF projesinde, her noktanın x, y ve z (yükseklik) koordinatlarına sahip bir pikseli temsil ettiği bir nokta haritası sağlanır. Bu koordinatların, her pikselin nerede çizileceğini belirlemek için ekran koordinatlarına çevrilmesi gerekir.

Bu koordinatları birbirine bağlama : Bireysel noktaları çizdikten sonraki adım, bunları çizgilerle birbirine bağlayarak bir tel kafes modeli oluşturmaktır. Bu, her bir bitişik nokta çifti arasına bir çizgi çizmeyi içerir.

Çizgileri çizmek için bir algoritma seçmek : 2 boyutlu bir ızgarada çizgi çizmek için iki popüler algoritma DDA (Dijital Diferansiyel Analizör) ve Bresenham'ın çizgi algoritmasıdır. DDA algoritması, çizgi boyunca piksellerin tam konumlarını hesaplamak için kayan nokta aritmetiğini kullanır, bu da onu oldukça doğru ancak potansiyel olarak daha yavaş hale getirir. Öte yandan Bresenham'ın çizgi algoritması tam sayı aritmetiğini kullanır ve genellikle daha hızlıdır ancak belirli çizgiler için daha az doğru olabilir.

Projeksiyonlar : Projeksiyonlar, 3B nesneleri 2B uzayda temsil etmek için kullanılır. Üç tür projeksiyon vardır:

Paralel Projeksiyon : Paralel projeksiyonda, nesnenin her noktasından izleyiciye doğru çizgiler paraleldir. Bu projeksiyon türü nesnenin boyutunu ve şeklini korur ancak derinlik algısından yoksundur. Üç yaygın paralel projeksiyon türü vardır:

Önden (veya Ortografik) : Nesneye önden bakılır ve yalnızca ön yüzü görünür.
Yukarıdan Aşağıya (veya Plan) : Nesneye üstten bakılır ve yalnızca üst yüzü görünür.
Yan (veya Profil) : Nesneye yandan bakıldığında yalnızca yan yüzü görünür.
İzometrik Projeksiyon : İzometrik projeksiyon her eksen için aynı ölçeği kullanır ve perspektifsiz 3 boyutlu bir etki yaratır. Çizgiler 30 derecelik açılarla çizilir ve tüm tarafların net bir şekilde görülmesini sağlar.

İzometrik ve Paralel

Konik (veya Perspektif) Projeksiyon : Konik projeksiyon, her noktadan gelen çizgileri tek bir noktaya (izleyicinin gözü) yakınsayarak gerçekçi derinlik algısını simüle eder. Ancak, nesnenin boyutu ve şekli bozulabilir. İki tür perspektif projeksiyonu vardır:

Tek nokta perspektifi : Bu tür perspektif projeksiyonunun tek bir kaybolma noktası vardır. Genellikle izleyici doğrudan nesnenin bir tarafına baktığında kullanılır.

İki nokta perspektifi : Bu tür perspektif projeksiyonunun iki kaybolma noktası vardır. Genellikle izleyici bir nesnenin köşesine baktığında kullanılır.

Perspektif

Noktalar ve Vektörler : FDF projesinde, manzaradaki noktalar 3B uzayda vektörler olarak temsil edilir. Vektörler, projede sıklıkla kullanılan işlemler olan skalerlerle toplanabilir ve çarpılabilir.

Dönüşümler : Dönüşümler manzaradaki noktaları değiştirir. Üç temel dönüşüm çeviri, döndürme ve ölçeklemedir.

Çeviri : Çeviri, nesnenin yönünü veya boyutunu değiştirmeden hareket ettirilmesini içerir. Her noktanın x, y ve z koordinatlarına belirli bir miktar eklenerek elde edilir.

3D Çeviri

Dönme : Dönme, nesneyi orijin etrafında döndürmeyi içerir. Vektörler üzerinde bir matris işlemi olarak temsil edilebilir. Örneğin, bir noktayı orijin etrafında döndürmek için vektörünü bir dönme matrisiyle çarparsınız. Dönme matrisi, dönme açısı ve dönme ekseni tarafından belirlenir.

İlköğretim Rotasyonları

Ölçekleme : Ölçekleme, nesnenin şeklini veya yönünü değiştirmeden boyutunu değiştirmeyi içerir. Vektörler açısından bu, her noktanın x, y ve z koordinatlarını belirli bir faktörle çarpmak anlamına gelir.

Ölçekleme

Bu dönüşümler manzaradaki noktaları ve şekilleri manipüle etmede temeldir.

Matris İşlemleri : Matris çarpımı gibi matris işlemleri, noktalara dönüşümler uygulamak için kullanılır. Çarpımın sırası önemlidir, bu nedenle dönüşümlerin sırasını dikkate almak önemlidir.

Denklem Sistemleri : FDF projesinin çeşitli yönlerinde doğrusal denklem sistemlerini çözmek gereklidir; örneğin noktalar arasında interpolasyon yaparak doğrular çizmek gibi.

Özetle, vektörler, matrisler ve dönüşümler gibi doğrusal cebir kavramlarını anlamak, FDF projesinde noktaları ve şekilleri manipüle etmek için çok önemlidir.

FDF Projesi için Otomatik Test
run_fdf_tests.shSenaryo

Betik, run_fdf_tests.shFDF projesinin test sürecini otomatikleştirmek için değerli bir araçtır. FDF programını birden fazla harita dosyasıyla çalıştırma ve bellek sızıntılarını kontrol etme görevini basitleştirir.

Komut dosyası çalıştırıldığında, kullanıcıdan harita dosyalarının bulunduğu dizin yolunu girmesini ister. Eğer bir yol sağlanmazsa, varsayılan olarak bir ./mapsdizine gider.

Komut dosyası, üzerinde çalıştığı işletim sistemini akıllıca algılar ve bellek sızıntılarını kontrol etmek için uygun aracı kullanır. Linux'ta, kullanırken valgrindmacOS'ta (Darwin) leakskomutunu kullanır.

Belirtilen dizindeki her harita dosyası için, betik FDF programını çalıştırır, bellek sızıntısı kontrolleri gerçekleştirir ve sonuçları görüntüler. Ayrıca, şu anda hangi haritanın işlendiğini ve kaç haritanın kaldığını belirten bir ilerleme güncellemesi sağlar.

Lütfen bu betiği kullanmanın FDF programının performansını etkileyebileceğini unutmayın. Bu, FDF programının kendisindeki bir kusur değil, bellek sızıntısı kontrollerinin bir sonucudur. Bu kontroller, programın bellek kullanımını ayrıntılı olarak izlemeyi içerir ve bu da kaynak yoğun olabilir.

Kullanım

Scripti kullanmak için şu adımları izleyin:

run_fdf_tests.shKomut dosyasını FDF proje klasörüne kaydedin .
Bir terminal açın ve FDF proje klasörüne gidin.
Aşağıdaki komutu kullanarak betiği çalıştırın:
bash run_fdf_tests.sh
Değerlendirme Süreci
Düzeltme Sayfası









Gelişmiş Beceriler



Referanslar
MiniLibX Belgeleri
Fdf Açıklaması (42 Ecole Projesi)
Fil de Fer (Fdf) - 42 Yaşındaki İlk Grafik Proje
Doğrusal Cebir
3D Döndürmeler

Destek ve Katkılar
Bu deponun faydalı olduğunu düşünüyorsanız, lütfen desteğinizi göstermek için yıldızlamayı düşünün. Desteğiniz için teşekkürler!
