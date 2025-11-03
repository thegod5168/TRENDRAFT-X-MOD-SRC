#include <android/log.h>
#include <unistd.h>
#include <thread>
#include <limits>
#include <KittyMemory/KittyMemory.h>
#include <KittyMemory/MemoryPatch.h>
#include <KittyMemory/KittyScanner.h>
#include <KittyMemory/KittyUtils.h>
#include "oxorany/oxorany.h"
#include <xdl.h>
#include <KittyUtils.h>
#include <KittyMemory.h>
#include <Il2Cpp.h>
#include <SubstrateHook.h>
#include <CydiaSubstrate.h>
#include "RishabhModsHook/gui.hpp"
#include "TRENDRAFT_UI/Theme.h"
#include "Rishabh.hpp"
#include "RishabhUi/CN.h"
#include "RishabhUi/Icon.h"
#include "RishabhUi/Font.h"
#include "RishabhUi/YTBODEVELOPER.h"
#include "RishabhUi/autofont.h"
#include <Themes.h>
#include "Firewall.h"
#include "exptime.h"
#include "Rishabh.h"
#include <fstream>
#include "RishabhUi/AGENCYB.h" 
#include "RishabhBypass/NawarFirewall1.h"
#include <ctime>
#include "imgui.h"
#include "imgui_internal.h"
#define ICON_MIN_FA 0xf000
#define ICON_MAX_FA 0xf957
#define ICON_FA_GAMEPAD      "\xef\x84\x9b" // U+f11b
#define ICON_FA_GAVEL        "\xef\x83\xa3" // U+f0e3
#define ICON_FA_BAN          "\xef\x81\x9e" // U+f05e
#define ICON_FA_SPINNER      "\xef\x84\x90" // U+f110
#define ICON_FA_HEARTBEAT    "\xef\x88\x9e" // U+f21e
#define ICON_FA_TASKS        "\xef\x82\xae" // U+f0ae
// ======================================================================== //
static bool Feu;
static bool Test = false;          // ตัวแปรใหม่แทน Enable
static bool lastTestState = false; // เก็บสถานะก่อนหน้า
static bool isHidden = false;
static bool showMainMenu = true;
static float Time_01 = 1.0f;
ImFont* ItSMKOP = nullptr;
bool PeekUp = true;
float Setspeed = 144.0f;
bool WIDEVIEW = true;
float Cross = 10.0f;
bool UP = false;
bool fastchut = true;
float ControlSpeed = 0.40;
////float WIDEVIEW1 = 190.0f
bool DEVILADITYA = false;
bool DEVILCHEAT = false;
bool RoZERRK;
bool initImGui = false , bValid = true;
bool ZOOMV3 = false;
bool show_WindowV1 = false;
bool show_WindowV2 = false;
bool show_WindowV3  = false;
bool show_WindowV4 = false;
bool RLFLYMOD = true;
bool AimButton2 = true;
bool MEMBYPASS = false,
mkmk = false,
mkmkk = false,
mkmkkk = false,
UrlLink = false,
Godviewup = false,
Godviewdown = false,
///Awm = false,
FIXSTUCK = false,
SKYSHOT = false,
STUCK2 = false;
bool Linee;
bool Lineee;
/////bool AimWhen2;
bool alert;
/////bool AimSilent;
/////bool Rishabhwater;
bool Distancee;
bool TeamIDd;
bool Vehiclee;
bool Weaponn;
bool Infoo;
bool Radarr;
bool Alertt;
bool View;
bool Recoil;
bool IgBot;
bool IgKnock;
bool VisCheck;
bool Unlock;
bool FastChut = true;
bool MK = false;

#include <imgui.h>
#include <vector> 
#include <string>
#include <algorithm> 
#include <chrono>


// =============================== [ระบบแจ้งเตือน] ===============================//

struct NotificationData {
    std::string title;
    std::string description;
    ImVec4 titleColor;
    ImVec4 descColor;
    ImVec4 bgColor;
    float duration;  // วินาทีที่อยู่บนจอ
    float xOffset;   // ตำแหน่งเลื่อนจากขอบขวา
};

std::vector<NotificationData> notifications;

// เรียกฟังก์ชันนี้เพื่อสร้าง Notification ใหม่
void Notification(const std::string& title,
                  const std::string& description,
                  ImVec4 titleColor,
                  ImVec4 descColor,
                  ImVec4 bgColor,
                  float duration = 2.0f)
{
    notifications.push_back({title, description, titleColor, descColor, bgColor, duration, 0.0f}); 
    // 300 คือเริ่มจากขอบจอทางขวา
}

