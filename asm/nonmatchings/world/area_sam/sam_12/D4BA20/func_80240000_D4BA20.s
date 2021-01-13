.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_D4BA20
/* D4BA20 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D4BA24 80240004 AFB10014 */  sw        $s1, 0x14($sp)
/* D4BA28 80240008 0080882D */  daddu     $s1, $a0, $zero
/* D4BA2C 8024000C AFBF0018 */  sw        $ra, 0x18($sp)
/* D4BA30 80240010 10A00005 */  beqz      $a1, .L80240028
/* D4BA34 80240014 AFB00010 */   sw       $s0, 0x10($sp)
/* D4BA38 80240018 8E24014C */  lw        $a0, 0x14c($s1)
/* D4BA3C 8024001C 0C00EAD2 */  jal       get_npc_safe
/* D4BA40 80240020 AE200074 */   sw       $zero, 0x74($s1)
/* D4BA44 80240024 AE220078 */  sw        $v0, 0x78($s1)
.L80240028:
/* D4BA48 80240028 C62C0074 */  lwc1      $f12, 0x74($s1)
/* D4BA4C 8024002C 0C00A8BB */  jal       sin_deg
/* D4BA50 80240030 8E300078 */   lw       $s0, 0x78($s1)
/* D4BA54 80240034 3C0140A0 */  lui       $at, 0x40a0
/* D4BA58 80240038 44811000 */  mtc1      $at, $f2
/* D4BA5C 8024003C 00000000 */  nop
/* D4BA60 80240040 46020002 */  mul.s     $f0, $f0, $f2
/* D4BA64 80240044 00000000 */  nop
/* D4BA68 80240048 3C014090 */  lui       $at, 0x4090
/* D4BA6C 8024004C 44816000 */  mtc1      $at, $f12
/* D4BA70 80240050 4600010D */  trunc.w.s $f4, $f0
/* D4BA74 80240054 44022000 */  mfc1      $v0, $f4
/* D4BA78 80240058 00000000 */  nop
/* D4BA7C 8024005C A20200AB */  sb        $v0, 0xab($s0)
/* D4BA80 80240060 C6200074 */  lwc1      $f0, 0x74($s1)
/* D4BA84 80240064 0C00A6C9 */  jal       clamp_angle
/* D4BA88 80240068 460C0300 */   add.s    $f12, $f0, $f12
/* D4BA8C 8024006C E6200074 */  swc1      $f0, 0x74($s1)
/* D4BA90 80240070 8FBF0018 */  lw        $ra, 0x18($sp)
/* D4BA94 80240074 8FB10014 */  lw        $s1, 0x14($sp)
/* D4BA98 80240078 8FB00010 */  lw        $s0, 0x10($sp)
/* D4BA9C 8024007C 0000102D */  daddu     $v0, $zero, $zero
/* D4BAA0 80240080 03E00008 */  jr        $ra
/* D4BAA4 80240084 27BD0020 */   addiu    $sp, $sp, 0x20
/* D4BAA8 80240088 00000000 */  nop
/* D4BAAC 8024008C 00000000 */  nop
