#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

typedef long long LL;

class Solution {
public:
    class KMPGenerate{
        private:
            int* failed;
            string source;
        public:
            void Init(string _source)
            {
                source = _source;
                int sz = source.length();
                failed = new int[sz];
            }

            bool findStr(string subStr)
            {
                int sz = subStr.length();
                failed[0] = -1;
                for(int i = 1, j = 0; i < sz; i++)
                {
                    while(subStr[i] != subStr[j] && j > 0) j = failed[j - 1] + 1;
                    if(subStr[i] == subStr[j]) failed[i] = j++;
                    else{
                        failed[i] = -1;
                    }
                }

                int cnt = 0;
                int subLength = subStr.length(); 
                int sourceLength = source.length();
                int i = 0, j = 0;
                while(j < sourceLength)
                {
                    while(subStr[i] != source[j] && i > 0) i = failed[i - 1] + 1;
                    if(subStr[i] == source[j])
                    {
                        i++; j++;
                    }
                    else{
                        j++;
                    }
                    if(i == subLength)
                    {
                        cnt++;
                        if(cnt >= 2)
                        {
                            return true;
                        }
                        i = max(failed[i - 1] + 1, 0);
                    }
                }
                return cnt >= 2;
            }
    };

    KMPGenerate kmpTool;
    string longestDupSubstring(string s) {
        kmpTool.Init(s);
        int sz = s.length();
        int l = 2; int r = sz - 1;
        string ans = "";
        while(l <= r)
        {
            int mid = (l + r) / 2;
            bool isOK = false;

            for(int i = 0; i + mid < sz - 1; i++)
            {
                string current = s.substr(i, mid);
                if(kmpTool.findStr(current)){
                    ans = current;
                    isOK = true;
                    break;
                }
            }

            if(isOK)
            {
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return ans;
    }

};

int main() {
    Solution s;
    cout << s.longestDupSubstring("iuiielmwbuhncfgvnsnwwcnzgbuylftyoopqrmkbycbubrvrfvwbufeooizjydgtpuxwpauqklqqlflzizazpevkcqysqyxhxpksvhnwdfaxqbpokvropwipxjfxcohnxvkyxybgzprkpsxmwuzdgfpaimcprhvmmqvijkfyrznhoucelkyoogemciorlzwigbvehltglnxirtedwhcxonzvbevluqpdcmmbxbdxdcfwdsnbcqbtuindgtwfnoadpchnzgkaeyjaonaehuyscbgnmuedyligijyeretyfubaazkrsexdbmxdhgquyvcuxyhfufejbwfcgurzireoprfceghntuvecrkfolanunkhigeqflufocnxjvfixgkjnbvoxwizvbelwhcdugmtohuobyrjesztnglsykfsxnikagckszybiuywwsdzomvaukufdcaeamdlblfixrflpqybajdnyrbasqegunwnpjejvpcsonfhqdzmhewdbqcdsjpcsvhmdprqujbsapfkzwwikfcdzhndnelhvnqilrtwbnzytsrmfpevqrupkdxliohtzbunzeyqskrvasycpzjrcwzywtqnoljzzkiarptcixcewpdqrcczchabvlnwtnrqxsvygrbpncfenkgojvomyrkqcxjzmxpsdofriwyljtwpibhfkvkkrnnfpbvceqrrustnplvogqyjmkjadalslxogdtuupzmdgkcjridzmpcldmgxrolnebxaodyshachjanskuwnsljumqrudjrjipequhqwxgpwhgnigdemdjsawvukqlamxxzqiavunzpkpuogpoegdhvxiedzvmhbxgqlhhwjlqexbojjnnhogktvedekmynvuzonqwwyntacpawlwtxsajrkzcivhnaukxzgugwdirrgwofasmdhduyaakqclvzltrdlwhimpvmwgeebvxfniupaxpkaqnlzpesurityfslpbdtffbqipbmkxfarpgteuwoaabyoqpkwmpvyarqzrbidzdcqkiwsgimtgllkjrgbzzmkogqsmpoglbqanilcqumpqotffhdymbjuftjwkljnyqpxzqffbncifmemtkxayaxzslfatiwnrtjdiyknzxecwrabvtoypcsaesmuvqgvkrykynxwzhyuurykveahbehtplvuzjxncegdfjpjlglfzwpipehksjswqiawipwdugltppqbujjopitgrtpslxpsfaanccsqtyuypztsplpfxxogycjpwmckdugknbcbbtjyqltlhtmtpdolptlrhaxnzchtlohcvgehkhlbewdcqswogzbjjzhlkheyamljyudwrfiqvfgekbtzyulwadkgdpflfxvpshcmlvrzzdgkdelodppwjyljmedrmhsfozmtciduaebpjaagykojwlrxrxqdsjvohrjzneqbfnsnkjxiguyuprrqzbaxpdrurgzhwmfylkmuxouasuztymcyzllvbcrxfjmwhcxdbgdzdzevftxabzwsisdwpvjauaqarkjwhjciqxckfmeqdhuvjljtrsieqkltqxgojmiqmnkxiedqowhnsrfwlcfdmwglidgcgvpjnfnqncusbfcdqhbrxqhslpxxynudulzfvvachayogeasyalhmwbknrkynwfhriqvhzykdsahlpfeoppkecxaxltkkygknvqrdpaikbzzlusnslcqxqojojytpagkfbiyezpbyfjgixqyzcqygcvwqokurblqyzqryfjdeeflqgworjltrfpkmtzafvuhdoqizyhqtzbpbvlziczhkqxcbdbxfiwsihytabcujqgyguxkaegmrnrasnolyqorspbmyanndarkhlxcpzxrznuqlligznfuivhmkmfdesyeuwelnoikbzhwnaltruclcchnximwibwtwjdnqofvlvplvkireoxorwqlcytwiiajbalhawevxwdefkvaezhfssbkytzrjwkurxvcxhhblgfcyhoubsnzlsvganxijgecztbklughbtulvwwkiizcjtadhmkbrdrqjcyfmmilriznqrmywjtzzzlsrgfhgoqldvdirohuqznwatmcoygzopqbcwgnsgdrygpichbxjzxsorzzkhuaexziyccrgavgicrazujbsgsloufonaydhligxlatxvcinnjkncsvngsadpghwxvzfgmanhvkvwhenvsedpqyqnqvutfydppubsjsgbqrbruhpsrrpcsmyndrcskkgibkvbvelljogfezszbgcjoppnqhzmuvnjvwtmkggmfiqwwbnnpylbqdxtmfsdwsogyvsqwvpczmcvahqqwtzykytirguxjcqsgrplqytzaojsuxycovdtfyxwimxbgvzzvmpitdxbhkegdocgapbrfrvjsormzjswoxdrbsurorqqrquhzorxmypygfvjdwbxndpzveqzoiflewwhmygwifmbpgfvkfmaiodfwjmgejlwgytdjhczbcivwsppuqenunwyyxtcrhxonwywpgpqcujzlflplxbocbpmoivakwsevzxggatdzqeztxrkkyjaugjexinqedxtkwykgbnyumjkrosrllqrryhanlwegnfordfexagdbafjstqlzoluqaxquhduyqwmeeimmgdraosatsjgrwygcrqtweieafsubczzxhixrrcxmiwkqjjtgzhblszwiwqjnxoprxsycqvwckaczjfxbrgaoxfujnqqpwehgtucczrdqctaibmccokvxdyqpxmfnnlbzwkmpgfjhcusqnkipkodkpoobbgrsokfjsyqtcknepyevfsdtdidrjztugtlcqzjgupttcktbslevosvbgxmxrbsvkuchcgxpdthtmuippirutisdiwiomubzdqosqdsnnszgatbnhovpizmbbjgxvgbxiryresmfcbswsgcacimyzjpwmxsdigibckikxeuixbbzvnwljhpxzwrcettnzfdsosvfrkcaxghlqgbsnlucvyfkbpmuniqdypguiaqswxrrzfhoeogjpwzztseqmoaksqgdtgcswoqbcrvwztprnsodzlrywzlgcsgwxeloiyvsstrhityqeukvocgoytrjbrusiovgxqdshesupvpecziigkuyjuwqpagfovhaeurvdegwtkphppinfacgngghiqflknmvfdycwqbqxerhguqnwzjxsfbwwqbjinqvgsmbgldgqwkokzqlwdyzhtdqccwtydtpqewkatinmpdolyosdacsmpujeyfwrhvqihorbgasfzpujvcsymigqlqynuotsomrlwxywaspgqzkbfckyipzxjrjrbkqluwefgjjkpkrurwypmsvxmyqnyqonplfwnjgynrkjodvmazdjyiqiwetdzjyaybpgjlddkncljpqgtpkgoavbbwbbbndobbcbaktvwrxbxulmknlzwgdocnngwmkezhdcnbkyjgtbubvtbntwqourytmldlxmbxxrndximtddesbguqyzdwykifnsbchkxwlsewcisrcseipfjohzrvjxqdqbkafzahqiwjbzpbwdayygweaoovabtiqinibadluqvgzxkuiqgulcdemfgltvaqbwtuyoqxwqdurhydunyqniitegfcrknwvubclfmhqyvtnwmuoypwzchjopoguwythwrmbtymcnxqvyojlirkvlzmebmscjuwgqhkfqnwcxhrnhprfaamqiwrplvdmxdfqfiysqpwctuqmggopuzqbxartbjlutpycbgsfrtljhwftutnaawqruozfxuqjqomschcagdxxpgwejrotntqlgvsrmsurxigmxpiuretciynfcbejaqtpyjlbgilvepqndybefvhcdiujubrwhikmodthnbxixlunuwqgribmodtyxouhyafdlqeskmeuoyhakttlvpyqxzydrhwgrtflsvmvsvtidugaaybvuerlrgbxjkshxtiplxsyhcnncrchkeumqjhusubuwaketwqpmowjvfwuuzrrpgekxmhkglmniocmziucaqvirppcjucqedfnjfyaemvxzwuzzyeziwbvalguyezjilqekqbqhkgbgjaoilrfstvlvmoeenlicatngpvrtuuywqpeemnnvgtevkxznicfjwdbgclxaenbchgqnvomhkaafbikujrbnjqfzvgopcnlujejmcmdvbtxrlrkyqtayhgkdyrieyuymnofwvzycidrhduqlmbpuaztkmkqxlttvibhjwdgoaljxlxcjiitkjyemveqhyjvgfnprceuijcfxrctjjtijwzwxbxmdsskocxtdyvqsfjdlafcgpbwijdirvsujfezbfewtwafmnrdvqegivxmyhcttkbwjffqphjcoackbprrcbxevwqwipqcqzdjuwpbrxymzibmuriqabwtsisijildsuvmsdlteywhysfavlpyptjhccnkiugzzxurqcepuvhddjdnpbidexqfbzkskmxqfcfxzdqhxywegnlevxgzkfwyyebkypfamodeshsispcbegwbjjbalcdpuviysvppknfhawynczychthbojmyjiihputdlnrnwgsgiejddxfpnayfajtugctqnkfrjarbkzrqrvtlsgnqqmvwtpluzwtthkiomnnfdjvuqajkarcvkpwtvzjariilatklnshsqdhtiejulcvgrtxqodsgoimpcyypsnxppjhkxrnstowomqqgmosisopgwnjaypvmtuibypfuduvnjqxamllbadgejvqroazkpbqzvkrcsmjnmkkftcarhqaqfzuaqwlixhemwglmejukgthqjocckbrbmhqucrenfqoekrroekxafvlzutdsscvcbitjuztwkblfyaxirptulfvrmmthijxwlzuytxoupzvvmkvdvntiawdfhattosqhasuikocyqywjohfqgvbsajuqfwwzxywkxsntrggwxffzlxzhlvhyjiuvhxplnrqlpqudoleljxcntsjsngmyehrwwruvwexkyqbbhlvwdojprakqahdunowuyaoqmnrzabxqbkfwlzdfxaebsufrogtoldnryibgggigtfmfyjdynxwmwirrnufbwpkgdqhohuhozzikjyngireqnypatlqscdreveyzrpwolcpzmxopwqpfejtutfeqaczjtzguqvznkwtsztgfimbazhixrvtyowlvhokmfgxlrfihxaucezqlkupcccdyysydzwoftbkxelotvlnquwqwkoxxiauntglfuocepewopxdeadkcghdscqmejdwgijdcejervtsiwndjqjhccotkbatjgxyxfkzbyyuqtjvfqjmevhjmxomaxwiapcwzatorslgagjtykmwegrbboritytawndfrymzjmqawlwytseugxhyyijxofallvshguvdxuzaqmzzoqrwodkkrsdhwhkgemsktxsrokcablkybfqbllulxqpkkwswmrxnznmtknfdqarvgvltojfismrvfcowmtrkdcqilucjslnxdwyzayoxejmhjeonzwdqpjjovumpkibgcmotazussvaofxnuladaghokxjntfqsdybvbwcyhusfdwbpivpvuxxfwbcdyvejkfzvnbbrohbswnhcwfhhylnsnayzglbirrdjksrxyeyftxmuhagnufhzyhaniersbdtjdsrlbzpkoyeehsgmerfqgnltzvywoeldjidhjsakcnjbvgwdaocxxvgyjjkigkrnpvwkzynbpziatncmmlharpqwqekvokamjiuptfirqhijulebypdwriwlwdjilenpvjpusftctulbqgduqhfbmgvylsmzmpczxlbdqkhdeeexiyxpdfpzynltvnptyfgyapooqcbgluqvgdopoyrhhbdmogybhljnfhcrehetpszeaohtbvdamtloaxrpgopxyennxavrsabnxdxstjyhcdvzhfgozitgiennalbgrefilibegrfqedmniyhhvttczrkgmuwiasqykoazxpxmczniyjnopyqtvvrquztexhmqztarekcunryrvptokmaftaksdqeejtdwnyplgbmencrcygdmenxxzdstwcbccxatpijavxxnxyflpnneeagysquecbjrvyoogborlxrybpydsvkffseqyeevcxontmqkmlpgqsymwpquizbawjpqpowyomficyahanqdazfvnaczfcfgoedtttdfaazknxycqynstwixfsdushmxmtjqwcuktjmcnyzsncpblmcnbnhjbxonazdpsrvyjcuxymenbsjpacgveuwsmikyieyoavdyejrwygyuhrvjwuydvfcjxxrvuwkncpfqucitxnlpzzxdudlxdgezetdsealhrmllajnznfnlanobgjxoxsdwfcslpeqmvjnxgecvynvkwiofzmfnqkthbxlfawyughefssnzcoaiwinrbqmztkgkcuzvsmxsvudsvdsfknyzhdastxikmhfrvfumteremzkfevrfdvjsebmyzivtexdhsjrrmwjeevktcmlbtsweygbnydwrvzoynzlcfbbhqacqqakubzgwstxenfiggdwsrnkkvfnbayeuzwulzdhmrgpxktnvleqvsdakkncojammomwgjnkoalrzzaijnpsonjeipgxxcglvosgasyifkoymqvhlzsqrhonohhsqxjaqswocmmzlftxebazvojjaijthbavdcutwekqboqvufpjdmcbphvjovexrdyzwefwzzlazqhbubmjlduzfvytpdxkkxhycynysxzomqsomfcaxaxtqbnabwbycgdeqwtmclkzuyyuzqhpjhwismgutwmrvlsbtmirbjivcyjmchlvyflxvdjdjjuevofvxchvqcnifakvnmvpqdzusxklvzfwihejnhxqofbmoisblanxdftqerkxcrgfanwsqnnhpjqwhequlvjesmymayqwomhajjpzktfbbqdvrnfzherypszsmxyixkfihwfpjfsljaifzzyfsoxpikgewuinlwrvgohgfqxxryrxfvxkhgtcpqcbgeymlfydkudegopfgnpjkrzsbloevpdyxbmhtbunpiiwfjpyoqojlepyqaajqjbhnqlsnvcwdryulrhijiwmlimbsafhcucyhzhgipiahnzkwiysutzxqkxepddfckgmrdiogjsftnvpzuhhatpckrodafgvkvkcqzaozbqkdsfzzpdxfbqtcjgejxftphontqnsoeeiezewjdfzuuozavgkspsozmrvkhebfunmdlecdojzczqyyyzcyztdvykmoxveqexkrxzrnqeyjmuaxaapsosqczbzybwnqetmmybnzlnsmygyxbupbolxbudxvazsdtkrbbuvylxwiyqviwtafgbfefkjdrocnfxwhhntmfrrexetmkadfduahzqdnpujcxfrokgvhjthjnbwbherwawknaxvmfrflraapevvmqodvgbsihtucirswpheqjxzpfldjioezonporgokkgiaszhcudfeecvrddieorjmufxftcztnxafnlxkmvctyetbplblybieolafdnztmrhcgzmkeqpfmbjbuobtjaodjpdvaeomoknrappaibtrqezxamrifufzowfkwdjepalxujaogrfgxnxsskkxfnhtfvgwdrrimsumxzcqqftsqywpjhqhudnxsxynuxqgzcwpcltluzymkbefbsvrzjwrnljaceisidppyhjqaydxaslioetbjtanggbhqkdnhzsgzqbtspkmteoymvxsnpdsaxsgmkgzidqcwcesmhjpkvppzmsdgjcremrvbmkllchrlrylcjrvclszbmjihppjckszfobbcqqpxgtcphndampzwcyubpuapgitlivdhcmkoeuyecrbpiofqnrodlaxwuyendreinfkhvnadnkiqhzpdbisymulfhgoyvzvvafxzonnlplkiywodfflqccmlldipxztimfzpvczqrmggfjguayqqvuwcerpffijttmggfkgnnhbweosrzenmkmhvzizrxrwhkwarquiqcjcbcpiyhyvddfvqpsxyoipaufjfxosuslehiwisberbuabcufajdhyheaghjznvbphmegnnikmtpxgxlbkxstvrdyvmuysnnmgrjbdiixknockznluhczbgsqwtsxfmcfbohncdwwhnfkiadefzffsbqaihgukavwdhebcwzuvqcsdwaubwwpddlioysxrlcdpzvwhfpnncuesxxftujqykgtuvejgnqnnrgusurlltpcjncxggbcpmwonoeloemjugangzxhzafkckiwjixvtbvkqeuxcouzlhqepencswgdljewlzrmmlktatczgknvpjdtjrdyvrsorkrgwvxgeshncmwjcmbqsbckkedxnxcxeoqnufgdbiltqklmepsbvdxqyxosrxgyghohoherenqqkcdpshcgnvdsiaqgbxoiwbnstulorlkqtoyofbdiwqqyovaxlxwqoxaukjbdwpcvgooibvkojcgkmopqugackzatnfmfcdaksnnzcabghdjlpqgslkrinljntnyuxesiiasvfvpnsagrtfkhxizebjffnynslylxqhrvcgrbhpplbadttmqdymdurzieqekizqkzhmsilrtnbeotnwwyltbkiahdderkiedspilycjvjfdmggvfvswcddpqtdaozpwfycsefpqicbusqdhucbndyttaypybxwdepqcgpfnvljkbocqnvsewciqewxxpbwbhawputrnkkqtpbcdytidiebeykrppuzrhycmhgzhknfjdzkpfhoxrswedhnvnyxdtxedukjirboigwexslnbtisyfbiurqkiitlclrbjleborreizutjsnsjvcpcyhuginhnnhanxjsdnjbmtwbesuecdhdemtjskvitfqmhhgtflehrafopgpakeswseinhgfpgaavosthlbffwgmkguoyyrjeyhtkgsegrbmubhfimernxhlhcdoqdmyhuxzkkyjruehkqocfqzobczljhcucvbzbivyaihegmabccfbkmkaoezugliicoiyrfsqdzhhwhxynpjxjsnkbpvytyejoctzqfjafwpfnprtnhkwknnrikpylswgszrgeffvroervyofynycbzgrgcdpanrfeyqbxgngzkbhdagzfhnpnvluakfdhfcvogyuraankndrbruhkzhmxzbhmvhmtakmsoozuawedlmjhhuvbmeyhdnhtacddcgsfuadhboinhzwmknyyvajtrzhwfwqlvehnjxckdjsybwhsoatyjklznwxwslmhzrdaxowfghfiolupjbmkdimdxwjobbrnuyendnsbahjtkbxgddzlkkdaflakikvcwivzhmrgpfckymwtnwlzrlnthfliwpdcpwtloajgyjpdgleudwpnouiojbepkmgvgkelhzcyutnsapuqkamwkpiextoytjiwtpkbdkqgltwsfaunkzogrbckhxiabwrvpmwrpoyuwgalbkgxifluysrduuzqbtemnmfcegploawzsibbqnyjwlflsdwwrnlszgmypbnhrqxcyiwlkkqfvqumeywjssnhgetejzukgztzrmvfajyraawogpozyuarxhcurnzxdsbnyckplrkkxwwcjipbwfqbwtapyhlwlowxdebbkpimustujkxyqhgxzuiaddubuxyvosfkplgimcpkosyyabyzyuyjxzohhctwelxtemvfsvgdmyktvvxzhftjvxhwcayhudrsgjmbhbxnecydibyeegpjzgicteyylbzjknqhohbmjqziupajbtiiugytyxduzimyspucowurhjujqxodbboknjnynmosftdtaxqfyteimcelkbryjnzmznpnshcegempkyyldtzlnpwbcypnphlnwtxmvlhbnjxmbbockwghzszbpgmhsiebxtwmndnyiaoqzdhgfzuakykqmxmksiqtqusbsbpntnwevrckjarabrhncjrqytncwvfxdfmntuoabminszlpjotflublgqmsubxbskevjzsdamfmlmzoscrmqnufjermnvlzlkbbipehuenispznvzpilcjrtflretqtrgwgtsdadbyfidxowihvdvqiidhzzmmqmzgjiedflvgtlscaumeskqjaoczhaopsndkcpleygaxbmglxxyhphrbypbroaxntjzuovpmtahmuxnynafjizuknpjwwtdrvqbmqlvpaxgtvjjpbxygwhawcokxqlderwdrtgvtnhkbvpzhjiqoccvrtwwwfbxsdttudydynaupqujupxtiaxpvgfremzrbzdbcxqjchkmpzpzrqomrfnhslboovebwqyqdmqppvxdkzppzcrypsxwdftquwwbkokyjserfjcprcrjdvcscgmauarjajrkrerszolcwxlkufnuuwbgbmhyzqsnhbkrpqdxirveddvphjaaxrcpfepexwoxwuxkjczkcfqfqyghregbciujqtqoiwyjfggmngsohbzgpcpwsfubvibqzblriuyddykexycnkmbmfzubbdyaqvgclvgngrlodpeayjuiwcfvfggnrifgzbfuywuhdlqiluddrxdmrsuojrulcttiwshoekpgyqxijiwlyjjsypqllcgizpxkhyghkogksxauylbntfdfgotoncafqwxsjyblhdujzmtbtqlkzrxpjpqsglguydkoghjwroocjjesulunomntrltllpeiqtnsghcbnfdvcwfrzvlmxanktjezkzksewpvbaikyvaakygdnrxgsfjnwzkodpabijhxugtgololojikptabzdbbqolexhlgljicwpvvbhaegjacahfldtfgsfizlyyvydzmjskemupxolalwnmygzrtzcprngffhndlocuksjebdbbtlphwpljhpiwjxdjptsljvjvnleigmkotssxspuzlgmqvdkwazpzbolpkushgrwhjovhmkuxqzmdtcbbhtomjyqbwugodehtoofayipuvxzvtfwitxmyfisuydmtxxpadqwxuvgetkyjccrcqmomkqhmljtnxpsizoblkkzgscxeudbdftmmhysgkngorlrxvrjbpyaubslahfmjjopzitkwtennnvkmfbvkvzcfhdbhvwmwkxmhgdbevqdudgqjczffulfnqqvakqqycjvrdqzvzpzerahrhkbzkitbzdmzruspqrtbzpatyoadrblojebbbrdsxgtedjqtiizijvjhjgfqqqltbornlvdkhslkujnoxgsfzwatwmeyslbmvayyhexjqihfpwjywfudkqxnusvyzlngenlgvtfldfzqsnqtrnoxzmlrmmzhiejvtzyyvefspdvbefdvxczuroqrphvdggavvvymkzhceauvlughgofjrcknkwcolosyjoxljvzjrhtaamblyslwrpzzwnwbuolpbewokwmarfnrwshmeyeeyqmuvnwyhhmwagigwttijiphcusidtefsroouppraododegmnuxxkgpzhikktosefauwmkllaloltkfbndfycmzmhvayxpbhpqiuillubqkkfxrkfhuqqhijfkxvwsztpvlbhrgzwpfjnceqlvrddjyfjjicfobupseddhpqerjugaluujzmclrnjmyfveujgprzhykwtllvovrphlxfywtkvvaixwostikokmydrbvmjpzqaybwbgvmlfdzpzuczccsbdooflhpjksrhqbdclmquraewubcpyswzfwwtelaweqttmmiasfkebfdlttjpulvcvekzwgntroogeaxeskdplmebafuagqjbmpxbrikmsrjamwkdhufpohctgsqytayrvhwtcpewjbodxcxpwkrqoemvmtwxrksxbimxwquwhhofciohgqtxxuqkcojaugnyhuzkttkjhsvupifkvhownbfrxcqlfeioglfihprxnmvpekepjigzwfhdsexhpjuafrbldmxlcrjssvjzpzmaclxvdwvneplkkvbxpqndqgbtvacgqnxzavxssjmjunwseilskdfnvtzmljplmjemgecumxttmfaswqclptipxbaljmfwjvoymsmwgzewadhycyycppseourdsfalacwbatfhgfceesctmekvtpdkqqgswijasdzfzwbjxzjtskvhlvbyimfzqukqrkzjyrnsaryeytttcnslkgsrtycibxdzgtorgajqfwibriticzfywlljfxyyufoffsdmaufgrfrawtdqserkjjemdgbvldyaothljxkeyutocfbdyfochjoxldlzyoefyskvcyvyuywqeskimbtitmovswieboyimigtcbuqgwasuvpxakweolyjfxqzxqntmlxypqesinhbspaekwdncciydxkbtvkqczdaxsvdnbkznwhirflizzbkekeemoghlizqhabxaifksirajlgryjkmqetumgbvvgarothabinftqkywrhdelgabkxopbjurwqtsoamapqpfeslprcxbmpszglupdlwwjofvxjvrrrsfqwjvztymtejxgdfg") << endl;
    return 0;
}