// ฟังก์ชันนี้เรียกทุก Frame เพื่ออัพเดตและวาด Notification
void RenderNotifications(float deltaTime)
{
    float slideSpeed = 600.0f; // ความเร็ว px ต่อวินาที
    float startY = 50.0f;      // เริ่มจากบนสุด
    float spacing = 5.0f;      // ช่องว่างแต่ละ Notification

    // อัพเดตตำแหน่ง Notification

    for (auto& n : notifications) { 
    
        float rightEdge = (ImGui::GetIO().DisplaySize.x - n.xOffset) + ImGui::GetWindowWidth();
        if (n.xOffset < 220 && n.duration > 0) {
            n.xOffset += slideSpeed * deltaTime;
        } else if (n.duration > 0) {
            n.duration -= deltaTime;
        } else {
            n.xOffset -= slideSpeed * deltaTime;
        }
        


    }

    // วาด Notification    
    float currentY = startY;
    for (auto& n : notifications) {
        ImGui::SetNextWindowPos(ImVec2(ImGui::GetIO().DisplaySize.x - n.xOffset, currentY));
        ImGui::SetNextWindowBgAlpha(n.bgColor.w); // ความโปร่งใสของพื้นหลัง
        ImGui::PushStyleColor(ImGuiCol_WindowBg, n.bgColor);

        ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(1.0f, 1.0f, 1.0f, 1.0f)); 
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(5,5)); // padding รอบทั้ง window
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 1.0f); // ความหนาขอบ

        ImGui::Begin("##Notification", NULL,
        ImGuiWindowFlags_NoTitleBar |
        ImGuiWindowFlags_AlwaysAutoResize |
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoMove
    );

        ImGui::PushStyleColor(ImGuiCol_Text, n.titleColor);
        ImGui::Text("%s", n.title.c_str());
        ImGui::PopStyleColor();
    
        //ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(10,5)); // ลด padding ของ background
        ImGui::PushStyleColor(ImGuiCol_Text, n.descColor);
        ImGui::Text("%s", n.description.c_str());
        ImGui::PopStyleColor();

        ImGui::End();

    // 🔁 คืนค่าการตั้งค่า style
        //ImGui::PopStyleVar();   // WindowBorderSize
        //ImGui::PopStyleColor(2); // Border + WindowBg
        
        ImGui::PopStyleVar(2);   // Pop ทั้ง WindowPadding + WindowBorderSize
        ImGui::PopStyleColor(1); // Pop Border (ถ้า push ก่อน Begin)


        currentY += ImGui::GetWindowHeight() + spacing;
    }
    // ลบ Notification ที่เลื่อนออกนอกจอ
    notifications.erase(
        std::remove_if(notifications.begin(), notifications.end(),
                       [](const NotificationData& n){ return n.xOffset < 0.0f; }),
        notifications.end()
    );
}



std::string GetABI() {
#if defined(__aarch64__)
    std::string abi = "arm64-v8a";
#elif defined(__arm__)
    std::string abi = "armeabi-v7a";
#elif defined(__i386__)
    std::string abi = "x86";
#elif defined(__x86_64__)
    std::string abi = "x86_64";
#else
    std::string abi = "unknown";
#endif

    // ตัวแรกเป็นพิมพ์ใหญ่
    if (!abi.empty()) abi[0] = toupper(abi[0]);
    return abi;
}

#include <map>
#include <unordered_map>
struct checkbox_animation
{
    float animation = 0.0f;
    float text_opacity = 1.0f;
    float lodaa = 0.0f;
    float lodaa1 = 0.0f;
    float lodaa2 = 0.0f;
};

static std::unordered_map<ImGuiID, checkbox_animation> g_checkbox_animations;


void MyCustomSwitch(const char* label, bool* v) {
    float width = 70.0f;
    float height = 40.0f;
    float marginRight = 40.0f; // ระยะห่างจากขอบขวา

    ImGui::Text("   %s", label);

    // ให้สวิตช์อยู่ในบรรทัดเดียวกับข้อความ
    ImGui::SameLine();

    // พื้นที่ของ window ตอนนี้
    ImVec2 win_pos = ImGui::GetWindowPos();
    ImVec2 win_size = ImGui::GetWindowSize();

    // Y ตรงกลางข้อความ
    float textHeight = ImGui::GetTextLineHeight();
    float y_center = ImGui::GetCursorScreenPos().y - (height - textHeight) * 0.5f;

    // ตำแหน่ง X = ขอบขวา - width - marginRight
    float x_pos = win_pos.x + win_size.x - width - marginRight - ImGui::GetStyle().WindowPadding.x;

    ImVec2 p = ImVec2(x_pos, y_center);

    ImDrawList* draw = ImGui::GetWindowDrawList();

    // สีพื้นหลัง
    ImU32 col_bg = *v ? IM_COL32(180, 2, 2, 255) : IM_COL32(255, 255, 255, 255);
    draw->AddRectFilled(p, ImVec2(p.x + width, p.y + height), col_bg, height * 0.5f);

    // วงกลม + ขอบดำ
    ImU32 circle_col = IM_COL32(255, 255, 255, 255);
    float circleX = *v ? (p.x + width - height / 2) : (p.x + height / 2);
    ImVec2 circleCenter = ImVec2(circleX, p.y + height / 2);
    float circleRadius = height * 0.45f;

    draw->AddCircleFilled(circleCenter, circleRadius, circle_col);
    draw->AddCircle(circleCenter, circleRadius, IM_COL32(0, 0, 0, 255), 32, 1.0f);

    // InvisibleButton สำหรับคลิก
    ImGui::SetCursorScreenPos(p);
    ImGui::InvisibleButton(label, ImVec2(width, height));
    if (ImGui::IsItemClicked()) {
        *v = !*v;
    }
}


