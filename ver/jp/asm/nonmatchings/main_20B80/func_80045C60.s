.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80045C60
/* 21060 80045C60 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 21064 80045C64 AFBF0014 */  sw        $ra, 0x14($sp)
/* 21068 80045C68 0C011652 */  jal       func_80045948
/* 2106C 80045C6C AFB00010 */   sw       $s0, 0x10($sp)
/* 21070 80045C70 0040802D */  daddu     $s0, $v0, $zero
/* 21074 80045C74 12000015 */  beqz      $s0, .L80045CCC
/* 21078 80045C78 24042C00 */   addiu    $a0, $zero, 0x2c00
/* 2107C 80045C7C 3C028004 */  lui       $v0, %hi(func_80045CDC)
/* 21080 80045C80 24425CDC */  addiu     $v0, $v0, %lo(func_80045CDC)
/* 21084 80045C84 AE020004 */  sw        $v0, 4($s0)
/* 21088 80045C88 3C028004 */  lui       $v0, %hi(func_8004628C)
/* 2108C 80045C8C 2442628C */  addiu     $v0, $v0, %lo(func_8004628C)
/* 21090 80045C90 AE000000 */  sw        $zero, ($s0)
/* 21094 80045C94 AE000008 */  sw        $zero, 8($s0)
/* 21098 80045C98 0C00AAFA */  jal       func_8002ABE8
/* 2109C 80045C9C AE02000C */   sw       $v0, 0xc($s0)
/* 210A0 80045CA0 AE020018 */  sw        $v0, 0x18($s0)
/* 210A4 80045CA4 3C01800A */  lui       $at, %hi(D_8009ED54)
/* 210A8 80045CA8 AC22ED54 */  sw        $v0, %lo(D_8009ED54)($at)
/* 210AC 80045CAC 14400003 */  bnez      $v0, .L80045CBC
/* 210B0 80045CB0 2403003F */   addiu    $v1, $zero, 0x3f
.L80045CB4:
/* 210B4 80045CB4 0801172D */  j         .L80045CB4
/* 210B8 80045CB8 00000000 */   nop
.L80045CBC:
/* 210BC 80045CBC AC400000 */  sw        $zero, ($v0)
/* 210C0 80045CC0 2463FFFF */  addiu     $v1, $v1, -1
/* 210C4 80045CC4 0461FFFD */  bgez      $v1, .L80045CBC
/* 210C8 80045CC8 244200B0 */   addiu    $v0, $v0, 0xb0
.L80045CCC:
/* 210CC 80045CCC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 210D0 80045CD0 8FB00010 */  lw        $s0, 0x10($sp)
/* 210D4 80045CD4 03E00008 */  jr        $ra
/* 210D8 80045CD8 27BD0018 */   addiu    $sp, $sp, 0x18
