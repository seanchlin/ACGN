#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

struct Question {
    string questionText;
    string options[4];
    char correctAnswer;
};

void playQuiz(const vector<Question>& questions) {
    srand(time(0));
    int score = 0;
    char optionLabels[] = {'A', 'B', 'C', 'D'};

    int numQuestions = min(30, (int)questions.size());
    vector<int> selectedIndexes;

    while (selectedIndexes.size() < numQuestions) {
        int randIndex = rand() % questions.size();
        if (find(selectedIndexes.begin(), selectedIndexes.end(), randIndex) == selectedIndexes.end()) {
            selectedIndexes.push_back(randIndex);
        }
    }

    for (int i = 0; i < numQuestions; ++i) {
        int idx = selectedIndexes[i];
        cout << "題目 " << (i + 1) << ": " << questions[idx].questionText << endl;
        for (int j = 0; j < 4; ++j) {
            cout << optionLabels[j] << ". " << questions[idx].options[j] << endl;
        }

        char userAnswer;
        cout << "請輸入答案 (A-D): ";
        cin >> userAnswer;
        userAnswer = toupper(userAnswer);

        if (userAnswer < 'A' || userAnswer > 'D') {
            cout << "無效輸入，請輸入 A, B, C 或 D" << endl;
            continue;
        }

        if (userAnswer == questions[idx].correctAnswer) {
            cout << "答對了！" << endl;
            score++;
        } else {
            cout << "答錯了！正確答案是 " << questions[idx].correctAnswer << endl;
        }
        cout << endl;
    }

    cout << "測驗結束！您的總分為：" << score << "/" << numQuestions << endl;
}