bool MyCustomCheckbox(const char* label, bool* v)
{
    ImGuiWindow* window = ImGui::GetCurrentWindow();
    if (window->SkipItems)
        return false;

    ImGuiContext& g = *GImGui;
    const ImGuiStyle& style = g.Style;
    const ImGuiID id = window->GetID(label);
    const ImVec2 label_size = ImGui::CalcTextSize(label, NULL, true);

    const ImVec2 pos = window->DC.CursorPos;
    const float height = 40.0f;
    const float box_size = 40.0f;

    const ImRect total_bb(pos, ImVec2(pos.x + 220, pos.y + height));
    ImGui::ItemSize(total_bb, 0.f);
    if (!ImGui::ItemAdd(total_bb, id))
        return false;

    bool hovered, held;
    bool pressed = ImGui::ButtonBehavior(total_bb, id, &hovered, &held);
    if (pressed)
    {
        *v = !(*v);
        ImGui::MarkItemEdited(id);
    }

    // Animation cache
    auto it = g_checkbox_animations.find(id);
    if (it == g_checkbox_animations.end())
        it = g_checkbox_animations.insert({ id, checkbox_animation() }).first;

    float dt = ImGui::GetIO().DeltaTime;
    float speed = 50.0f * dt;
    it->second.animation = ImLerp(it->second.animation, *v ? 1.0f : 0.0f, speed);

    // วาดพื้นหลัง (สีดำ) 
    window->DrawList->AddRectFilled(
        ImVec2(total_bb.Min.x, total_bb.Min.y),
        ImVec2(total_bb.Max.x, total_bb.Max.y),
        IM_COL32(10, 10, 10, 0),
        6.0f
    );

    // Checkbox outline
    ImVec2 box_min = ImVec2(total_bb.Min.x + 3, total_bb.Min.y + 3);
    ImVec2 box_max = ImVec2(box_min.x + box_size, box_min.y + box_size);

    window->DrawList->AddRect(
        box_min, box_max,
        IM_COL32(180, 2, 2, 255), // สีขอบ
        6.0f, 0, 2.0f
    );

    // Fill when checked
    if (it->second.animation > 0.05f)
    {
        ImU32 fill_col = IM_COL32(80, 2, 2,(int)(205 * it->second.animation));
        window->DrawList->AddRectFilled(
            box_min, box_max,
            fill_col, 4.0f
        );

        // เครื่องหมายถูก
        ImVec2 p1 = ImVec2(box_min.x + 7, box_min.y + box_size / 5);
        ImVec2 p2 = ImVec2(box_min.x + 11, box_min.y + box_size - 7);
        ImVec2 p3 = ImVec2(box_min.x + box_size - 7, box_min.y + 7);
        window->DrawList->AddLine(p1, p2, IM_COL32(180, 2, 2, 255), 6.0f);
        window->DrawList->AddLine(p2, p3, IM_COL32(180, 2, 2, 255), 6.0f);
    }

    // Text
    window->DrawList->AddText(
        ImVec2(box_max.x + 10, total_bb.Min.y + 5),
        IM_COL32(180, 2, 2, 255),
        label
    );

    return pressed;
}

// กำหนดให้มี:  #include "imgui.h"

void DrawBottomBanner(const char* text, float barHeight = 40.0f, float rounding = 6.0f, float alpha = 0.85f)
{
    ImVec2 display = ImGui::GetIO().DisplaySize;
    ImDrawList* dl = ImGui::GetForegroundDrawList();

    // style / geometry
    const float margin = 12.0f;                     // distance from left/right screen edges
    const float bottomOffset = 10.0f;               // distance from screen bottom to banner
    const ImVec2 barTL(margin, display.y - bottomOffset - barHeight); // top-left
    const ImVec2 barBR(display.x - margin, display.y - bottomOffset); // bottom-right
    const ImU32 bgColor = ImGui::GetColorU32(ImVec4(0.f, 0.f, 0.f, alpha)); // black, semi-transparent
    const ImU32 borderColor = ImGui::GetColorU32(ImVec4(1.f, 1.f, 1.f, alpha * 0.05f));
    const ImU32 textColor = ImGui::GetColorU32(ImVec4(1.f, 1.f, 1.f, 1.f)); // white
}
 
//===============XOR ENCYPTION END HERE=============================================//
#define ICON_FA_EYE "\xef\x81\xae"
#define ICON_FA_FIRE "\xef\x81\xad"
#define ICON_FA_CROSSHAIRS "\xef\x81\x9b"
#define ICON_FA_USER_NINJA "\xef\x94\x9c"
#define ICON_FA_BOLT "\xef\x83\xa7"
#define ICON_FA_GUN "\xef\xa3\xaf" // optional, FA v6
#define ICON_FA_TELEGRAM "\xef\x8b\xac"
#define CREATE_COLOR(r, g, b, a) new float[4]{(float)r, (float)g, (float)b, (float)a};
static float isRed = 0.0f, isGreen = 0.01f, isBlue = 0.0f;
int32_t ToColor(float * col) {
return ImGui::ColorConvertFloat4ToU32( * (ImVec4 *)(col));}
#define SLEEP_TIME 1000LL / 120LL
int screenWidth = -1, glWidth, screenHeight = -1, glHeight;
////float density = -1;
int Write_Float(long int addr, float value) {
Tools::WriteAddr((void *) (addr), (void *) &value, 4);
return 0;}
bool WriteAddr(void *addr, void *buffer, size_t length) {
unsigned long page_size = sysconf(_SC_PAGESIZE);
unsigned long size = page_size * sizeof(uintptr_t);
return mprotect((void *) ((uintptr_t) addr - ((uintptr_t) addr % page_size) - page_size), (size_t) size, PROT_EXEC | PROT_READ | PROT_WRITE) == 0 && memcpy(addr, buffer, length) != 0;}
template<typename T>
void Write(uintptr_t addr, T value) {
WriteAddr((void *) addr, &value, sizeof(T));}
std::map<int, bool> Items;
////Made By @Rishabhmodx//////
enum EAimTarget {
HeadT = 0,
Chest = 1
};
enum EAimRange {
R_360 = 0,
};
enum EAimTrigger {
None = 0,
Shooting = 1,
Scoping = 2,
Both = 3,
Any = 4
};
//ImVec4 particleColor = ImVec4(0.2f, 1.0f, 0.4f, 1.0f);  // Change color here
namespace settings {
    ImVec4 particleColour = ImVec4(0.26f, 0.59f, 0.98f, 0.70f); // Accent color with alpha
    static int Tab = 1;
   // float Fov_Aim = 100.0f;
   }
