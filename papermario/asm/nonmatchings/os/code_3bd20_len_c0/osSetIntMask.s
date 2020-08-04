.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel osSetIntMask
/* 03BD40 80060940 400C6000 */  mfc0  $t4, $12
/* 03BD44 80060944 3182FF01 */  andi  $v0, $t4, 0xff01
/* 03BD48 80060948 3C088009 */  lui   $t0, 0x8009
/* 03BD4C 8006094C 25085900 */  addiu $t0, $t0, 0x5900
/* 03BD50 80060950 8D0B0000 */  lw    $t3, ($t0)
/* 03BD54 80060954 2401FFFF */  addiu $at, $zero, -1
/* 03BD58 80060958 01614026 */  xor   $t0, $t3, $at
/* 03BD5C 8006095C 3108FF00 */  andi  $t0, $t0, 0xff00
/* 03BD60 80060960 00481025 */  or    $v0, $v0, $t0
/* 03BD64 80060964 3C0AA430 */  lui   $t2, 0xa430
/* 03BD68 80060968 8D4A000C */  lw    $t2, 0xc($t2)
/* 03BD6C 8006096C 11400005 */  beqz  $t2, .L80060984
/* 03BD70 80060970 000B4C02 */   srl   $t1, $t3, 0x10
/* 03BD74 80060974 2401FFFF */  addiu $at, $zero, -1
/* 03BD78 80060978 01214826 */  xor   $t1, $t1, $at
/* 03BD7C 8006097C 3129003F */  andi  $t1, $t1, 0x3f
/* 03BD80 80060980 01495025 */  or    $t2, $t2, $t1
.L80060984:
/* 03BD84 80060984 000A5400 */  sll   $t2, $t2, 0x10
/* 03BD88 80060988 004A1025 */  or    $v0, $v0, $t2
/* 03BD8C 8006098C 3C01003F */  lui   $at, 0x3f
/* 03BD90 80060990 00814024 */  and   $t0, $a0, $at
/* 03BD94 80060994 010B4024 */  and   $t0, $t0, $t3
/* 03BD98 80060998 000843C2 */  srl   $t0, $t0, 0xf
/* 03BD9C 8006099C 3C0A800A */  lui   $t2, 0x800a
/* 03BDA0 800609A0 01485021 */  addu  $t2, $t2, $t0
/* 03BDA4 800609A4 954A9AA0 */  lhu   $t2, -0x6560($t2)
/* 03BDA8 800609A8 3C01A430 */  lui   $at, 0xa430
/* 03BDAC 800609AC AC2A000C */  sw    $t2, 0xc($at)
/* 03BDB0 800609B0 3088FF01 */  andi  $t0, $a0, 0xff01
/* 03BDB4 800609B4 3169FF00 */  andi  $t1, $t3, 0xff00
/* 03BDB8 800609B8 01094024 */  and   $t0, $t0, $t1
/* 03BDBC 800609BC 3C01FFFF */  lui   $at, 0xffff
/* 03BDC0 800609C0 342100FF */  ori   $at, $at, 0xff
/* 03BDC4 800609C4 01816024 */  and   $t4, $t4, $at
/* 03BDC8 800609C8 01886025 */  or    $t4, $t4, $t0
/* 03BDCC 800609CC 408C6000 */  mtc0  $t4, $12
/* 03BDD0 800609D0 00000000 */  nop   
/* 03BDD4 800609D4 00000000 */  nop   
/* 03BDD8 800609D8 03E00008 */  jr    $ra
/* 03BDDC 800609DC 00000000 */   nop   

.set reorder
