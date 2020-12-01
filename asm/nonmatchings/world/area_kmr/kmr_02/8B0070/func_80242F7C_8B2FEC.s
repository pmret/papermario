.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242F7C_8B2FEC
/* 8B2FEC 80242F7C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8B2FF0 80242F80 AFB10014 */  sw        $s1, 0x14($sp)
/* 8B2FF4 80242F84 0080882D */  daddu     $s1, $a0, $zero
/* 8B2FF8 80242F88 AFBF0018 */  sw        $ra, 0x18($sp)
/* 8B2FFC 80242F8C 10A0000B */  beqz      $a1, .L80242FBC
/* 8B3000 80242F90 AFB00010 */   sw       $s0, 0x10($sp)
/* 8B3004 80242F94 8E24014C */  lw        $a0, 0x14c($s1)
/* 8B3008 80242F98 0C00EAD2 */  jal       get_npc_safe
/* 8B300C 80242F9C AE200074 */   sw       $zero, 0x74($s1)
/* 8B3010 80242FA0 8E23014C */  lw        $v1, 0x14c($s1)
/* 8B3014 80242FA4 AE220078 */  sw        $v0, 0x78($s1)
/* 8B3018 80242FA8 00031840 */  sll       $v1, $v1, 1
/* 8B301C 80242FAC 3C028025 */  lui       $v0, %hi(D_8024E538)
/* 8B3020 80242FB0 00431021 */  addu      $v0, $v0, $v1
/* 8B3024 80242FB4 8442E538 */  lh        $v0, %lo(D_8024E538)($v0)
/* 8B3028 80242FB8 AE22007C */  sw        $v0, 0x7c($s1)
.L80242FBC:
/* 8B302C 80242FBC 8E22007C */  lw        $v0, 0x7c($s1)
/* 8B3030 80242FC0 14400015 */  bnez      $v0, .L80243018
/* 8B3034 80242FC4 2442FFFF */   addiu    $v0, $v0, -1
/* 8B3038 80242FC8 C62C0074 */  lwc1      $f12, 0x74($s1)
/* 8B303C 80242FCC 0C00A8BB */  jal       sin_deg
/* 8B3040 80242FD0 8E300078 */   lw       $s0, 0x78($s1)
/* 8B3044 80242FD4 3C013FC0 */  lui       $at, 0x3fc0
/* 8B3048 80242FD8 44811000 */  mtc1      $at, $f2
/* 8B304C 80242FDC 00000000 */  nop       
/* 8B3050 80242FE0 46020002 */  mul.s     $f0, $f0, $f2
/* 8B3054 80242FE4 00000000 */  nop       
/* 8B3058 80242FE8 3C014190 */  lui       $at, 0x4190
/* 8B305C 80242FEC 44816000 */  mtc1      $at, $f12
/* 8B3060 80242FF0 4600010D */  trunc.w.s $f4, $f0
/* 8B3064 80242FF4 44022000 */  mfc1      $v0, $f4
/* 8B3068 80242FF8 00000000 */  nop       
/* 8B306C 80242FFC A20200AB */  sb        $v0, 0xab($s0)
/* 8B3070 80243000 C6200074 */  lwc1      $f0, 0x74($s1)
/* 8B3074 80243004 0C00A6C9 */  jal       clamp_angle
/* 8B3078 80243008 460C0300 */   add.s    $f12, $f0, $f12
/* 8B307C 8024300C 0000102D */  daddu     $v0, $zero, $zero
/* 8B3080 80243010 08090C08 */  j         .L80243020
/* 8B3084 80243014 E6200074 */   swc1     $f0, 0x74($s1)
.L80243018:
/* 8B3088 80243018 AE22007C */  sw        $v0, 0x7c($s1)
/* 8B308C 8024301C 0000102D */  daddu     $v0, $zero, $zero
.L80243020:
/* 8B3090 80243020 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8B3094 80243024 8FB10014 */  lw        $s1, 0x14($sp)
/* 8B3098 80243028 8FB00010 */  lw        $s0, 0x10($sp)
/* 8B309C 8024302C 03E00008 */  jr        $ra
/* 8B30A0 80243030 27BD0020 */   addiu    $sp, $sp, 0x20