void (*OpenURL)(String *url);

//=========================================================================//
//#define OBFUSCATE(str) str
///static float isRed = 0.0f, isGreen = 0.01f, isBlue = 0.0f;
static float isRedV2 = 0.0f, isGreenV2 = 0.01f, isBlueV2 = 0.0f;
// At the top of your .cpp (ONLY ONCE)
static float pulse = 0.0f;


bool Items_Esp_Menu = false;
bool FPS = true;
bool HIDEESP = true;


// 👇 Include your XOR/obfuscation stuff
#define ICON_FA_EYE "\xef\x81\xae"
#define ICON_FA_FIRE "\xef\x81\xad"
#define ICON_FA_RUNNING "\xef\x9c\x8c"
#define ICON_FA_CROSSHAIRS "\xef\x81\x9b"
#define ICON_FA_BOLT "\xef\x83\xa7"
#define ICON_FA_USER_SECRET "\xef\x88\x9b"
extern ImVec4 settings::particleColour;

static ImFont* iconFont = nullptr; // FA ICON font

inline ImVec2 Add(const ImVec2& a, const ImVec2& b) {
    return ImVec2(a.x + b.x, a.y + b.y);
}
inline ImVec2 Sub(const ImVec2& a, const ImVec2& b) {
    return ImVec2(a.x - b.x, a.y - b.y);
}
inline ImVec2 Mul(const ImVec2& a, float scale) {
    return ImVec2(a.x * scale, a.y * scale);
}
// ======================================================================== //
struct My_Patches {
    MemoryPatch Bypass1;
    MemoryPatch Bypass2;
    MemoryPatch Bypass3;
    MemoryPatch Bypass4;
    MemoryPatch Bypass5;
    MemoryPatch Bypass6;
    MemoryPatch Bypass7;
    MemoryPatch Bypass8;
    MemoryPatch Bypass9;
    MemoryPatch Bypass10;
    MemoryPatch Bypass11;
    MemoryPatch Bypass12;
    MemoryPatch Bypass13;
    MemoryPatch Bypass14;
    MemoryPatch Bypass15;
    
    MemoryPatch Guest;
} hexPatches;
using zygisk::Api;
using zygisk::AppSpecializeArgs;
using zygisk::ServerSpecializeArgs;


void hack();
void writeLog(const std::string& logMessage, const std::string& filename = "/storage/emulated/0/Android/data/com.dualspace.multispace.androidx/files/log.txt");


JavaVM *jvm;
JNIEnv *genv;


class MyModule : public zygisk::ModuleBase {
 public:
  void onLoad(Api *api, JNIEnv *env) override {
    this->api_ = api;
    this->env_ = env;
    genv = env;
   // gEnv = env;

  }

  void preAppSpecialize(AppSpecializeArgs *args) override {
    static constexpr const char *packages[] = {
        "com.dts.freefireth"
    };
    const char *process = env_->GetStringUTFChars(args->nice_name, nullptr);
    for (const auto *package: packages) {
      is_game_ = (strcmp(process, package) == 0);
      if (is_game_) {
        break;
      }
    }
    env_->ReleaseStringUTFChars(args->nice_name, process);
  }

  void postAppSpecialize(const AppSpecializeArgs *args) override {
    if (is_game_) {
       genv->GetJavaVM(&jvm);
     //  genv->GetJavaVM(&gJvm);
      std::thread{hack}.detach();
    }
  }

 private:
  Api *api_ = nullptr;
  JNIEnv *env_ = nullptr;
  bool is_game_ = false;
};


uintptr_t il2cpp_base = 0;
void *getRealAddr(ulong offset) {
    return reinterpret_cast<void*>(il2cpp_base + offset);
};

static int Tab = 1;




