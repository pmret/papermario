.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80066FA0
/* 423A0 80066FA0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 423A4 80066FA4 F7B40018 */  sdc1      $f20, 0x18($sp)
/* 423A8 80066FA8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 423AC 80066FAC 0C01ACD0 */  jal       func_8006B340
/* 423B0 80066FB0 46006506 */   mov.s    $f20, $f12
/* 423B4 80066FB4 3C048009 */  lui       $a0, %hi(D_80095964)
/* 423B8 80066FB8 8C845964 */  lw        $a0, %lo(D_80095964)($a0)
/* 423BC 80066FBC 94830000 */  lhu       $v1, ($a0)
/* 423C0 80066FC0 E4940024 */  swc1      $f20, 0x24($a0)
/* 423C4 80066FC4 34630004 */  ori       $v1, $v1, 4
/* 423C8 80066FC8 A4830000 */  sh        $v1, ($a0)
/* 423CC 80066FCC 0C01ACEC */  jal       func_8006B3B0
/* 423D0 80066FD0 00402021 */   addu     $a0, $v0, $zero
/* 423D4 80066FD4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 423D8 80066FD8 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 423DC 80066FDC 03E00008 */  jr        $ra
/* 423E0 80066FE0 27BD0020 */   addiu    $sp, $sp, 0x20
/* 423E4 80066FE4 00000000 */  nop
/* 423E8 80066FE8 00000000 */  nop
/* 423EC 80066FEC 00000000 */  nop