int main() {
	
    vector<Question> questions;
    questions.push_back({"《鳴潮》這款遊戲為哪一家公司發行？", {"米哈遊", "任天堂", "庫洛遊戲", "台積電"}, 'C'});
    questions.push_back({"《不時輕聲地以俄語遮羞的鄰座艾莉同學》這部動畫為哪一家公司製作？", {"MADHOUSE", "動畫工房", "吉卜力工作室", "project No.9"}, 'B'});
    questions.push_back({"《排球少年！!》於2024年出了一部劇場版動畫，請問此部電影副標題為何？", {"垃圾場的決戰", "排球場的決戰", "last game", "這是你與我的最後戰場"}, 'A'});
    questions.push_back({"日本Vtuber公司hololive旗下的Vtuber團體ReGLOSS於今年八月達成了全員Youtube訂閱總數到達多少的目標？", {"150萬", "200萬", "250萬", "666萬"}, 'C'});
    questions.push_back({"作為 hololive 成員活躍的日本知名Vtuber，在今年8/6於個人直播中宣布將於8/28日畢業，請問為下面哪一位?", {"桐生可可", "湊阿庫婭", "白上吹雪", "阿神"}, 'B'});
    questions.push_back({"動畫《名偵探柯南》系列電影裡，服部平次的青梅竹馬為誰？", {"遠山和葉", "結城明日奈", "周防有希", "工藤新一"}, 'A'});
    questions.push_back({"在ACG界裡，一部動畫(或漫畫、小說）未完結卻沒有再繼續連載，這種狀況我們一般稱之為什麼？", {"背斬", "水面斬", "星爆氣流斬", "腰斬"}, 'D'});
    questions.push_back({"動畫界傳說中的「三級定律」最有名的橋段是出自哪一部動畫？", {"魔法少女小圓", "鬼滅之刃", "多拉A夢", "在異世界獲得超強能力的我，在現實世界照樣無敵"}, 'A'});
    questions.push_back({"知名動畫《多拉A夢》中，主人公大雄喜歡的對象為誰？", {"靜香", "胖虎", "小夫", "出木杉"}, 'A'});
    questions.push_back({"遊戲《第五人格》的背景故事開始時間為下列何者?", {"17世紀巴洛克時期", "17世紀啟蒙時代", "18世紀維多利亞時代", "19世紀不列顛治世時期"}, 'C'});
    questions.push_back({"下列哪一位台灣Vtuber 的外號被叫做哈士奇？", {"瑪格麗特.諾爾斯", "露恰露恰", "森森鈴蘭", "厄倫蒂兒"}, 'C'});
    questions.push_back({"動畫《名偵探柯南》系列電影裡，工藤新一的青梅竹馬暱稱叫什麼？", {"小蘭", "小律", "小虹", "小光"}, 'A'});
    questions.push_back({"在大逃殺類型的FPS遊戲裡（如pubg、apex)，存活到全場只剩自己一隊，這個狀態我們可以怎麼稱呼？", {"吃鴨", "吃雞", "吃貨", "吃王"}, 'B'});
    questions.push_back({"下列哪一位hololive Vtuber 的外號被叫做人中之龍？", {"桐生可可", "時乃空", "白銀諾艾爾", "華生.艾米莉亞"}, 'A'});
    questions.push_back({"在日本動畫史上曾出現過一名知名導演，他出過的作品包含天空之城、風之谷等等，為下列哪一位？", {"柯南道爾", "陳澄波", "久石讓", "宮崎駿"}, 'D'});
	questions.push_back({"請問被諸多粉絲稱為「原作粉粹機」，且曾在公開訪談表示自己從不看原作的監督是以下哪一位？", {"赤城博昭", "元永慶太郎", "吉原達矢", "岡本學"}, 'B'});
	questions.push_back({"輕改作品若是由這間動畫公司操刀，高機率會讓原作粉絲哀嚎遍野，曾經製作《關於我在無意間被隔壁的天使變成廢柴這件事》的動畫公司是哪一家？", {"Project No.9", "A-1 Pictures", "WHITE FOX", "P.A.Works"}, 'A'});
	questions.push_back({"請問『44.5』是下列哪一個Vtuber的梗(包含已畢業)?", {"音乃瀨奏(Otonose Kanade)", "桐生可可(Kiryu Coco)", "火威青(Hiodoshi Ao)", "湊阿庫婭(Minato Aqua)"}, 'D'});
	questions.push_back({"《鹿乃子乃子虎視眈眈》的鹿乃子乃子的角沒展現過何種功用？", {"泡咖啡", "爆破", "儲存糧食", "入菜"}, 'D'});
	questions.push_back({"靠著柯南跳舞而紅的迷因「明知有舞，為何不避？」請問下列何者是正確歌詞？", {"停滯天空之間，像淚在眼眶盤旋", "雨停滯天空之間，淚在眼眶盤旋", "雨停滯天空之間，像淚在眼眶盤旋", "停滯天空之間，淚在眼眶打轉"}, 'C'});
	questions.push_back({"Hololive的Vtuber們常常會有晚上喝酒回，請問誰喝醉酒後會喵喵叫?", {"雪花菈米(Yukihana Lamy)", "白上吹雪(Shirakami Fubuki)", "貓又小粥(Nekomata Okayu)", "亞綺 ‧ 羅森塔爾(Aki Rosenthal)"}, 'B'});
	questions.push_back({"《火影忍者》中，原寫輪眼能力的對應人物哪個正確？", {"旗木卡卡西-神威", "宇智波鼬-伊邪那岐", "宇智波止水-別天神", "宇智波佐助-伊邪那美"}, 'C'});
	questions.push_back({"《球少年》中，日排向翔陽對牛島若利下馬威時說了那一句台詞？", {"我是出生在混凝土的日向翔陽", "我是出生在垃圾場的日向翔陽", "我是出生在宮城縣的日向翔陽", "我是出生在雜草堆的日向翔陽"}, 'A'});
	questions.push_back({"漫畫《咒術迴戰》中，連續黑閃次數最高紀錄保持者是誰？", {"七海健人", "五條悟", "虎杖悠仁", "兩面宿儺"}, 'C'});
	questions.push_back({"《名偵探柯南》中，俗稱酒廠的黑暗組織中的間諜數量層出不窮，下列哪位不是叛徒？", {"庫拉索", "蘇格蘭威士忌", "黑麥威士忌", "波本"}, 'A'});
	questions.push_back({"《原神》中，下列何者角色不是五星角色？", {"珊瑚宮星海", "神里綾華", "班尼特", "賽諾"}, 'C'});
	questions.push_back({"下列何者遊戲不是出自日本的公司？", {"原神", "世界計畫", "貓咪大戰爭", "勇者鬥惡龍"}, 'A'});
	questions.push_back({"「當你凝視著深淵，深淵也在凝視著你。」這句話在哪一部作品中曾出現過？", {"刀劍神域", "關於我轉生變成史萊姆這檔事", "為美好的世界獻上祝福！", "OVERLORD"}, 'C'});
	questions.push_back({"下列何者不是FPS(第一人稱射擊)遊戲？", {"Apex Legends", "Valorant", "PUBG MOBILE", "傳說對決"}, 'D'});
	questions.push_back({"下列哪位Vtuber不是屬於hololive?", {"時雨羽衣", "星街彗星", "紫?詩音", "櫻巫女"}, 'A'});
	questions.push_back({"下列哪一個日本聲優因為配音多部主角開後宮的動畫而有「後宮王」的稱號但卻有恐女症？", {"松岡禎丞", "花江夏樹", "日野聰", "?裕貴"}, 'A'});
	questions.push_back({"下列哪一個人不是hololive Vtuber團體「StarEnd」的成員？", {"星街彗星(Hoshimachi Suisei)", "湊阿庫婭(Minato Aqua)", "常闇永遠(Tokoyami Towa)", "紫?詩音(Murasaki Shion)"}, 'D'});
	questions.push_back({"下列哪一位Vtuber沒有被觀眾和實況主 Kamito做過配對？", {"橘雛乃", "英麗薩", "貓汰月奈", "星川沙拉"}, 'D'});
	questions.push_back({"下列哪一個遊戲沒有職業賽?？", {"傳說對決", "特戰英豪", "第五人格", "俄羅斯方塊"}, 'B'});
	questions.push_back({"請問下列哪部作品，可以說是開啟了輕改動畫的代表作?", {"命運石之門", "Re：從零開始的異世界生活", "涼宮春日的憂鬱", "平凡職業造就世界最強"}, 'C'});
	questions.push_back({"下列哪部作品，沒有被真人電影化過?", {"名偵探柯南", "鋼之煉金術師", "刀劍神域", "輝夜姬也想談戀愛"}, 'C'});
	questions.push_back({"下列哪個作品，與湯淺政明無關?", {"獸爪", "海馬", "蠟筆小新", "海獸之子"}, 'D'});
	questions.push_back({"下列何者作品，沒有被歸類為OVA?", {"FLCL", "若葉少女", "飛越巔峰", "伊里野的天空、UFO的夏天"}, 'B'});
	questions.push_back({"以下何者Vtuber並未舉辦過個人演唱會?", {"湊阿庫婭(Minato Aqua)", "星街彗星(Hoshimachi Suisei)", "時乃空(Tokino Sora)", "AZKi"}, 'B'});
	questions.push_back({"Vtuber戌神沁音(Inugami Korone)在一次恐怖遊戲中遇到蟑螂並用臉盆蓋住，請問後來蟑螂的下落?", {"被狗狗奶奶殺了", "消失了", "狗狗拿報紙殺了", "Call小粥來殺"}, 'D'});
	questions.push_back({"請問以下哪一種不是遊戲《魔物獵人 X》內的狩獵風格？", {"公會 Style", "武士道 Style", "飛空 Style", "江南 Style"}, 'D'});
	questions.push_back({"忍者哈特利最怕什麼動物?", {"青蛙", "蜘蛛", "瓢蟲", "獨角仙"}, 'A'});
	questions.push_back({"下列何者不是遊戲《聖火降魔錄風花雪月》裡修伯特的強項?", {"弓術", "理學", "指揮", "劍術"}, 'D'});
	questions.push_back({"動畫《我們真的學不來！》，武元潤香為一之瀨學園3年幾班的學生?", {"A班", "B班", "C班", "D班"}, 'D'});
	questions.push_back({"漫畫《金田一少年之事件簿》『雪影村殺人事件』中，冬美的內褲顏色是?", {"綠色", "粉紅色", "黑色", "黃色"}, 'B'});
	questions.push_back({"動畫《名偵探柯南》第703話『漆黑的特快列車(交差)』中，燒傷臉男子的真實身份?", {"苦艾酒", "琴酒", "伏特加", "波本"}, 'A'});
	questions.push_back({"小說《問題兒童都來自異世界?》中，下列人物何者沒有『模擬創星圖』?", {"逆迴十六夜", "久遠飛鳥", "黑兔", "白雪姬"}, 'D'});
	questions.push_back({"請問下列Vtuber誰沒養貓?", {"貓又小粥", "百鬼綾目", "蘿蔔子", "不知火芙蕾雅"}, 'D'});
	questions.push_back({"以下何者Vtuber沒有主持電台?", {"星街彗星", "AZKi", "夏色祭", "寶鐘瑪琳"}, 'C'});
	questions.push_back({"在動畫《銀魂》『性轉換篇』中，下列哪一位角色性別沒有對調?", {"志村妙", "?田銀子", "志村新八", "神樂惇"}, 'A'});
	questions.push_back({"請問在西元2005年發行的遊戲《惡靈古堡4》中，主角的名字是?", {"艾西莉", "里昂", "路易斯", "比雷斯"}, 'B'});
	questions.push_back({"動畫《路人超能100》第2話中，影山茂夫最後說要加入哪個社團?", {"動漫畫社", "突破極限社", "肉體改造社", "文藝社"}, 'C'});
	questions.push_back({"在任天堂《勇者鬥惡龍XI》中，『葛雷格』出生於?", {"薩馬丁王國", "邦德爾馮王國", "海底王國穆雷亞", "聖地拉姆達"}, 'B'});
	questions.push_back({"動畫《笨蛋,測驗,召喚獸》中，康太發現犯人身上的特徵是?", {"眉毛上方有痣", "每天變髮型", "屁股上有燒傷", "不穿橘色衣服"}, 'C'});
	questions.push_back({"以下手遊何者並非由COLOPL開發?", {"貓咪大戰爭", "祕寶偵探", "問答RPG魔法使與黑貓維茲", "機戰少女Alice"}, 'A'});
	questions.push_back({"請問hololive Vtuber Mori Calliope(死神)曾經由於想要玩哪款遊戲卻沒有授權而開了直播不斷地喊拜託讓我玩?", {"女神異聞錄3", "女神異聞錄4", "女神異聞錄5", "女神異聞錄Q"}, 'A'});
	questions.push_back({"作品《進擊的巨人》中，瑪利亞之牆與席納之牆的最近直線距離為何?", {"175km", "230km", "270km", "330km"}, 'B'});
	questions.push_back({"在遊戲《英雄聯盟》中，李星施放(Q)虎嘯龍吟需要多少能量?", {"30", "40", "50", "60"}, 'C'});
	questions.push_back({"動畫《寄生獸》中，田村玲子死於第幾話?", {"15", "16", "17", "18"}, 'D'});
	questions.push_back({"遊戲《超級瑪利歐銀河》中掉進黑洞時會出現什麼英文？", {"TOO BAD!", "OH NO~", "YOU LOSE", "不會出現文字"}, 'A'});
	questions.push_back({"卡通《真珠美人魚》中總共有幾個美人魚公主?", {"8", "9", "10", "11"}, 'A'});
	questions.push_back({"蠟筆小新中『小新的妹妹』叫什麼名字?", {"小花", "小葵", "小美", "小蘭"}, 'B'});
	questions.push_back({"請問下列角色何人的職業不是忍者?", {"?田銀時(銀魂)", "千代女(骸骨騎士大人異世界冒險中)", "春日(戰國BASARA)", "東谷小雪(keroro軍曹)"}, 'A'});
	questions.push_back({"下列哪一位角色不是動畫《公主連結☆Re:Dive》?戀育幼院的成員？", {"鈴莓", "綾音", "胡桃", "柚希"}, 'D'});
	questions.push_back({"下列選項中，哪兩位不是『青梅竹馬』的關係？", {"野比大雄&源靜香(多拉A夢)", "朽木露琪亞&戀次(BLEACH)", "大路餅藏&北白川玉子(玉子市場)", "利歐&綾瀨美春(精靈幻想記)"}, 'D'});
	questions.push_back({"動畫《美妙旋律 Dear My Future》中，勇華、齊二人組成的團體名是？", {"Leo/need", "LOVE-MIX", "Vivid BAD SQUAD", "Wonderlands×Showtime"}, 'B'});
	questions.push_back({"動畫《刀劍神域》中桐人在74層對付閃耀魔眼使用的招式為？", {"星爆氣流斬(星光連流擊)", "日蝕", "雙重扇形斬", "新星升天"}, 'A'});
	questions.push_back({"《影子籃球員》(黑子的籃球)漫畫中，曾經發動過ZONE的人有幾位?", {"4", "5", "6", "7"}, 'B'});
	questions.push_back({"《惡魔高校DxD》中誰的階級為西洋棋中的皇后？", {"莉雅絲", "愛西亞", "姬島朱乃", "塔城小貓"}, 'C'});
	questions.push_back({"下列哪位角色的聲優並非內山昂輝？", {"姬川大輝(我推的孩子)", "真城最高 (爆漫王)", "月島螢(排球少年！！)", "織斑一夏(IS〈Infinite Stratos〉)"}, 'B'});
	questions.push_back({"《處女愛上姊姊》這系列作品中，歷代 Elder Sister 的正確順序？", {"幸穗→紫苑→瑞穗→奏→千早", "幸穗→奏→紫苑→千早→瑞穗", "奏→幸穗→千早→紫苑→瑞穗", "紫苑→瑞穗→奏→幸穗→千早"}, 'A'});
	questions.push_back({"動畫《線上遊戲的老婆不可能是女生？》中玉置亞子的遊玩風格？", {"付費至上主義", "美觀至上主義", "攻擊至上主義", "輕鬆玩至上主義"}, 'B'});
	questions.push_back({"在《CODE GEASS反逆的魯路修》中，魯路修以隱藏身分領導日本人民，請問變裝後的魯路修以何者為名?", {"NO NAME", "GEASS", "ZERO", "KING"}, 'C'});
	questions.push_back({"《約會大作戰》中『夜刀神十香』的天使名稱是?", {"鏖殺公", "刻刻帝", "滅絕天使", "破軍歌姬"}, 'A'});
	questions.push_back({"動畫《鑽石王牌》中，降谷喜歡看什麼書？", {"百科全書", "色色的書", "動物圖鑑", "棒球場使用手冊"}, 'C'});
	questions.push_back({"《Love Live!》劇場版中，真姬在車上親吻的對象是誰?", {"真姬的爸爸", "真姬的姐姐", "真姬的弟弟", "真姬的青梅竹馬"}, 'A'});
	questions.push_back({"下列彩虹社Vtuber中身高最高的是？", {"劍持刀也(Kenmochi Toya)", "緋八舞成(Hibachi Mana)", "不破湊(Fuwa Minato)", "三枝明那(Saegusa Akina)"}, 'C'});
	questions.push_back({"下列哪位Vtuber不是彩虹社2期生?", {"伏見學(Fushimi Gaku)", "吉爾扎倫三世(Gilzaren Ⅲ)", "文野環(Fumino Tamaki)", "月之美兔(Tsukino Mito)"}, 'D'});
	questions.push_back({"請問這是哪一位Vtuber的官方介紹文？『夢想在大舞台上大顯身手的高中生。為了用自己的力量實現夢想，躍入了這個世界。現在的目標是讓相關的人都能露出笑容。』", {"空星煌(Sorahoshi Kirame)", "町田千麻(Machita Chima)", "夕陽莉莉(Yuhi Riri)", "ina"}, 'A'});
	questions.push_back({"下列哪位Vtuber不是人類?", {"周央珊瑚(Suo Sango)", "修女?克蕾雅(Sister Cleaire)", "渡會雲雀(Watarai Hibari)", "多拉(Dala)"}, 'D'});
	questions.push_back({"下列哪一位Vtuber不是hololive DEV_IS團體『FLOW GLOW』的成員?", {"虎金妃笑虎(Koganei Niko)", "輪堂千速(Rindo Chihaya)", "綺綺羅羅薇薇(Kikirara Vivi)", "音乃瀨奏(Otonose Kanade)"}, 'D'});
	questions.push_back({"下列哪一種『柱』沒有出現在鬼滅之刃裡面?", {"花柱", "鹽柱", "炎柱", "蛇柱"}, 'B'});
	questions.push_back({"以下音樂中，沒有在《刀劍神域》中出現的是？", {"Rewaker", "Crossing Field", "Catch the Moment", "ADAMAS"}, 'A'});
	questions.push_back({"《進擊的巨人》中，『盔甲巨人』的真實身份為下列何者?", {"亞妮·雷恩哈特", "萊納·布朗", "貝爾托特·胡佛", "希斯特莉亞·雷斯"}, 'B'});
	questions.push_back({"被公認為日本的第一部動畫片的是？", {"攻殼機動隊", "魯邦三世", "力與世間女子", "芋川掠三玄關．一番之卷"}, 'D'});
	questions.push_back({"以下哪部動畫不是根據Galgame改編的？", {"公主戀人", "灰色的果實", "約會大作戰", "日在校園(School Days)"}, 'C'});
	questions.push_back({"《K-ON！輕音部》被大眾認為是:", {"強國源泉，人生意義", "人類的真實", "宇宙神作", "業界最後的良心"}, 'A'});
	questions.push_back({"Hololive第一個有人物設定的角色是誰?", {"白上吹雪(Shirakami Fubuki)", "時乃空(Tokino Sora)", "蘿蔔子(Roboko-san)", "櫻巫女(Sakura Miko)"}, 'C'});
	questions.push_back({"Hololive三期生某次在諾艾爾家中聚會時說出想喝誰的洗澡水?", {"白銀諾艾爾(Shirogane Noel)", "不知火芙蕾雅(Shiranui Flare)", "兔田佩可拉(Usada Pekora)", "寶鐘瑪琳(Houshou Marin)"}, 'C'});
	questions.push_back({"就大眾所知下列哪位台灣實況主沒有玩過《原神》這款遊戲?", {"阿神", "瑞斯帝亞", "小光", "璐洛洛"}, 'B'});
	questions.push_back({"由Vtuber『月之美兔』主唱的《Moon!!》這首歌，是由誰製作的?", {"粉絲", "她自己", "外面委託", "其他Vtuber為她寫的"}, 'A'});
	questions.push_back({"下面哪個人物沒有親妹妹？", {"真島圭太(請把我當成妹妹，給我超越女友的愛。)", "春日野悠(緣之空)", "久世政近(不時輕聲地以俄語遮羞的鄰座艾莉同學)", "櫻羽春太(妹妹是不能當女友的，可是...)"}, 'A'});
	questions.push_back({"下列哪一種系列的飲料非常受到台灣Vtuber真理果的喜愛?", {"御茶園", "原萃", "冰鎮", "茶裏王"}, 'B'});
	questions.push_back({"下列哪個實況主不是男娘?", {"焦兒", "犬山玉姬", "瑞斯帝亞", "鈴谷秋"}, 'C'});
	questions.push_back({"《精靈幻想記》中，『艾西雅』這個名字代表下列何者?", {"溫暖的春天", "炙熱的夏天", "涼爽的秋天", "寒冷的冬天"}, 'A'});
	questions.push_back({"《平凡職業造就世界最強》中，下列何者人物是人類?", {"緹奧", "希雅", "月", "莉莉安娜"}, 'D'});
	questions.push_back({"《靠廢柴技能【狀態異常】成為最強的我將蹂躪一切》中，主角班上有一對雙胞胎姊妹，名為聖和樹。請問她們的姓氏為下列何者?", {"高雄", "台中", "台北", "嘉義"}, 'A'});
	questions.push_back({"《遊戲人生》中，『人類種』在西洋棋中代表的棋子為何?", {"騎士", "士兵", "國王", "主教"}, 'C'});
	questions.push_back({"Vtuber『華生．艾米莉亞』(Watson Amelia)的角色設定為何?", {"偵探", "狼", "章魚", "鯊魚"}, 'A'});
	questions.push_back({"下列哪位人物在作品裡的戰鬥實力非常強?", {"闇影(我想成為影之強者!)", "勇者正幸(關於我轉生變成史萊姆這檔事)", "克萊伊‧安德里西(嘆氣的亡靈想隱退)", "宮間快人(被捲入了勇者召喚事件卻發現異世界很和平)"}, 'A'});
	questions.push_back({"請問在台灣實況主Restia與Vtuber杏仁咪嚕於2024年秋天舉辦的APEX比賽《瑞杏杯》中，最後的冠軍為下列哪一隊?", {"帷為甚麼不追我埃基", "丸皮鬼殺隊", "Ren生勝利組", "唯悠魔儲義生杏福"}, 'B'});
	questions.push_back({"下列哪一部不是特攝作品?", {"超人力霸王", "假面騎士", "超級戰隊", "無敵鐵金剛"}, 'D'});
	questions.push_back({"下列哪一部小說作者不是舞城王太郎?", {"聽風的歌", "喜歡喜歡最喜歡我愛你(好?好?大好?超愛???。)", "阿修羅女孩", "迪斯科偵探星期三"}, 'A'});
	questions.push_back({"請問『我像喜歡春天的熊一樣喜歡你。』這句話是出自村上春樹的哪一部小說?", {"黑夜之後", "發條鳥年代記", "尋羊冒險記", "挪威的森林"}, 'D'});
	questions.push_back({"台灣Vtuber『歐麥麥麥』有一次因為在玩看圖猜動漫角色遊戲時答錯而接受改名懲罰，請問她改名後叫什麼？", {"歐睦睦睦", "歐火火火", "歐放放放", "歐尊尊尊"}, 'D'});
	questions.push_back({"動畫《死神BLEACH》中，『卯之花烈』原本是第幾番隊的隊長?", {"4", "7", "9", "11"}, 'D'});
	questions.push_back({"《關於我轉生變成史萊姆這檔事》中，坦派斯特地下城的最終BOSS為下列何者?", {"紅丸", "迪亞布羅", "維爾德拉", "蘭加"}, 'C'});
	questions.push_back({"2023年《傳說對決》APL(超級職業聯賽)的世界冠軍是下列哪支戰隊?", {"BMG", "FW", "BAC", "SGP"}, 'A'});
	questions.push_back({"動畫《鏈鋸人》中，OP(片頭曲)『KICK BACK』是由下列哪一個歌手所唱?", {"Ado", "酸欠少女Sayuri", "米津玄師", "星乃一歌"}, 'C'});
	questions.push_back({"下列哪一個人不是Vocaloid P?", {"Orangestar", "cos@暴走P", "Kanaria", "tuki."}, 'D'});
	questions.push_back({"下列哪一位選手沒有獲得過《英雄聯盟》MSI(季中邀請賽)FMVP?", {"ClearLove", "Faker", "Chovy", "Caps"}, 'C'});
	questions.push_back({"在《寶可夢》中，下列哪一隻寶可夢的種族值最高?", {"極巨化無極汰那", "Mega烈空座", "原始型態固拉多", "胡帕(解放胡帕)"}, 'A'});
	questions.push_back({"《週刊少年Jump》連載最久的漫畫為下列哪一部？", {"死神BLEACH", "烏龍派出所", "火影忍者", "海賊王"}, 'B'});
	questions.push_back({"下列哪一部動畫不是由J.C.STAFF製作?", {"現實主義勇者的王國重建記", "2.5次元的誘惑", "鏈鋸人", "食戟之靈"}, 'C'});
	questions.push_back({"下列哪一個遊戲沒有職業賽?", {"傳說對決", "特戰英豪", "第五人格", "俄羅斯方塊"}, 'D'});
	questions.push_back({"遊戲《第五人格》的背景故事開始時間為下列何者?", {"17世紀巴洛克時期", "17世紀啟蒙時代", "18世紀維多利亞時代", "19世紀不列顛治世時期"}, 'C'});
	questions.push_back({"下列哪一部動畫被稱為『名作之壁』?", {"精靈使的劍舞", "IS〈Infinite Stratos〉", "最弱無敗神裝機龍", "落第騎士英雄譚"}, 'B'});
	questions.push_back({"《亂馬?》中，早乙女玄馬是掉進下列哪一座溫泉?", {"熊貓溺泉", "娘溺泉", "貓溺泉", "黑豬溺泉"}, 'A'});
	questions.push_back({"Hololive的Vtuber們常常會有晚上喝酒回，請問誰喝醉酒後會喵喵叫?", {"雪花菈米(Yukihana Lamy)", "白上吹雪(Shirakami Fubuki)", "貓又小粥(Nekomata Okayu)", "亞綺 ‧ 羅森塔爾(Aki Rosenthal)"}, 'B'});
	questions.push_back({"下列哪一部2024年秋季動漫是由Netflix獨家播出?", {"平凡職業造就世界最強", "孤單一人的異世界攻略", "青春之箱", "膽大黨"}, 'C'});
	questions.push_back({"下列哪一個遊戲不是多人遊戲?", {"傳說對決", "貓咪大戰爭", "皇室戰爭", "Apex Legends"}, 'B'});
	questions.push_back({"請問『44.5』是下列哪一個Vtuber的梗(包含已畢業)?", {"音乃瀨奏(Otonose Kanade)", "桐生可可(Kiryu Coco)", "火威青(Hiodoshi Ao)", "湊阿庫婭(Minato Aqua)"}, 'D'});
	questions.push_back({"下列哪個Vtuber不是VSPO!的成員?", {"千燈夕陽(Sendo Yuuhi)", "空澄賽娜(Asumi Sena)", "天宮心(Amamiya Kokoro)", "如月憐(Nekota Tsuna)"}, 'C'});
	questions.push_back({"請問台灣Vtuber『橙米』於2024年底與下列哪一個Vtuber直播舉辦線上結婚典禮?", {"喪屍迪", "諾櫻", "久田", "淺野薰"}, 'A'});
	questions.push_back({"日本Vtuber『結城昨日奈(Yuuki Sakuna)』的名字由來是源自下列哪一部動畫?", {"約會大作戰", "刀劍神域", "神劍闖江湖", "關於我在無意間被隔壁的天使變成廢柴這件事"}, 'B'});
	questions.push_back({"遊戲《人中之龍》在第七代以前的主角為下列何者?", {"春日一番", "桐谷和人", "桐生可可", "桐生一馬"}, 'D'});
	questions.push_back({"小說《噩盡島》是由下列哪位台灣作家所創作?", {"莫仁", "護玄", "水泉", "鬱兔"}, 'A'});
	questions.push_back({"下列哪一部小說的主角視角不是女性視角?", {"謀殺勇者的新娘", "羅梅莉亞戰記", "這個△戀愛喜劇有獲得幸福的義務", "請待在有光的地方"}, 'C'});
	questions.push_back({"下列哪一個遊戲的主題是回合制遊戲?", {"鳴潮", "原神", "寶可夢集換式卡牌遊戲口袋版(PTCG Pocket)", "傳說對決"}, 'C'});
	questions.push_back({"下列哪一部小說不是由日本人創作?", {"刀劍神域", "我獨自升級", "關於我轉生變成史萊姆這檔事", "歡迎來到實力至上主義的教室"}, 'B'});
	questions.push_back({"下列哪句話不是《BanG Dream! It’s myGo!!!!!》出現過的台詞？", {"「是又怎樣。」", "「一輩子和我一起組樂團嗎。」", "「啊不就好棒棒。」", "「還真是高高在上呢。」"}, 'C'});
	questions.push_back({"請問下列哪一部電影的導演不是新海誠?", {"你的名字", "天氣之子", "鈴芽之旅", "崖上的波妞"}, 'D'});
	questions.push_back({"請問『伊織萌』的身份為下列何者？", {"Vtuber", "Cosplayer", "歌手", "聲優"}, 'B'});
	questions.push_back({"請問下列哪一個選項不是Vtuber事務所？", {"Hololive", "NIJISANJI(彩虹社）", "時雨羽衣", "VSPO!"}, 'C'});
	questions.push_back({"請問下列哪一部動漫不是2025年1月新番或續番？", {"我獨自升級", "進擊的巨人", "結緣甘神神社", "這公司有我喜歡的人"}, 'B'});
	questions.push_back({"請問由『星街彗星』所演唱的歌曲《????》(Bibideba)，是參考了下列哪一個童話故事作為背景？", {"灰姑娘", "白雪公主", "小飛俠", "小美人魚"}, 'A'});
	questions.push_back({"請問在台灣Vtuber中，目前擁有Youtube最高訂閱數的為下列何者？", {"厄倫蒂兒", "浠Mizuki", "歐麥麥麥", "杏仁咪嚕"}, 'D'});
	questions.push_back({"請問《刀劍神域》的主角為下列何者？", {"野比大雄", "工藤新一", "桐谷和人", "野原新之助"}, 'C'});
	questions.push_back({"《進擊的巨人》中，始祖尤米爾的力量被其後代繼承並分為九大巨人，請問以下何者不包涵在九大巨人之內？", {"戰錘巨人", "槍之巨人", "進擊的巨人", "女巨人"}, 'B'});
	questions.push_back({"在《航海王》中，魯夫的懸賞金首次超過10億貝里是在擊敗誰之後？", {"多佛朗明哥", "卡塔克利", "克洛克達爾", "凱多"}, 'B'});
	questions.push_back({"《鬼滅之刃》中，炭治郎的日輪刀最初是什麼顏色？", {"紅色", "黑色", "藍色", "綠色"}, 'B'});
	questions.push_back({"日本Vtuber事務所Hololive的母公司為下列何者？", {"ANYCOLOR Inc.", "COVER Corp.", "774 Inc.", "Activ8 Inc."}, 'B'});
	questions.push_back({"下列哪位Vtuber是NIJISANJI(彩虹社)的成員？", {"雪花菈米(Yukihana Lamy)", "葛葉(Kuzuha)", "火威青(Hiodoshi Ao)", "千燈夕陽(Sendo Yuuhi)"}, 'B'});
	questions.push_back({"Vtuber事務所VShojo的觀眾主要以哪個地區為主？", {"日本", "韓國", "北美", "台灣"}, 'C'});
	questions.push_back({"Vtuber『Neuro-sama』的中之人身份為下列何者？", {"AI", "聲優", "偶像", "未知"}, 'A'});
	questions.push_back({"在 Hololive裡，哪位 Vtuber以『蛙語』和『湯匙梗』聞名？", {"尾丸波爾卡(Omaru Polka)", "白上吹雪 (Shirakami Fubuki)", "音乃瀨奏(Otonose Kanade)", "大空昴(Oozara Subaru)"}, 'D'});
	questions.push_back({"《刀劍神域》的作者為下列何者？", {"川原礫", "鎌池和馬", "伏見司", "白米良"}, 'A'});
	questions.push_back({"在《OVERLORD》中，安茲 ‧烏爾 ‧ 恭(Ainz Ooal Gown)原本在遊戲中的ID名稱為下列何者？", {"莫莫(Momon)", "飛鼠(Momonga)", "亞因茲(Ainz)", "夏提雅(Shalltear)"}, 'B'});
	questions.push_back({"在《加速世界》中，男主角春雪的遊戲化身(Avatar)為下列何者？", {"Scarlet Flame", "Black Lotus", "Silver Crow", "Azure Healer"}, 'C'});
	questions.push_back({"在《果然我的青春戀愛喜劇搞錯了。》中，男主角比企谷八幡最常說的一句座右銘是？", {"「人與人之間的關係總會破裂。」", "「這一定是哪裡搞錯了。」", "「現實是殘酷的。」", "「求求你我什麼都願意做。」"}, 'A'});
	questions.push_back({"在《Re：從零開始的異世界生活》中，昴最初在異世界遇見的少女是？", {"雷姆", "貝緹可", "艾蜜莉雅", "菲魯特"}, 'C'});
	questions.push_back({"在《涼宮春日的憂鬱》中，涼宮春日最初成立的社團名稱是？", {"SOS社", "文藝社", "未知探究會", "超自然研究部"}, 'A'});
	questions.push_back({"《銀魂》20週年紀念展的正式名稱是？", {"銀魂展～二十年的回憶～", "銀魂展～二十周年慶典～", "銀魂展～二十歲的聚會～", "銀魂展～二十年之路～"}, 'C'});
	questions.push_back({"「我要代替月亮懲罰你！」這句台詞是出自哪部作品？", {"美少女戰士", "Re：從零開始的異世界生活", "JOJO的奇妙冒險", "鬼滅之刃"}, 'A'});
	questions.push_back({"《Final Fantasy VII》中，賽菲羅斯最具代表性的武器是？", {"闡釋者", "降魔劍", "日輪刀", "太刀 ‧ 白夜"}, 'B'});
	questions.push_back({"《艾爾登法環》是由下列哪個遊戲公司開發的？", {"Ubisoft", "FromSoftware", "Capcom", "Bethesda"}, 'B'});
	questions.push_back({"在《薩爾達傳說 王國之淚》中相對於《薩爾達傳說 曠野之息》，林克可以使用的新能力不包括下列哪一個？", {"餘料建造", "倒轉乾坤", "通天術", "磁力操控"}, 'D'});
	questions.push_back({"「看來你還不懂得，我為什麼被稱為......」這句台詞最常被哪位動漫角色使用？", {"宇智波斑(火影忍者)", "迪奧(JOJO的奇妙冒險)", "庫洛洛(獵人×獵人)", "愛德華 ‧ 艾力克(鋼之鍊金術師)"}, 'B'});
	questions.push_back({"《一拳超人》中的主角琦玉是如何獲得超強力量的？", {"進行極限訓練", "被外星人賦予能力", "吃了神奇的藥丸", "進行基因實驗"}, 'A'});
	questions.push_back({"《冰?》中，女主角千反田愛?的口頭禪為下列何者？", {"「是又怎樣。」", "「原來如此。」", "「我很好奇！」", "「真相永遠只有一個。」"}, 'C'});
	questions.push_back({"下列哪一部漫畫不是由台灣作家所創作？", {"貓妖傳", "小籠包誕生物語", "?身", "冥戰錄"}, 'B'});
	questions.push_back({"動畫《葬送的芙莉蓮》中，芙莉蓮的主要職業是？", {"劍士", "僧侶", "盜賊", "魔法師"}, 'D'});
	questions.push_back({"暗殺教室是幾週年快閃？", {"5", "10", "15", "20"}, 'B'});
	questions.push_back({"柯南2025電影名稱？", {"獨眼的殘像", "獨眼的幻像", "獨瞳的殘像", "單眼的殘響"}, 'A'});
	questions.push_back({"沒有公布畢業的Vtuber？", {"Gawr Gura", "Fulgur Ovid", "小鳥遊???", "紫?詩音"}, 'C'});
	questions.push_back({"吉伊卡哇的吉伊最討厭吃的是？", {"紅蘿蔔", "水煮花椰菜", "鯛魚燒", "關東煮"}, 'B'});
	questions.push_back({"哪個品牌沒有製作痛包？", {"名創優品", "Wego", "大創", "浮游貓"}, 'A'});
	questions.push_back({"第五季機器翻譯把“文豪野犬”翻成了什麼？", {"文豪野犬", "?哥流浪狗", "邦戈流浪狗", "邦戈俊坤"}, 'C'});
	questions.push_back({"進擊的巨人兵長砍了幾次野獸巨人？", {"3", "4", "5", "6"}, 'B'});
	questions.push_back({"哪個不是迷宮飯的人種？", {"精靈", "長身上", "矮人", "長腿人"}, 'D'});
	questions.push_back({"失憶投捕中要圭在初三時失憶的原因是什麼？", {"遭遇車禍", "長時間的精神壓力", "被毒害", "遺傳性疾病"}, 'B'});
	questions.push_back({"Netflix 預告公開的狂賭深淵真人版是？", {"日劇", "美劇", "韓劇", "台劇"}, 'B'});
    playQuiz(questions);


    return 0;
}

