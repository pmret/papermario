.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .rodata

dlabel D_80099AA0
.short 0x0555, 0x0556, 0x0559, 0x055A, 0x0565, 0x0566, 0x0569, 0x056A, 0x0595, 0x0596, 0x0599, 0x059A, 0x05A5, 0x05A6, 0x05A9, 0x05AA, 0x0655, 0x0656, 0x0659, 0x065A, 0x0665, 0x0666, 0x0669, 0x066A, 0x0695, 0x0696, 0x0699, 0x069A, 0x06A5, 0x06A6, 0x06A9, 0x06AA, 0x0955, 0x0956, 0x0959, 0x095A, 0x0965, 0x0966, 0x0969, 0x096A, 0x0995, 0x0996, 0x0999, 0x099A, 0x09A5, 0x09A6, 0x09A9, 0x09AA, 0x0A55, 0x0A56, 0x0A59, 0x0A5A, 0x0A65, 0x0A66, 0x0A69, 0x0A6A, 0x0A95, 0x0A96, 0x0A99, 0x0A9A, 0x0AA5, 0x0AA6, 0x0AA9, 0x0AAA

.section .text, "ax"

glabel osSetIntMask
/* 3BD40 80060940 400C6000 */  mfc0      $t4, $12
/* 3BD44 80060944 3182FF01 */  andi      $v0, $t4, 0xff01
/* 3BD48 80060948 3C088009 */  lui       $t0, %hi(__OSGlobalIntMask)
/* 3BD4C 8006094C 25085900 */  addiu     $t0, $t0, %lo(__OSGlobalIntMask)
/* 3BD50 80060950 8D0B0000 */  lw        $t3, ($t0)
/* 3BD54 80060954 2401FFFF */  addiu     $at, $zero, -1
/* 3BD58 80060958 01614026 */  xor       $t0, $t3, $at
/* 3BD5C 8006095C 3108FF00 */  andi      $t0, $t0, 0xff00
/* 3BD60 80060960 00481025 */  or        $v0, $v0, $t0
/* 3BD64 80060964 3C0AA430 */  lui       $t2, %hi(D_A430000C)
/* 3BD68 80060968 8D4A000C */  lw        $t2, %lo(D_A430000C)($t2)
/* 3BD6C 8006096C 11400005 */  beqz      $t2, .L80060984
/* 3BD70 80060970 000B4C02 */   srl      $t1, $t3, 0x10
/* 3BD74 80060974 2401FFFF */  addiu     $at, $zero, -1
/* 3BD78 80060978 01214826 */  xor       $t1, $t1, $at
/* 3BD7C 8006097C 3129003F */  andi      $t1, $t1, 0x3f
/* 3BD80 80060980 01495025 */  or        $t2, $t2, $t1
.L80060984:
/* 3BD84 80060984 000A5400 */  sll       $t2, $t2, 0x10
/* 3BD88 80060988 004A1025 */  or        $v0, $v0, $t2
/* 3BD8C 8006098C 3C01003F */  lui       $at, 0x3f
/* 3BD90 80060990 00814024 */  and       $t0, $a0, $at
/* 3BD94 80060994 010B4024 */  and       $t0, $t0, $t3
/* 3BD98 80060998 000843C2 */  srl       $t0, $t0, 0xf
/* 3BD9C 8006099C 3C0A800A */  lui       $t2, %hi(D_80099AA0)
/* 3BDA0 800609A0 01485021 */  addu      $t2, $t2, $t0
/* 3BDA4 800609A4 954A9AA0 */  lhu       $t2, %lo(D_80099AA0)($t2)
/* 3BDA8 800609A8 3C01A430 */  lui       $at, %hi(D_A430000C)
/* 3BDAC 800609AC AC2A000C */  sw        $t2, %lo(D_A430000C)($at)
/* 3BDB0 800609B0 3088FF01 */  andi      $t0, $a0, 0xff01
/* 3BDB4 800609B4 3169FF00 */  andi      $t1, $t3, 0xff00
/* 3BDB8 800609B8 01094024 */  and       $t0, $t0, $t1
/* 3BDBC 800609BC 3C01FFFF */  lui       $at, 0xffff
/* 3BDC0 800609C0 342100FF */  ori       $at, $at, 0xff
/* 3BDC4 800609C4 01816024 */  and       $t4, $t4, $at
/* 3BDC8 800609C8 01886025 */  or        $t4, $t4, $t0
/* 3BDCC 800609CC 408C6000 */  mtc0      $t4, $12
/* 3BDD0 800609D0 00000000 */  nop
/* 3BDD4 800609D4 00000000 */  nop
/* 3BDD8 800609D8 03E00008 */  jr        $ra
/* 3BDDC 800609DC 00000000 */   nop
