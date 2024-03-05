.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .rodata

dlabel __osRcpImTable
 .short 0x0555
 .short 0x0556
 .short 0x0559
 .short 0x055A
 .short 0x0565
 .short 0x0566
 .short 0x0569
 .short 0x056A
 .short 0x0595
 .short 0x0596
 .short 0x0599
 .short 0x059A
 .short 0x05A5
 .short 0x05A6
 .short 0x05A9
 .short 0x05AA
 .short 0x0655
 .short 0x0656
 .short 0x0659
 .short 0x065A
 .short 0x0665
 .short 0x0666
 .short 0x0669
 .short 0x066A
 .short 0x0695
 .short 0x0696
 .short 0x0699
 .short 0x069A
 .short 0x06A5
 .short 0x06A6
 .short 0x06A9
 .short 0x06AA
 .short 0x0955
 .short 0x0956
 .short 0x0959
 .short 0x095A
 .short 0x0965
 .short 0x0966
 .short 0x0969
 .short 0x096A
 .short 0x0995
 .short 0x0996
 .short 0x0999
 .short 0x099A
 .short 0x09A5
 .short 0x09A6
 .short 0x09A9
 .short 0x09AA
 .short 0x0A55
 .short 0x0A56
 .short 0x0A59
 .short 0x0A5A
 .short 0x0A65
 .short 0x0A66
 .short 0x0A69
 .short 0x0A6A
 .short 0x0A95
 .short 0x0A96
 .short 0x0A99
 .short 0x0A9A
 .short 0x0AA5
 .short 0x0AA6
 .short 0x0AA9
 .short 0x0AAA
.size __osRcpImTable, . - __osRcpImTable

.section .text, "ax"

glabel osSetIntMask
/* 3BD40 80060940 400C6000 */  mfc0      $t4, $12
/* 3BD44 80060944 3182FF01 */  andi      $v0, $t4, 0xff01
/* 3BD48 80060948 3C088009 */  lui       $t0, %hi(__OSGlobalIntMask)
/* 3BD4C 8006094C 25085900 */  addiu     $t0, $t0, %lo(__OSGlobalIntMask)
/* 3BD50 80060950 8D0B0000 */  lw        $t3, ($t0)
#ifdef BBPLAYER
/* 421A4 80066DA4 3C01FFFF */  lui       $at, (0xFFFFFFFF >> 16)
/* 421A8 80066DA8 3421FFFF */  ori       $at, $at, (0xFFFFFFFF & 0xFFFF)
#else
/* 3BD54 80060954 2401FFFF */  addiu     $at, $zero, -1
#endif
/* 3BD58 80060958 01614026 */  xor       $t0, $t3, $at
/* 3BD5C 8006095C 3108FF00 */  andi      $t0, $t0, 0xff00
/* 3BD60 80060960 00481025 */  or        $v0, $v0, $t0
/* 3BD64 80060964 3C0AA430 */  lui       $t2, %hi(D_A430000C)
/* 3BD68 80060968 8D4A000C */  lw        $t2, %lo(D_A430000C)($t2)
/* 3BD6C 8006096C 11400005 */  beqz      $t2, .L80060984
/* 3BD70 80060970 000B4C02 */   srl      $t1, $t3, 0x10
#ifdef BBPLAYER
/* 421C8 80066DC8 3C01FFFF */  lui       $at, (0xFFFFFFFF >> 16)
/* 421CC 80066DCC 3421FFFF */  ori       $at, $at, (0xFFFFFFFF & 0xFFFF)
#else
/* 3BD74 80060974 2401FFFF */  addiu     $at, $zero, -1
#endif
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
/* 3BD9C 8006099C 3C0A800A */  lui       $t2, %hi(__osRcpImTable)
/* 3BDA0 800609A0 01485021 */  addu      $t2, $t2, $t0
/* 3BDA4 800609A4 954A9AA0 */  lhu       $t2, %lo(__osRcpImTable)($t2)
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