void ImGui_v_Menu(int s_tchtch, const char *s_string, bool *b_boolean) {
    ImGui::Checkbox(s_string, b_boolean);
    bool b_setonoff = *b_boolean;
    	
    switch (s_tchtch) {
        
      case 1:

            case 2:
            
            if (b_setonoff) {
                hexPatches.Guest.Modify();
            } else {
                hexPatches.Guest.Restore();
            }
            
            break;
			
			case 3:
            BypassN = *b_boolean;
            if (BypassN) {
				hexPatches.Bypass6.Modify();
        hexPatches.Bypass7.Modify();
        hexPatches.Bypass8.Modify();
        hexPatches.Bypass9.Modify();
        hexPatches.Bypass10.Modify();
                
				
        
            } else {
                
        hexPatches.Bypass6.Restore();
        hexPatches.Bypass7.Restore();
        hexPatches.Bypass8.Restore();
        hexPatches.Bypass9.Restore();
        hexPatches.Bypass10.Restore();
            }
            
            break;
			case 4:
            BypassA = *b_boolean;
            if (BypassA) {
                hexPatches.Bypass11.Modify();
        hexPatches.Bypass12.Modify();
        hexPatches.Bypass13.Modify();
        hexPatches.Bypass14.Modify();
		hexPatches.Bypass15.Modify();
            } else {
        hexPatches.Bypass11.Restore();
        hexPatches.Bypass12.Restore();
        hexPatches.Bypass13.Restore();
        hexPatches.Bypass14.Restore();
		hexPatches.Bypass15.Restore();
            }
            
            break;
        default:
            // Xử lý các trường hợp khác (nếu cần)
            break;
        
    }
}


bool clearMousePos = true;
bool ImGuiOK = false;
///bool initImGui = false;
//bool rainbow = false;
inline EGLBoolean (*old_eglSwapBuffers)(EGLDisplay dpy, EGLSurface surface);
inline EGLBoolean hook_eglSwapBuffers(EGLDisplay dpy, EGLSurface surface) {
    
        eglQuerySurface(dpy, surface, EGL_WIDTH, &g_GlWidth);
    eglQuerySurface(dpy, surface, EGL_HEIGHT, &g_GlHeight);
    
    if (!g_IsSetup) {
        // เก็บขนาดหน้าจอ
        prevWidth = g_GlWidth;
        prevHeight = g_GlHeight;

        // เตรียม ImGui
        SetupImgui();
        ImGui_ImplOpenGL3_Init("#version 300 es");

        ImGuiIO & io = ImGui::GetIO();
        io.IniFilename = NULL; // ปิดการเซฟ layout

        // ================= ICON FONTS (FontAwesome)
        static const ImWchar icons_ranges[] = {0xf000, 0xf3ff, 0};
        ImFontConfig icons_config;
        icons_config.MergeMode = true;
        icons_config.PixelSnapH = true;
        icons_config.OversampleH = 2.5f;
        icons_config.OversampleV = 2.5f;

        io.DisplaySize = ImVec2((float)glWidth, (float)glHeight);

        // ================= CUSTOM FONT ของหมิง
        ImFontConfig CustomFontConfig;
        CustomFontConfig.FontDataOwnedByAtlas = false; // memory ของเราเอง
        CustomFontConfig.SizePixels = 25.0f;           // ขนาดฟอนต์

        // โหลดฟอนต์จาก memory array ของหมิง
        ImFont* myFont = io.Fonts->AddFontFromMemoryTTF(
            (void*)_sdcard_Download_AGENCYB_ttf,   // pointer ของ array
            sizeof(_sdcard_Download_AGENCYB_ttf), // ขนาด array
            25.0f,                                           // ขนาดฟอนต์
            &CustomFontConfig,
            io.Fonts->GetGlyphRangesThai()                  // โหลดอักษรไทย + อังกฤษ + ตัวเลข + สัญลักษณ์
        );

        if (myFont == nullptr) {
            // หากโหลดฟอนต์ไม่สำเร็จ
            printf("Failed to load custom font!\n");
        } else {
            printf("Font Load");
        }

        // ================= ICON FONT (FontAwesome)
        io.Fonts->AddFontFromMemoryCompressedTTF(
            font_awesome_data,
            font_awesome_size,
            25.0f,
            &icons_config,
            icons_ranges
        );

        // ตั้งฟอนต์ default ของ ImGui เป็นฟอนต์ของหมิง
        io.FontDefault = myFont;

        g_IsSetup = true;
    }

    
    ImGuiIO &io = ImGui::GetIO();
ImGui::StyleColorsDark(); // Start from default dark

    ImGuiStyle *style = &ImGui::GetStyle();
 
style->ScrollbarRounding = 10.0f;
//style->Colors[ImGuiCol_ScrollbarBg] = ImVec4(0, 0, 0, 0);
style->WindowPadding = ImVec2(3, 3);
style->FramePadding = ImVec2(4, 4);
style->FrameRounding = 6.0f;
style->WindowRounding = 6.0f;
style->GrabRounding = 6.0f;      // ความโค้งของ Slider Grab (ตัวจับเลื่อน)
style->WindowTitleAlign = ImVec2(0.5,0.5);
style->ButtonTextAlign = ImVec2(0.5,0.5);

style->Colors[ImGuiCol_Text] = ImColor(255, 255, 255, 255);
style->Colors[ImGuiCol_WindowBg] = ImColor(0, 0, 0, 150); // Darker black
style->Colors[ImGuiCol_SliderGrab] = ImColor(180, 2, 2, 255); // Soft blue
style->Colors[ImGuiCol_FrameBg] = ImColor(30, 30, 30, 200);
style->Colors[ImGuiCol_FrameBgActive] = ImColor(45, 45, 45, 255);
style->Colors[ImGuiCol_FrameBgHovered] = ImColor(50, 50, 50, 255);
style->Colors[ImGuiCol_Border] = ImColor(100, 100, 100, 0);

style->Colors[ImGuiCol_PopupBg] = ImColor(20, 20, 20, 240);

style->Colors[ImGuiCol_Header] = ImColor(40, 40, 40, 200);
style->Colors[ImGuiCol_HeaderActive] = ImColor(50, 50, 50, 255);
style->Colors[ImGuiCol_HeaderHovered] = ImColor(60, 60, 60, 255);

style->Colors[ImGuiCol_Tab] = ImColor(25, 25, 25, 0);
style->Colors[ImGuiCol_TabActive] = ImColor(60, 60, 60, 255);
style->Colors[ImGuiCol_TabHovered] = ImColor(70, 70, 70, 255);

style->Colors[ImGuiCol_Button] = ImColor(35, 35, 35, 255);
style->Colors[ImGuiCol_ButtonActive] = ImColor(60, 60, 60, 255);
style->Colors[ImGuiCol_ButtonHovered] = ImColor(55, 55, 55, 255);

style->Colors[ImGuiCol_TitleBg] = ImColor(20, 20, 20, 220);
style->Colors[ImGuiCol_TitleBgActive] = ImColor(25, 25, 25, 255);
style->Colors[ImGuiCol_TitleBgCollapsed] = ImColor(20, 20, 20, 180);

style->Colors[ImGuiCol_CheckMark] = ImColor(180, 2, 2, 150); // Neon green check

//==========================================  
     
    style->ScaleAllSizes(std::max(1.0f, density / 150.0f));  
    style->ScrollbarSize = 20.0f; 



ImGui_ImplOpenGL3_NewFrame();  
ImGui_ImplAndroid_NewFrame(g_GlWidth, g_GlHeight);  
ImGui::NewFrame();  
DrawBottomBanner("Telegram : @TRENDRAFT");
if (ImGuiOK) {  
    int touchCount = (((int (*)())(Class_Input__get_touchCount))());  
if (touchCount > 0) {  
    UnityEngine_Touch_Fields touch = ((UnityEngine_Touch_Fields(*)(int))(Class_Input__GetTouch))(0);  
    float reverseY = io.DisplaySize.y - touch.m_Position.fields.y;  
    switch (touch.m_Phase) {  
        case TouchPhase::Began:  
        case TouchPhase::Stationary:  
            io.MousePos = ImVec2(touch.m_Position.fields.x, reverseY);  
            io.MouseDown[0] = true;  
            break;  
        case TouchPhase::Ended:  
        case TouchPhase::Canceled:  
            io.MouseDown[0] = false;  
            clearMousePos = true;  
            break;  
        case TouchPhase::Moved:  
            io.MousePos = ImVec2(touch.m_Position.fields.x, reverseY);  
            break;  
        default:  
            break;  
    }  
}  
}  
DrawESP(g_GlWidth, g_GlHeight);

ImGui::End();

ImVec2 center = ImGui::GetMainViewport()->GetCenter();
ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 6.0f); // มุมโค้ง

