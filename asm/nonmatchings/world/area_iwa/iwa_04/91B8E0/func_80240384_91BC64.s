.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240384_91BC64
/* 91BC64 80240384 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 91BC68 80240388 AFB20018 */  sw        $s2, 0x18($sp)
/* 91BC6C 8024038C 0080902D */  daddu     $s2, $a0, $zero
/* 91BC70 80240390 AFBF001C */  sw        $ra, 0x1c($sp)
/* 91BC74 80240394 AFB10014 */  sw        $s1, 0x14($sp)
/* 91BC78 80240398 AFB00010 */  sw        $s0, 0x10($sp)
/* 91BC7C 8024039C 8E510148 */  lw        $s1, 0x148($s2)
/* 91BC80 802403A0 0C00EABB */  jal       get_npc_unsafe
/* 91BC84 802403A4 86240008 */   lh       $a0, 8($s1)
/* 91BC88 802403A8 0040802D */  daddu     $s0, $v0, $zero
/* 91BC8C 802403AC 9602008E */  lhu       $v0, 0x8e($s0)
/* 91BC90 802403B0 2442FFFF */  addiu     $v0, $v0, -1
/* 91BC94 802403B4 A602008E */  sh        $v0, 0x8e($s0)
/* 91BC98 802403B8 00021400 */  sll       $v0, $v0, 0x10
/* 91BC9C 802403BC 1C400012 */  bgtz      $v0, .L80240408
/* 91BCA0 802403C0 00000000 */   nop      
/* 91BCA4 802403C4 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 91BCA8 802403C8 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 91BCAC 802403CC C60C0038 */  lwc1      $f12, 0x38($s0)
/* 91BCB0 802403D0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 91BCB4 802403D4 8C460028 */  lw        $a2, 0x28($v0)
/* 91BCB8 802403D8 0C00A720 */  jal       atan2
/* 91BCBC 802403DC 8C470030 */   lw       $a3, 0x30($v0)
/* 91BCC0 802403E0 0200202D */  daddu     $a0, $s0, $zero
/* 91BCC4 802403E4 0C00EAE8 */  jal       enable_npc_shadow
/* 91BCC8 802403E8 E600000C */   swc1     $f0, 0xc($s0)
/* 91BCCC 802403EC 8E2200CC */  lw        $v0, 0xcc($s1)
/* 91BCD0 802403F0 8C430028 */  lw        $v1, 0x28($v0)
/* 91BCD4 802403F4 24020008 */  addiu     $v0, $zero, 8
/* 91BCD8 802403F8 A602008E */  sh        $v0, 0x8e($s0)
/* 91BCDC 802403FC 24020003 */  addiu     $v0, $zero, 3
/* 91BCE0 80240400 AE030028 */  sw        $v1, 0x28($s0)
/* 91BCE4 80240404 AE420070 */  sw        $v0, 0x70($s2)
.L80240408:
/* 91BCE8 80240408 8FBF001C */  lw        $ra, 0x1c($sp)
/* 91BCEC 8024040C 8FB20018 */  lw        $s2, 0x18($sp)
/* 91BCF0 80240410 8FB10014 */  lw        $s1, 0x14($sp)
/* 91BCF4 80240414 8FB00010 */  lw        $s0, 0x10($sp)
/* 91BCF8 80240418 03E00008 */  jr        $ra
/* 91BCFC 8024041C 27BD0020 */   addiu    $sp, $sp, 0x20
