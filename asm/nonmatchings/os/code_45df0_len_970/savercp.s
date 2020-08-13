.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel savercp
.L8006AB34:
/* 045F34 8006AB34 3C09A430 */  lui   $t1, 0xa430
/* 045F38 8006AB38 8D29000C */  lw    $t1, 0xc($t1)
/* 045F3C 8006AB3C 1120000B */  beqz  $t1, .L8006AB6C
/* 045F40 8006AB40 00000000 */   nop   
/* 045F44 8006AB44 3C088009 */  lui   $t0, 0x8009
/* 045F48 8006AB48 25085900 */  addiu $t0, $t0, 0x5900
/* 045F4C 8006AB4C 8D080000 */  lw    $t0, ($t0)
/* 045F50 8006AB50 00084402 */  srl   $t0, $t0, 0x10
/* 045F54 8006AB54 2401FFFF */  addiu $at, $zero, -1
/* 045F58 8006AB58 01014026 */  xor   $t0, $t0, $at
/* 045F5C 8006AB5C 3108003F */  andi  $t0, $t0, 0x3f
/* 045F60 8006AB60 8F4C0128 */  lw    $t4, 0x128($k0)
/* 045F64 8006AB64 010C4024 */  and   $t0, $t0, $t4
/* 045F68 8006AB68 01284825 */  or    $t1, $t1, $t0
