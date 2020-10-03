.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel clear_script_list
/* E7B8C 802C31DC 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* E7B90 802C31E0 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* E7B94 802C31E4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E7B98 802C31E8 AFBF0010 */  sw        $ra, 0x10($sp)
/* E7B9C 802C31EC 80420070 */  lb        $v0, 0x70($v0)
/* E7BA0 802C31F0 1440000D */  bnez      $v0, .L802C3228
/* E7BA4 802C31F4 00000000 */   nop      
/* E7BA8 802C31F8 3C02802E */  lui       $v0, %hi(gWorldScriptList)
/* E7BAC 802C31FC 2442A490 */  addiu     $v0, $v0, %lo(gWorldScriptList)
/* E7BB0 802C3200 3C01802E */  lui       $at, %hi(gCurrentScriptListPtr)
/* E7BB4 802C3204 AC22A890 */  sw        $v0, %lo(gCurrentScriptListPtr)($at)
/* E7BB8 802C3208 3C02802E */  lui       $v0, 0x802e
/* E7BBC 802C320C 2442BCA8 */  addiu     $v0, $v0, -0x4358
/* E7BC0 802C3210 3C01802E */  lui       $at, %hi(gMapVars)
/* E7BC4 802C3214 AC22A484 */  sw        $v0, %lo(gMapVars)($at)
/* E7BC8 802C3218 3C02802E */  lui       $v0, 0x802e
/* E7BCC 802C321C 2442BC70 */  addiu     $v0, $v0, -0x4390
/* E7BD0 802C3220 080B0C94 */  j         .L802C3250
/* E7BD4 802C3224 00000000 */   nop      
.L802C3228:
/* E7BD8 802C3228 3C02802E */  lui       $v0, %hi(gBattleScriptList)
/* E7BDC 802C322C 2442A690 */  addiu     $v0, $v0, %lo(gBattleScriptList)
/* E7BE0 802C3230 3C01802E */  lui       $at, %hi(gCurrentScriptListPtr)
/* E7BE4 802C3234 AC22A890 */  sw        $v0, %lo(gCurrentScriptListPtr)($at)
/* E7BE8 802C3238 3C02802E */  lui       $v0, 0x802e
/* E7BEC 802C323C 2442BCE8 */  addiu     $v0, $v0, -0x4318
/* E7BF0 802C3240 3C01802E */  lui       $at, %hi(gMapVars)
/* E7BF4 802C3244 AC22A484 */  sw        $v0, %lo(gMapVars)($at)
/* E7BF8 802C3248 3C02802E */  lui       $v0, 0x802e
/* E7BFC 802C324C 2442BD34 */  addiu     $v0, $v0, -0x42cc
.L802C3250:
/* E7C00 802C3250 3C01802E */  lui       $at, %hi(gMapFlags)
/* E7C04 802C3254 AC22A480 */  sw        $v0, %lo(gMapFlags)($at)
/* E7C08 802C3258 3C02802E */  lui       $v0, %hi(gCurrentScriptListPtr)
/* E7C0C 802C325C 8C42A890 */  lw        $v0, %lo(gCurrentScriptListPtr)($v0)
/* E7C10 802C3260 2403007F */  addiu     $v1, $zero, 0x7f
/* E7C14 802C3264 244201FC */  addiu     $v0, $v0, 0x1fc
.L802C3268:
/* E7C18 802C3268 AC400000 */  sw        $zero, ($v0)
/* E7C1C 802C326C 2463FFFF */  addiu     $v1, $v1, -1
/* E7C20 802C3270 0461FFFD */  bgez      $v1, .L802C3268
/* E7C24 802C3274 2442FFFC */   addiu    $v0, $v0, -4
/* E7C28 802C3278 3C02802E */  lui       $v0, %hi(gMapVars)
/* E7C2C 802C327C 8C42A484 */  lw        $v0, %lo(gMapVars)($v0)
/* E7C30 802C3280 2403000F */  addiu     $v1, $zero, 0xf
/* E7C34 802C3284 3C01802E */  lui       $at, %hi(gNumScripts)
/* E7C38 802C3288 AC20A488 */  sw        $zero, %lo(gNumScripts)($at)
/* E7C3C 802C328C 3C01802E */  lui       $at, %hi(gScriptListCount)
/* E7C40 802C3290 AC20AC98 */  sw        $zero, %lo(gScriptListCount)($at)
/* E7C44 802C3294 3C01802E */  lui       $at, %hi(D_802D9CA4)
/* E7C48 802C3298 AC209CA4 */  sw        $zero, %lo(D_802D9CA4)($at)
/* E7C4C 802C329C 2442003C */  addiu     $v0, $v0, 0x3c
.L802C32A0:
/* E7C50 802C32A0 AC400000 */  sw        $zero, ($v0)
/* E7C54 802C32A4 2463FFFF */  addiu     $v1, $v1, -1
/* E7C58 802C32A8 0461FFFD */  bgez      $v1, .L802C32A0
/* E7C5C 802C32AC 2442FFFC */   addiu    $v0, $v0, -4
/* E7C60 802C32B0 3C02802E */  lui       $v0, %hi(gMapFlags)
/* E7C64 802C32B4 8C42A480 */  lw        $v0, %lo(gMapFlags)($v0)
/* E7C68 802C32B8 24030002 */  addiu     $v1, $zero, 2
/* E7C6C 802C32BC 24420008 */  addiu     $v0, $v0, 8
.L802C32C0:
/* E7C70 802C32C0 AC400000 */  sw        $zero, ($v0)
/* E7C74 802C32C4 2463FFFF */  addiu     $v1, $v1, -1
/* E7C78 802C32C8 0461FFFD */  bgez      $v1, .L802C32C0
/* E7C7C 802C32CC 2442FFFC */   addiu    $v0, $v0, -4
/* E7C80 802C32D0 0C0B5122 */  jal       func_802D4488
/* E7C84 802C32D4 00000000 */   nop      
/* E7C88 802C32D8 0C0B352D */  jal       func_802CD4B4
/* E7C8C 802C32DC 00000000 */   nop      
/* E7C90 802C32E0 8FBF0010 */  lw        $ra, 0x10($sp)
/* E7C94 802C32E4 03E00008 */  jr        $ra
/* E7C98 802C32E8 27BD0018 */   addiu    $sp, $sp, 0x18
