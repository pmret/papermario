.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802691C8
/* 197AA8 802691C8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 197AAC 802691CC AFB20018 */  sw        $s2, 0x18($sp)
/* 197AB0 802691D0 0080902D */  daddu     $s2, $a0, $zero
/* 197AB4 802691D4 AFBF001C */  sw        $ra, 0x1c($sp)
/* 197AB8 802691D8 AFB10014 */  sw        $s1, 0x14($sp)
/* 197ABC 802691DC AFB00010 */  sw        $s0, 0x10($sp)
/* 197AC0 802691E0 8E50000C */  lw        $s0, 0xc($s2)
/* 197AC4 802691E4 8E050000 */  lw        $a1, ($s0)
/* 197AC8 802691E8 0C0B1EAF */  jal       get_variable
/* 197ACC 802691EC 26100004 */   addiu    $s0, $s0, 4
/* 197AD0 802691F0 3C11802A */  lui       $s1, %hi(D_8029FBE0)
/* 197AD4 802691F4 2631FBE0 */  addiu     $s1, $s1, %lo(D_8029FBE0)
/* 197AD8 802691F8 A2220080 */  sb        $v0, 0x80($s1)
/* 197ADC 802691FC 8E050000 */  lw        $a1, ($s0)
/* 197AE0 80269200 26100004 */  addiu     $s0, $s0, 4
/* 197AE4 80269204 0C0B1EAF */  jal       get_variable
/* 197AE8 80269208 0240202D */   daddu    $a0, $s2, $zero
/* 197AEC 8026920C A6220076 */  sh        $v0, 0x76($s1)
/* 197AF0 80269210 8E050000 */  lw        $a1, ($s0)
/* 197AF4 80269214 26100004 */  addiu     $s0, $s0, 4
/* 197AF8 80269218 0C0B1EAF */  jal       get_variable
/* 197AFC 8026921C 0240202D */   daddu    $a0, $s2, $zero
/* 197B00 80269220 A6220078 */  sh        $v0, 0x78($s1)
/* 197B04 80269224 8E050000 */  lw        $a1, ($s0)
/* 197B08 80269228 26100004 */  addiu     $s0, $s0, 4
/* 197B0C 8026922C 0C0B1EAF */  jal       get_variable
/* 197B10 80269230 0240202D */   daddu    $a0, $s2, $zero
/* 197B14 80269234 A622007A */  sh        $v0, 0x7a($s1)
/* 197B18 80269238 8E050000 */  lw        $a1, ($s0)
/* 197B1C 8026923C 26100004 */  addiu     $s0, $s0, 4
/* 197B20 80269240 0C0B1EAF */  jal       get_variable
/* 197B24 80269244 0240202D */   daddu    $a0, $s2, $zero
/* 197B28 80269248 A622007C */  sh        $v0, 0x7c($s1)
/* 197B2C 8026924C 8E050000 */  lw        $a1, ($s0)
/* 197B30 80269250 0C0B1EAF */  jal       get_variable
/* 197B34 80269254 0240202D */   daddu    $a0, $s2, $zero
/* 197B38 80269258 96240076 */  lhu       $a0, 0x76($s1)
/* 197B3C 8026925C A622007E */  sh        $v0, 0x7e($s1)
/* 197B40 80269260 00042400 */  sll       $a0, $a0, 0x10
/* 197B44 80269264 00041C03 */  sra       $v1, $a0, 0x10
/* 197B48 80269268 000427C2 */  srl       $a0, $a0, 0x1f
/* 197B4C 8026926C 00641821 */  addu      $v1, $v1, $a0
/* 197B50 80269270 00031843 */  sra       $v1, $v1, 1
/* 197B54 80269274 A6230074 */  sh        $v1, 0x74($s1)
/* 197B58 80269278 8FBF001C */  lw        $ra, 0x1c($sp)
/* 197B5C 8026927C 8FB20018 */  lw        $s2, 0x18($sp)
/* 197B60 80269280 8FB10014 */  lw        $s1, 0x14($sp)
/* 197B64 80269284 8FB00010 */  lw        $s0, 0x10($sp)
/* 197B68 80269288 24020002 */  addiu     $v0, $zero, 2
/* 197B6C 8026928C 03E00008 */  jr        $ra
/* 197B70 80269290 27BD0020 */   addiu    $sp, $sp, 0x20
