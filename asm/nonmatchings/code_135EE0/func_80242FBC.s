.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242FBC
/* 1362FC 80242FBC 240200A0 */  addiu     $v0, $zero, 0xa0
/* 136300 80242FC0 8FA30028 */  lw        $v1, 0x28($sp)
/* 136304 80242FC4 8FA5002C */  lw        $a1, 0x2c($sp)
/* 136308 80242FC8 00042140 */  sll       $a0, $a0, 5
/* 13630C 80242FCC AC620000 */  sw        $v0, ($v1)
/* 136310 80242FD0 24020050 */  addiu     $v0, $zero, 0x50
/* 136314 80242FD4 ACA20000 */  sw        $v0, ($a1)
/* 136318 80242FD8 3C028016 */  lui       $v0, 0x8016
/* 13631C 80242FDC 24429D50 */  addiu     $v0, $v0, -0x62b0
/* 136320 80242FE0 00822021 */  addu      $a0, $a0, $v0
/* 136324 80242FE4 90820000 */  lbu       $v0, ($a0)
/* 136328 80242FE8 304200F3 */  andi      $v0, $v0, 0xf3
/* 13632C 80242FEC 03E00008 */  jr        $ra
/* 136330 80242FF0 A0820000 */   sb       $v0, ($a0)
