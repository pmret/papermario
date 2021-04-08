.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80047E4C
/* 2324C 80047E4C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 23250 80047E50 00041040 */  sll       $v0, $a0, 1
/* 23254 80047E54 00441021 */  addu      $v0, $v0, $a0
/* 23258 80047E58 00021080 */  sll       $v0, $v0, 2
/* 2325C 80047E5C 00441023 */  subu      $v0, $v0, $a0
/* 23260 80047E60 3C03800A */  lui       $v1, %hi(D_800A0F44)
/* 23264 80047E64 8C630F44 */  lw        $v1, %lo(D_800A0F44)($v1)
/* 23268 80047E68 00021100 */  sll       $v0, $v0, 4
/* 2326C 80047E6C AFBF0018 */  sw        $ra, 0x18($sp)
/* 23270 80047E70 AFB10014 */  sw        $s1, 0x14($sp)
/* 23274 80047E74 AFB00010 */  sw        $s0, 0x10($sp)
/* 23278 80047E78 00628821 */  addu      $s1, $v1, $v0
/* 2327C 80047E7C 2403FEFF */  addiu     $v1, $zero, -0x101
/* 23280 80047E80 8E220000 */  lw        $v0, ($s1)
/* 23284 80047E84 82240090 */  lb        $a0, 0x90($s1)
/* 23288 80047E88 00431024 */  and       $v0, $v0, $v1
/* 2328C 80047E8C 1480000E */  bnez      $a0, .L80047EC8
/* 23290 80047E90 AE220000 */   sw       $v0, ($s1)
/* 23294 80047E94 3C048010 */  lui       $a0, %hi(D_801075E0)
/* 23298 80047E98 248475E0 */  addiu     $a0, $a0, %lo(D_801075E0)
/* 2329C 80047E9C 24020001 */  addiu     $v0, $zero, 1
/* 232A0 80047EA0 0C050529 */  jal       create_icon
/* 232A4 80047EA4 A2220090 */   sb       $v0, 0x90($s1)
/* 232A8 80047EA8 0040802D */  daddu     $s0, $v0, $zero
/* 232AC 80047EAC 0200202D */  daddu     $a0, $s0, $zero
/* 232B0 80047EB0 0C051280 */  jal       set_icon_flags
/* 232B4 80047EB4 24050002 */   addiu    $a1, $zero, 2
/* 232B8 80047EB8 0200202D */  daddu     $a0, $s0, $zero
/* 232BC 80047EBC 0C051280 */  jal       set_icon_flags
/* 232C0 80047EC0 24050080 */   addiu    $a1, $zero, 0x80
/* 232C4 80047EC4 AE300094 */  sw        $s0, 0x94($s1)
.L80047EC8:
/* 232C8 80047EC8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 232CC 80047ECC 8FB10014 */  lw        $s1, 0x14($sp)
/* 232D0 80047ED0 8FB00010 */  lw        $s0, 0x10($sp)
/* 232D4 80047ED4 03E00008 */  jr        $ra
/* 232D8 80047ED8 27BD0020 */   addiu    $sp, $sp, 0x20