if (showMainMenu) { // แสดงเมนูถ้า flag เป็น true
ImGui::SetNextWindowSize(ImVec2(450, 600));
if (ImGui::Begin("TRENDRAFT X MOD V5 PLUS EDITION", nullptr, ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoTitleBar)) {

    // Header
    ImVec2 headerPos = ImGui::GetCursorScreenPos();
    ImVec2 headerSize = ImVec2(ImGui::GetWindowWidth(), 40);
    ImDrawList* draw_list = ImGui::GetWindowDrawList();
    draw_list->AddRectFilled(headerPos, ImVec2(headerPos.x + headerSize.x, headerPos.y + headerSize.y), IM_COL32(50, 50, 50, 255), 6.0f);
    draw_list->AddText(ImVec2(headerPos.x + 10, headerPos.y + 10), IM_COL32(255, 255, 255, 255), "TRENDRAFT X MOD V5 PLUS EDITION");

    // ปุ่ม X
    ImGui::SetCursorScreenPos(ImVec2(headerPos.x + headerSize.x - 40, headerPos.y + 5));
    ImGui::PushStyleColor(ImGuiCol_Button, IM_COL32(180, 50, 50, 255));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, IM_COL32(200, 70, 70, 255));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, IM_COL32(160, 40, 40, 255));
    if (ImGui::Button("X", ImVec2(30, 30))) {
        Notification("Hide menu!", "เมนูกำลังซ่อนอยู่", 
                     ImVec4(180.0f/255.0f, 2.0f/255.0f, 2.0f/255.0f, 1.0f),
                     ImVec4(1,1,1,1),
                     ImVec4(0,0,0,0.588f),
                     1.0f);
        showMainMenu = false;
    }
    ImGui::PopStyleColor(3);

    // เว้นบรรทัด header
    ImGui::Dummy(ImVec2(0, headerSize.y + 5));

    // Child สำหรับ toggles และเนื้อหา
    ImGui::PushStyleColor(ImGuiCol_Border, IM_COL32(100, 100, 100, 150));  
    ImGui::PushStyleVar(ImGuiStyleVar_ChildBorderSize, 1.0f); 
    ImGui::BeginChild("TextChild#1", ImVec2(0, 0), true);

    // ฟังก์ชัน toggle แบบ custom
    #define TOGGLE_BUTTON(label, varName) \
        ImGui::Text(label); \
        ImGui::SameLine(290); \
        if (varName) { \
            ImGui::PushStyleColor(ImGuiCol_Button, IM_COL32(76, 76, 76, 255)); \
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, IM_COL32(76, 76, 76, 255)); \
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, IM_COL32(76, 76, 76, 255)); \
            ImGui::Button("ON", ImVec2(76, 39)); varName = true; \
            ImGui::PopStyleColor(3); \
        } else { \
            ImGui::PushStyleColor(ImGuiCol_Button, IM_COL32(56, 56, 56, 255)); \
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, IM_COL32(56, 56, 56, 255)); \
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, IM_COL32(56, 56, 56, 255)); \
            ImGui::Button("OFF", ImVec2(76, 39)); varName = false; \
            ImGui::PopStyleColor(3); \
        } \
        if (ImGui::IsItemClicked()) varName = !varName; \
        ImGui::Separator();

    // ส่วนเนื้อหาและ switch
    ImVec2 p; ImVec2 text_size, box_size;
    float padding_x = 500.0f, padding_y = 4.0f;

    auto DrawSection = [&](const char* title) {
        p = ImGui::GetCursorScreenPos();
        text_size = ImGui::CalcTextSize(title);
        box_size = ImVec2(text_size.x + padding_x*2, text_size.y + padding_y*2);
        draw_list->AddRectFilled(ImVec2(p.x - padding_x, p.y - padding_y), ImVec2(p.x + text_size.x + padding_x, p.y + text_size.y + padding_y), IM_COL32(180, 2, 2, 255), 6.0f);
        draw_list->AddText(ImVec2(p.x, p.y), IM_COL32(255, 255, 255, 255), title);
        ImGui::Dummy(box_size);
    };

    DrawSection("    Details");
    ImGui::Text("    YouTube : TRENDRAFT X MOD");
    ImGui::Text("    Welcome to TRENDRAFT X MOD UI");
    ImGui::Text("    FF/ALL 2.117.X");
    ImGui::Text("    SDK : %s", GetABI().c_str());

    DrawSection("    Function");
    MyCustomSwitch(" Enable Function (In game)", &Enable);
    MyCustomSwitch(" Enable Aim", &ActivateAimAllFunction);
    MyCustomSwitch(" Enable Esp", &ActivateEspAllFunction);
    MyCustomSwitch(" Headshot Mode", &HeadshotMode);

    DrawSection("    SliderFloat Setting");
    ImGui::SliderFloat(OBFUSCATE("    Fov"), &Fov_Aim, 0.0f, 1000.0f, "%.0f°", ImGuiSliderFlags_AlwaysClamp | ImGuiSliderFlags_NoInput); 
    ImGui::SliderFloat(OBFUSCATE("    Aim Pos"), &AimPos, 0.1f, 1.3f, "%.1f", ImGuiSliderFlags_AlwaysClamp | ImGuiSliderFlags_NoInput);

    DrawSection("    Info");
    char buf[64];
    sprintf(buf, "    Player Pos: %.2f, %.2f, %.2f", Player_pos.x, Player_pos.y, Player_pos.z);
    ImGui::Text("%s", buf);
    sprintf(buf, "    PlayerTarget Pos: %.2f, %.2f, %.2f", PlayerTarget_pos.x, PlayerTarget_pos.y, PlayerTarget_pos.z);
    ImGui::Text("%s", buf);
    ImGui::Text("    FPS: %.0f", ImGui::GetIO().Framerate);

    ImGui::Spacing();

    static bool initialized = false;
    if (!initialized) {
        Fov_Aim = 1000.0;
        Aimbot = true;  
        AimWhen2 = true;  
        Notification("TRENDRAFT X MOD!", "Hack is working", 
                     ImVec4(180.0f/255.0f, 2.0f/255.0f, 2.0f/255.0f, 1.0f), 
                     ImVec4(1,1,1,1), 
                     ImVec4(0,0,0,0.588f), 
                     1.0f);
        initialized = true;
    }

    RenderNotifications(1.0f/60.0f);

    ImGui::EndChild();
}
ImGui::End();

}

