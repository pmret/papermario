.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80117C94
/* 0AE394 80117C94 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0AE398 80117C98 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0AE39C 80117C9C 94820002 */  lhu   $v0, 2($a0)
/* 0AE3A0 80117CA0 3C05800A */  lui   $a1, 0x800a
/* 0AE3A4 80117CA4 8CA5A5F4 */  lw    $a1, -0x5a0c($a1)
/* 0AE3A8 80117CA8 2443FFFF */  addiu $v1, $v0, -1
/* 0AE3AC 80117CAC 00021080 */  sll   $v0, $v0, 2
/* 0AE3B0 80117CB0 00451021 */  addu  $v0, $v0, $a1
/* 0AE3B4 80117CB4 90460001 */  lbu   $a2, 1($v0)
/* 0AE3B8 80117CB8 04600009 */  bltz  $v1, .L80117CE0
/* 0AE3BC 80117CBC 00031080 */   sll   $v0, $v1, 2
/* 0AE3C0 80117CC0 00452821 */  addu  $a1, $v0, $a1
.L80117CC4:
/* 0AE3C4 80117CC4 90A20001 */  lbu   $v0, 1($a1)
/* 0AE3C8 80117CC8 00C2102A */  slt   $v0, $a2, $v0
/* 0AE3CC 80117CCC 10400005 */  beqz  $v0, .L80117CE4
/* 0AE3D0 80117CD0 24620001 */   addiu $v0, $v1, 1
/* 0AE3D4 80117CD4 2463FFFF */  addiu $v1, $v1, -1
/* 0AE3D8 80117CD8 0461FFFA */  bgez  $v1, .L80117CC4
/* 0AE3DC 80117CDC 24A5FFFC */   addiu $a1, $a1, -4
.L80117CE0:
/* 0AE3E0 80117CE0 24620001 */  addiu $v0, $v1, 1
.L80117CE4:
/* 0AE3E4 80117CE4 3C018015 */  lui   $at, 0x8015
/* 0AE3E8 80117CE8 AC223224 */  sw    $v0, 0x3224($at)
/* 0AE3EC 80117CEC 0C045F40 */  jal   func_80117D00
/* 0AE3F0 80117CF0 00000000 */   nop   
/* 0AE3F4 80117CF4 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0AE3F8 80117CF8 03E00008 */  jr    $ra
/* 0AE3FC 80117CFC 27BD0018 */   addiu $sp, $sp, 0x18

