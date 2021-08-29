.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021C9D4_6A3BD4
/* 6A3BD4 8021C9D4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6A3BD8 8021C9D8 3C038011 */  lui       $v1, %hi(gPlayerData)
/* 6A3BDC 8021C9DC 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* 6A3BE0 8021C9E0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 6A3BE4 8021C9E4 80620002 */  lb        $v0, 2($v1)
/* 6A3BE8 8021C9E8 00023040 */  sll       $a2, $v0, 1
/* 6A3BEC 8021C9EC 00C23021 */  addu      $a2, $a2, $v0
/* 6A3BF0 8021C9F0 000630C0 */  sll       $a2, $a2, 3
/* 6A3BF4 8021C9F4 00C23021 */  addu      $a2, $a2, $v0
/* 6A3BF8 8021C9F8 80620003 */  lb        $v0, 3($v1)
/* 6A3BFC 8021C9FC 00063080 */  sll       $a2, $a2, 2
/* 6A3C00 8021CA00 14400002 */  bnez      $v0, .L8021CA0C
/* 6A3C04 8021CA04 00C2001A */   div      $zero, $a2, $v0
/* 6A3C08 8021CA08 0007000D */  break     7
.L8021CA0C:
/* 6A3C0C 8021CA0C 2401FFFF */   addiu    $at, $zero, -1
/* 6A3C10 8021CA10 14410004 */  bne       $v0, $at, .L8021CA24
/* 6A3C14 8021CA14 3C018000 */   lui      $at, 0x8000
/* 6A3C18 8021CA18 14C10002 */  bne       $a2, $at, .L8021CA24
/* 6A3C1C 8021CA1C 00000000 */   nop
/* 6A3C20 8021CA20 0006000D */  break     6
.L8021CA24:
/* 6A3C24 8021CA24 00003012 */   mflo     $a2
/* 6A3C28 8021CA28 8C82000C */  lw        $v0, 0xc($a0)
/* 6A3C2C 8021CA2C 0C0B2026 */  jal       evt_set_variable
/* 6A3C30 8021CA30 8C450000 */   lw       $a1, ($v0)
/* 6A3C34 8021CA34 8FBF0010 */  lw        $ra, 0x10($sp)
/* 6A3C38 8021CA38 24020002 */  addiu     $v0, $zero, 2
/* 6A3C3C 8021CA3C 03E00008 */  jr        $ra
/* 6A3C40 8021CA40 27BD0018 */   addiu    $sp, $sp, 0x18