ImGui::EndFrame();
ImGui::Render();
ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

return old_eglSwapBuffers(dpy, surface);

typedef unsigned long DWORD;
static uintptr_t libBase;

uintptr_t string2Offset(const char *c) {
    int base = 16;
    // See if this function catches all possibilities.
    // If it doesn't, the function would have to be amended
    // whenever you add a combination of architecture and
    // compiler that is not yet addressed.
    static_assert(sizeof(uintptr_t) == sizeof(unsigned long)
                  || sizeof(uintptr_t) == sizeof(unsigned long long),
                  "Please add string to handle conversion for this architecture.");

    // Now choose the correct function ...
    if (sizeof(uintptr_t) == sizeof(unsigned long)) {
        return strtoul(c, nullptr, base);
    }

    // All other options exhausted, sizeof(uintptr_t) == sizeof(unsigned long long))
    return strtoull(c, nullptr, base);
}


inline void hack_injec();
inline void StartGUI() {
    void *ptr_eglSwapBuffer = DobbySymbolResolver("/system/lib/libEGL.so", "eglSwapBuffers");
    if (NULL != ptr_eglSwapBuffer) {
        DobbyHook((void *)ptr_eglSwapBuffer, (void*)hook_eglSwapBuffers, (void**)&old_eglSwapBuffers);
            LOGD("Gui Started");
			hack_injec();
        }
    }

bool libLoaded = false;

