.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_802AB970
.word L802A44D0_419260, L802A4528_4192B8, L802A44D0_419260, L802A4528_4192B8, L802A4528_4192B8, L802A4528_4192B8, L802A4528_4192B8, L802A4528_4192B8, L802A4528_4192B8, L802A4528_4192B8, L802A4528_4192B8, L802A44D0_419260, L802A4528_4192B8, L802A4528_4192B8, L802A4528_4192B8, L802A4528_4192B8, L802A4528_4192B8, L802A4528_4192B8, L802A4528_4192B8, L802A4528_4192B8, L802A4528_4192B8, L802A44D0_419260, L802A4528_4192B8, L802A4528_4192B8, L802A4528_4192B8, L802A4528_4192B8, L802A4528_4192B8, L802A4528_4192B8, L802A4528_4192B8, L802A4528_4192B8, L802A4528_4192B8, L802A44D0_419260

.section .text

glabel func_802A4494
/* 419224 802A4494 3C02802B */  lui       $v0, %hi(battle_menu_moveState)
/* 419228 802A4498 9042D108 */  lbu       $v0, %lo(battle_menu_moveState)($v0)
/* 41922C 802A449C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 419230 802A44A0 24420001 */  addiu     $v0, $v0, 1
/* 419234 802A44A4 00021600 */  sll       $v0, $v0, 0x18
/* 419238 802A44A8 00021E03 */  sra       $v1, $v0, 0x18
/* 41923C 802A44AC 2C620020 */  sltiu     $v0, $v1, 0x20
/* 419240 802A44B0 1040001D */  beqz      $v0, L802A4528_4192B8
/* 419244 802A44B4 AFBF0018 */   sw       $ra, 0x18($sp)
/* 419248 802A44B8 00031080 */  sll       $v0, $v1, 2
/* 41924C 802A44BC 3C01802B */  lui       $at, %hi(jtbl_802AB970)
/* 419250 802A44C0 00220821 */  addu      $at, $at, $v0
/* 419254 802A44C4 8C22B970 */  lw        $v0, %lo(jtbl_802AB970)($at)
/* 419258 802A44C8 00400008 */  jr        $v0
/* 41925C 802A44CC 00000000 */   nop
glabel L802A44D0_419260
/* 419260 802A44D0 3C02802B */  lui       $v0, %hi(D_802AD10F)
/* 419264 802A44D4 8042D10F */  lb        $v0, %lo(D_802AD10F)($v0)
/* 419268 802A44D8 10400013 */  beqz      $v0, L802A4528_4192B8
/* 41926C 802A44DC 00000000 */   nop
/* 419270 802A44E0 3C02802B */  lui       $v0, %hi(battle_menu_moveCursorPos)
/* 419274 802A44E4 8042D109 */  lb        $v0, %lo(battle_menu_moveCursorPos)($v0)
/* 419278 802A44E8 3C03802B */  lui       $v1, %hi(battle_menu_moveTextColor)
/* 41927C 802A44EC 8463D114 */  lh        $v1, %lo(battle_menu_moveTextColor)($v1)
/* 419280 802A44F0 3C07802B */  lui       $a3, %hi(battle_menu_moveTextOpacity)
/* 419284 802A44F4 84E7D116 */  lh        $a3, %lo(battle_menu_moveTextOpacity)($a3)
/* 419288 802A44F8 00021080 */  sll       $v0, $v0, 2
/* 41928C 802A44FC 3C01802B */  lui       $at, %hi(battle_menu_moveOptionIndexMap)
/* 419290 802A4500 00220821 */  addu      $at, $at, $v0
/* 419294 802A4504 8C22D1F8 */  lw        $v0, %lo(battle_menu_moveOptionIndexMap)($at)
/* 419298 802A4508 AFA30010 */  sw        $v1, 0x10($sp)
/* 41929C 802A450C AFA00014 */  sw        $zero, 0x14($sp)
/* 4192A0 802A4510 00021080 */  sll       $v0, $v0, 2
/* 4192A4 802A4514 3C04802B */  lui       $a0, %hi(battle_menu_moveOptionDescriptions)
/* 4192A8 802A4518 00822021 */  addu      $a0, $a0, $v0
/* 4192AC 802A451C 8C84D570 */  lw        $a0, %lo(battle_menu_moveOptionDescriptions)($a0)
/* 4192B0 802A4520 0C04993B */  jal       draw_string
/* 4192B4 802A4524 24A50008 */   addiu    $a1, $a1, 8
glabel L802A4528_4192B8
/* 4192B8 802A4528 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4192BC 802A452C 03E00008 */  jr        $ra
/* 4192C0 802A4530 27BD0020 */   addiu    $sp, $sp, 0x20
