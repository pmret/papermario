.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80260DD8
/* 18F6B8 80260DD8 3C028011 */  lui       $v0, 0x8011
/* 18F6BC 80260DDC 8042F29A */  lb        $v0, -0xd66($v0)
/* 18F6C0 80260DE0 3C03800E */  lui       $v1, 0x800e
/* 18F6C4 80260DE4 8C63C148 */  lw        $v1, -0x3eb8($v1)
/* 18F6C8 80260DE8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 18F6CC 80260DEC AFB10014 */  sw        $s1, 0x14($sp)
/* 18F6D0 80260DF0 0080882D */  daddu     $s1, $a0, $zero
/* 18F6D4 80260DF4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 18F6D8 80260DF8 14400009 */  bnez      $v0, .L80260E20
/* 18F6DC 80260DFC AFB00010 */   sw       $s0, 0x10($sp)
/* 18F6E0 80260E00 8C700088 */  lw        $s0, 0x88($v1)
/* 18F6E4 80260E04 0C00A67F */  jal       rand_int
/* 18F6E8 80260E08 24040064 */   addiu    $a0, $zero, 0x64
/* 18F6EC 80260E0C 0202802A */  slt       $s0, $s0, $v0
/* 18F6F0 80260E10 56000003 */  bnel      $s0, $zero, .L80260E20
/* 18F6F4 80260E14 AE200084 */   sw       $zero, 0x84($s1)
/* 18F6F8 80260E18 24020001 */  addiu     $v0, $zero, 1
/* 18F6FC 80260E1C AE220084 */  sw        $v0, 0x84($s1)
.L80260E20:
/* 18F700 80260E20 24020002 */  addiu     $v0, $zero, 2
/* 18F704 80260E24 8FBF0018 */  lw        $ra, 0x18($sp)
/* 18F708 80260E28 8FB10014 */  lw        $s1, 0x14($sp)
/* 18F70C 80260E2C 8FB00010 */  lw        $s0, 0x10($sp)
/* 18F710 80260E30 03E00008 */  jr        $ra
/* 18F714 80260E34 27BD0020 */   addiu    $sp, $sp, 0x20