DWORD findLibrary(const char *library) {
    char filename[0xFF] = {0},
            buffer[1024] = {0};
    FILE *fp = NULL;
    DWORD address = 0;

    sprintf(filename, OBFUSCATE("/proc/self/maps"));

    fp = fopen(filename, OBFUSCATE("rt"));
    if (fp == NULL) {
        perror(OBFUSCATE("fopen"));
        goto done;
    }

    while (fgets(buffer, sizeof(buffer), fp)) {
        if (strstr(buffer, library)) {
            address = (DWORD) strtoul(buffer, NULL, 16);
            goto done;
        }
    }

    done:

    if (fp) {
        fclose(fp);
    }

    return address;
}

DWORD getAbsoluteAddress(const char *libraryName, DWORD relativeAddr) {
    libBase = findLibrary(libraryName);
    if (libBase == 0)
        return 0;
    return (reinterpret_cast<DWORD>(libBase + relativeAddr));
}
ProcMap unityMap, anogsMap, il2cppMap;
using KittyScanner::RegisterNativeFn;



    
    
void hack() {
     LOGD("Inject Ok");
    //std::thread thread_hack(hack_thread, getpid());
    //thread_hack.detach();
    
}
uintptr_t get_symbol_addr_in_pid(pid_t pid, const char* libname, uintptr_t offset_in_lib) {
    char maps_path[64];
    snprintf(maps_path, sizeof(maps_path), "/proc/%d/maps", pid);

    FILE* fp = fopen(maps_path, "r");
    if (!fp) return 0;

    char line[512];
    uintptr_t base = 0;

    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, libname)) {
            sscanf(line, "%lx-%*lx", &base);
            break;
        }
    }
    fclose(fp);

    if (base == 0) return 0;
    return base + offset_in_lib;
}

pid_t get_pid_by_name(const char* process_name) {
    DIR* proc_dir = opendir("/proc");
    if (!proc_dir) return -1;

    struct dirent* entry;
    while ((entry = readdir(proc_dir)) != NULL) {
        if (entry->d_type != DT_DIR) continue;

        pid_t pid = atoi(entry->d_name);
        if (pid <= 0) continue;

        char cmdline_path[256];
        snprintf(cmdline_path, sizeof(cmdline_path), "/proc/%d/cmdline", pid);

        FILE* fp = fopen(cmdline_path, "r");
        if (!fp) continue;

        char cmdline[256];
        fgets(cmdline, sizeof(cmdline), fp);
        fclose(fp);

        if (strstr(cmdline, process_name)) {
            closedir(proc_dir);
            return pid;
        }
    }

    closedir(proc_dir);
    return -1;
}

void writeLog(const std::string& logMessage, const std::string& filename) {
    std::ofstream outFile(filename, std::ios::app); // Mở file ở chế độ append (thêm)
    if (outFile.is_open()) {
        outFile << logMessage << std::endl;
        outFile.close();
    } else {
        std::cerr << "Không thể mở file log: " << filename << std::endl;
    }
}

bool is_current_process(const char* target_name) {
    char cmdline_path[64];
    snprintf(cmdline_path, sizeof(cmdline_path), "/proc/%d/cmdline", getpid());

    FILE* fp = fopen(cmdline_path, "r");
    if (!fp) return false;

    char cmdline[256] = {0};
    fgets(cmdline, sizeof(cmdline), fp);
    fclose(fp);

    return strcmp(cmdline, target_name) == 0;
}




void hack_injec() {
	while (!unityMap.isValid()) {
        unityMap = KittyMemory::getLibraryBaseMap("libunity.so");
		anogsMap = KittyMemory::getLibraryBaseMap("libanogs.so");
		il2cppMap = KittyMemory::getLibraryBaseMap("libil2cpp.so");
		
        sleep(6);
	}
    
 sleep(5);
    Il2CppAttach();

A64HookFunction(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("COW.GamePlay"), OBFUSCATE("Player"), OBFUSCATE("UpdateBehavior"), 2), (void *) _LateUpdate, (void **) &LateUpdate);
   	
OpenURL = (void (*)(String *))Il2CppGetMethodOffset("UnityEngine.CoreModule.dll","UnityEngine","Application","OpenURL",1);

    ImGuiOK = true;
    Notification("Load Library", "libil2cpp.so had Load!", ImVec4(180.0f/255.0f, 2.0f/255.0f, 2.0f/255.0f, 1.0f), ImVec4(1,1,1,1), ImVec4(0,0,0,0.588f), 1.0f);
}
void hack_thread(pid_t pid) {
	
	StartGUI();
	while(pid == -1){pid = get_pid_by_name("com.dts.freefireth");} 
	remote_inject(pid);
	writeLog(to_string(pid));
    
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void * reserved) {
jvm = vm;
JNIEnv *env;
vm->GetEnv((void **) &env, JNI_VERSION_1_6); 
return JNI_VERSION_1_6;
}

__attribute__((constructor))
void lib_main()
{
    std::thread thread_hack(hack_thread, get_pid_by_name("com.dts.freefireth"));
    thread_hack.detach();
}

// =============================== [ระบบซ่อนเมนู] ===============================//
void DrawMenu() {
    if (isHidden) return; // ถ้าซ่อนอยู่ ก็ไม่วาดเมนูเลย

    // ====== เรียกเมนูหลักตรงนี้ ======
    // ตัวอย่าง:
    if (ImGui::Begin("Main Menu")) {
        ImGui::Text("เมนูหลักแสดงอยู่ค้าบ 😎");
        ImGui::End();
    }
}
