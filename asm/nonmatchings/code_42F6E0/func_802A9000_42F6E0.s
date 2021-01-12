.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9000_42F6E0
/* 42F6E0 802A9000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 42F6E4 802A9004 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 42F6E8 802A9008 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 42F6EC 802A900C 24020005 */  addiu     $v0, $zero, 5
/* 42F6F0 802A9010 AFBF0018 */  sw        $ra, 0x18($sp)
/* 42F6F4 802A9014 AFB10014 */  sw        $s1, 0x14($sp)
/* 42F6F8 802A9018 AFB00010 */  sw        $s0, 0x10($sp)
/* 42F6FC 802A901C A0620082 */  sb        $v0, 0x82($v1)
/* 42F700 802A9020 3C028029 */  lui       $v0, %hi(D_80294420)
/* 42F704 802A9024 24424420 */  addiu     $v0, $v0, %lo(D_80294420)
/* 42F708 802A9028 AC620434 */  sw        $v0, 0x434($v1)
/* 42F70C 802A902C 80620083 */  lb        $v0, 0x83($v1)
/* 42F710 802A9030 3C11802A */  lui       $s1, %hi(D_8029FBE0)
/* 42F714 802A9034 2631FBE0 */  addiu     $s1, $s1, %lo(D_8029FBE0)
/* 42F718 802A9038 50400053 */  beql      $v0, $zero, .L802A9188
/* 42F71C 802A903C A0600081 */   sb       $zero, 0x81($v1)
/* 42F720 802A9040 0C09A216 */  jal       func_80268858
/* 42F724 802A9044 00000000 */   nop
/* 42F728 802A9048 3C048011 */  lui       $a0, %hi(D_80108B28)
/* 42F72C 802A904C 24848B28 */  addiu     $a0, $a0, %lo(D_80108B28)
/* 42F730 802A9050 24020014 */  addiu     $v0, $zero, 0x14
/* 42F734 802A9054 A622004A */  sh        $v0, 0x4a($s1)
/* 42F738 802A9058 2402001E */  addiu     $v0, $zero, 0x1e
/* 42F73C 802A905C A622006C */  sh        $v0, 0x6c($s1)
/* 42F740 802A9060 2402FFD0 */  addiu     $v0, $zero, -0x30
/* 42F744 802A9064 A6220056 */  sh        $v0, 0x56($s1)
/* 42F748 802A9068 24020050 */  addiu     $v0, $zero, 0x50
/* 42F74C 802A906C A620004C */  sh        $zero, 0x4c($s1)
/* 42F750 802A9070 A2200060 */  sb        $zero, 0x60($s1)
/* 42F754 802A9074 A6200044 */  sh        $zero, 0x44($s1)
/* 42F758 802A9078 A6200048 */  sh        $zero, 0x48($s1)
/* 42F75C 802A907C A6200068 */  sh        $zero, 0x68($s1)
/* 42F760 802A9080 0C050529 */  jal       create_icon
/* 42F764 802A9084 A6220058 */   sh       $v0, 0x58($s1)
/* 42F768 802A9088 0040802D */  daddu     $s0, $v0, $zero
/* 42F76C 802A908C 0200202D */  daddu     $a0, $s0, $zero
/* 42F770 802A9090 24050082 */  addiu     $a1, $zero, 0x82
/* 42F774 802A9094 0C051280 */  jal       set_icon_flags
/* 42F778 802A9098 AE300004 */   sw       $s0, 4($s1)
/* 42F77C 802A909C 86250056 */  lh        $a1, 0x56($s1)
/* 42F780 802A90A0 86260058 */  lh        $a2, 0x58($s1)
/* 42F784 802A90A4 0C051261 */  jal       set_icon_render_pos
/* 42F788 802A90A8 0200202D */   daddu    $a0, $s0, $zero
/* 42F78C 802A90AC 0200202D */  daddu     $a0, $s0, $zero
/* 42F790 802A90B0 0C051277 */  jal       func_801449DC
/* 42F794 802A90B4 0000282D */   daddu    $a1, $zero, $zero
/* 42F798 802A90B8 3C048029 */  lui       $a0, %hi(D_8029231C)
/* 42F79C 802A90BC 2484231C */  addiu     $a0, $a0, %lo(D_8029231C)
/* 42F7A0 802A90C0 0C050529 */  jal       create_icon
/* 42F7A4 802A90C4 00000000 */   nop
/* 42F7A8 802A90C8 0040802D */  daddu     $s0, $v0, $zero
/* 42F7AC 802A90CC 0200202D */  daddu     $a0, $s0, $zero
/* 42F7B0 802A90D0 24050082 */  addiu     $a1, $zero, 0x82
/* 42F7B4 802A90D4 0C051280 */  jal       set_icon_flags
/* 42F7B8 802A90D8 AE30000C */   sw       $s0, 0xc($s1)
/* 42F7BC 802A90DC 86250056 */  lh        $a1, 0x56($s1)
/* 42F7C0 802A90E0 86260058 */  lh        $a2, 0x58($s1)
/* 42F7C4 802A90E4 0C051261 */  jal       set_icon_render_pos
/* 42F7C8 802A90E8 0200202D */   daddu    $a0, $s0, $zero
/* 42F7CC 802A90EC 0200202D */  daddu     $a0, $s0, $zero
/* 42F7D0 802A90F0 0C051277 */  jal       func_801449DC
/* 42F7D4 802A90F4 0000282D */   daddu    $a1, $zero, $zero
/* 42F7D8 802A90F8 3C048011 */  lui       $a0, %hi(D_80108AFC)
/* 42F7DC 802A90FC 24848AFC */  addiu     $a0, $a0, %lo(D_80108AFC)
/* 42F7E0 802A9100 0C050529 */  jal       create_icon
/* 42F7E4 802A9104 00000000 */   nop
/* 42F7E8 802A9108 0040802D */  daddu     $s0, $v0, $zero
/* 42F7EC 802A910C 86250056 */  lh        $a1, 0x56($s1)
/* 42F7F0 802A9110 86260058 */  lh        $a2, 0x58($s1)
/* 42F7F4 802A9114 0200202D */  daddu     $a0, $s0, $zero
/* 42F7F8 802A9118 AE300008 */  sw        $s0, 8($s1)
/* 42F7FC 802A911C 0C051261 */  jal       set_icon_render_pos
/* 42F800 802A9120 24C6001C */   addiu    $a2, $a2, 0x1c
/* 42F804 802A9124 0200202D */  daddu     $a0, $s0, $zero
/* 42F808 802A9128 0C051277 */  jal       func_801449DC
/* 42F80C 802A912C 0000282D */   daddu    $a1, $zero, $zero
/* 42F810 802A9130 0200202D */  daddu     $a0, $s0, $zero
/* 42F814 802A9134 0C051280 */  jal       set_icon_flags
/* 42F818 802A9138 24050082 */   addiu    $a1, $zero, 0x82
/* 42F81C 802A913C 3C048029 */  lui       $a0, %hi(D_80292974)
/* 42F820 802A9140 24842974 */  addiu     $a0, $a0, %lo(D_80292974)
/* 42F824 802A9144 0C050529 */  jal       create_icon
/* 42F828 802A9148 00000000 */   nop
/* 42F82C 802A914C 0040802D */  daddu     $s0, $v0, $zero
/* 42F830 802A9150 86250056 */  lh        $a1, 0x56($s1)
/* 42F834 802A9154 86260058 */  lh        $a2, 0x58($s1)
/* 42F838 802A9158 0200202D */  daddu     $a0, $s0, $zero
/* 42F83C 802A915C AE300014 */  sw        $s0, 0x14($s1)
/* 42F840 802A9160 0C051261 */  jal       set_icon_render_pos
/* 42F844 802A9164 24C6001C */   addiu    $a2, $a2, 0x1c
/* 42F848 802A9168 0200202D */  daddu     $a0, $s0, $zero
/* 42F84C 802A916C 0C051277 */  jal       func_801449DC
/* 42F850 802A9170 0000282D */   daddu    $a1, $zero, $zero
/* 42F854 802A9174 0200202D */  daddu     $a0, $s0, $zero
/* 42F858 802A9178 0C051280 */  jal       set_icon_flags
/* 42F85C 802A917C 24050082 */   addiu    $a1, $zero, 0x82
/* 42F860 802A9180 080AA463 */  j         .L802A918C
/* 42F864 802A9184 24020002 */   addiu    $v0, $zero, 2
.L802A9188:
/* 42F868 802A9188 24020002 */  addiu     $v0, $zero, 2
.L802A918C:
/* 42F86C 802A918C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 42F870 802A9190 8FB10014 */  lw        $s1, 0x14($sp)
/* 42F874 802A9194 8FB00010 */  lw        $s0, 0x10($sp)
/* 42F878 802A9198 03E00008 */  jr        $ra
/* 42F87C 802A919C 27BD0020 */   addiu    $sp, $sp, 0x20
