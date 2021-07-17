.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_80150730
.word L80127FAC_BE6AC, L8012803C_BE73C, L8012803C_BE73C, L8012803C_BE73C, L8012803C_BE73C, L80128068_BE768, L80128068_BE768, L80128068_BE768, L801280A0_BE7A0, L8012A6C4_C0DC4, L80129ADC_C01DC, L80129BF8_C02F8, L8012AB5C_C125C, L8012AB5C_C125C, L8012AB5C_C125C, L80129C04_C0304

glabel jtbl_80150770
.word L801280DC_BE7DC, L801280DC_BE7DC, L801280DC_BE7DC, L801280DC_BE7DC, L8012897C_BF07C, L80128D28_BF428, L80128F34_BF634, L80128F34_BF634, L801296EC_BFDEC, L80129958_C0058, L80129958_C0058, L80128D28_BF428, L80128D28_BF428, L80129A40_C0140, L80128D28_BF428, 0

glabel D_801507B0
.double 0.35

glabel D_801507B8
.double 0.13333333333333333

glabel D_801507C0
.double 0.2

glabel D_801507C8
.double 255.0

glabel D_801507D0
.double 0.6

glabel D_801507D8
.double 0.6

glabel jtbl_801507E0
.word L80129C44_C0344, L80129C7C_C037C, L8012BF70_C2670, L8012BF70_C2670, L80129CA8_C03A8, L80129CE0_C03E0, L80129D00_C0400, L80129E38_C0538, L80129E84_C0584, L80129EBC_C05BC, L80129EE0_C05E0, L80129F14_C0614, L80129F40_C0640, L8012BF70_C2670, L80129F74_C0674, L8012A0C8_C07C8, L8012A21C_C091C, L8012A350_C0A50, L8012A54C_C0C4C, L8012AB44_C1244, L8012A564_C0C64, L8012A5E0_C0CE0, L8012A634_C0D34, L8012A654_C0D54, L8012A664_C0D64, L8012A68C_C0D8C, L8012A6B4_C0DB4, L8012A6DC_C0DDC, L8012A6FC_C0DFC, L8012A960_C1060, L8012AAD8_C11D8, 0

glabel D_80150860
.double 0.7

glabel D_80150868
.double 0.7

glabel D_80150870
.double 0.7

glabel jtbl_80150878
.word L8012A734_C0E34, L8012A74C_C0E4C, L8012A764_C0E64, L8012A7AC_C0EAC, L8012BF70_C2670, L8012A834_C0F34, L8012A864_C0F64, L8012A87C_C0F7C, L8012A8AC_C0FAC, L8012A8C4_C0FC4, L8012A8DC_C0FDC, L8012A8F4_C0FF4, L8012A90C_C100C, L8012A924_C1024, L8012A93C_C103C, 0

glabel jtbl_801508B8
.word L8012A998_C1098, L8012A9AC_C10AC, L8012A9C0_C10C0, L8012A9D4_C10D4, L8012AB44_C1244, L8012A9EC_C10EC, L8012AA00_C1100, L8012AA10_C1110, L8012AA24_C1124, L8012AA38_C1138, L8012AA60_C1160, L8012AA74_C1174, L8012AA88_C1188, L8012AA9C_C119C, L8012AAB8_C11B8, 0

glabel D_801508F8
.double 0.35

glabel D_80150900
.double 45.0

glabel D_80150908
.double 1.6

glabel D_80150910
.double 180.0

glabel D_80150918
.double 90.0

glabel D_80150920
.double 1.6

glabel D_80150928
.double 180.0

glabel D_80150930
.double 90.0

glabel D_80150938
.double 255.0

glabel D_80150940
.double 1.7

glabel D_80150948
.double 1.4

glabel D_80150950
.double 1.2

glabel D_80150958
.double 0.3

glabel jtbl_80150960
.word L8012BC6C_C236C, L8012BC64_C2364, L8012BC64_C2364, L8012BC64_C2364, L8012BC64_C2364, L8012BC64_C2364, L8012BC64_C2364, L8012BC6C_C236C, L8012BC64_C2364, L8012BC64_C2364, L8012BC30_C2330, L8012BC64_C2364, L8012BC64_C2364, L8012BC64_C2364, L8012BC64_C2364, L8012BC64_C2364, L8012BC6C_C236C, L8012BC6C_C236C, L8012BC6C_C236C, L8012BC6C_C236C, L8012BC6C_C236C, L8012BC64_C2364, L8012BC64_C2364, L8012BC64_C2364, L8012BC64_C2364, L8012BC64_C2364, L8012BC64_C2364, L8012BC64_C2364, L8012BC64_C2364, L8012BC64_C2364, L8012BC64_C2364, L8012BC64_C2364, L8012BC3C_C233C, L8012BC64_C2364, L8012BC44_C2344, L8012BC50_C2350, L8012BC64_C2364, L8012BC58_C2358

glabel D_801509F8
.double 255.0

glabel D_80150A00
.double 255.0

.section .text

glabel appendGfx_message
/* BE490 80127D90 27BDFEC0 */  addiu     $sp, $sp, -0x140
/* BE494 80127D94 AFBE0108 */  sw        $fp, 0x108($sp)
/* BE498 80127D98 0080F02D */  daddu     $fp, $a0, $zero
/* BE49C 80127D9C AFB000E8 */  sw        $s0, 0xe8($sp)
/* BE4A0 80127DA0 3C108015 */  lui       $s0, %hi(gMessageDrawStatePtr)
/* BE4A4 80127DA4 26105D74 */  addiu     $s0, $s0, %lo(gMessageDrawStatePtr)
/* BE4A8 80127DA8 AFB100EC */  sw        $s1, 0xec($sp)
/* BE4AC 80127DAC 8FB10154 */  lw        $s1, 0x154($sp)
/* BE4B0 80127DB0 97B80152 */  lhu       $t8, 0x152($sp)
/* BE4B4 80127DB4 3C028015 */  lui       $v0, %hi(D_80155D20)
/* BE4B8 80127DB8 24425D20 */  addiu     $v0, $v0, %lo(D_80155D20)
/* BE4BC 80127DBC AFB200F0 */  sw        $s2, 0xf0($sp)
/* BE4C0 80127DC0 93B2015B */  lbu       $s2, 0x15b($sp)
/* BE4C4 80127DC4 27C30010 */  addiu     $v1, $fp, 0x10
/* BE4C8 80127DC8 AFB300F4 */  sw        $s3, 0xf4($sp)
/* BE4CC 80127DCC 3C13800A */  lui       $s3, %hi(gMasterGfxPos)
/* BE4D0 80127DD0 2673A66C */  addiu     $s3, $s3, %lo(gMasterGfxPos)
/* BE4D4 80127DD4 AFBF010C */  sw        $ra, 0x10c($sp)
/* BE4D8 80127DD8 AFB70104 */  sw        $s7, 0x104($sp)
/* BE4DC 80127DDC AFB60100 */  sw        $s6, 0x100($sp)
/* BE4E0 80127DE0 AFB500FC */  sw        $s5, 0xfc($sp)
/* BE4E4 80127DE4 AFB400F8 */  sw        $s4, 0xf8($sp)
/* BE4E8 80127DE8 F7BE0138 */  sdc1      $f30, 0x138($sp)
/* BE4EC 80127DEC F7BC0130 */  sdc1      $f28, 0x130($sp)
/* BE4F0 80127DF0 F7BA0128 */  sdc1      $f26, 0x128($sp)
/* BE4F4 80127DF4 F7B80120 */  sdc1      $f24, 0x120($sp)
/* BE4F8 80127DF8 F7B60118 */  sdc1      $f22, 0x118($sp)
/* BE4FC 80127DFC F7B40110 */  sdc1      $f20, 0x110($sp)
/* BE500 80127E00 A7B8007E */  sh        $t8, 0x7e($sp)
/* BE504 80127E04 AE020000 */  sw        $v0, ($s0)
/* BE508 80127E08 AC43004C */  sw        $v1, 0x4c($v0)
/* BE50C 80127E0C A4400034 */  sh        $zero, 0x34($v0)
/* BE510 80127E10 A7A50066 */  sh        $a1, 0x66($sp)
/* BE514 80127E14 A7A6006E */  sh        $a2, 0x6e($sp)
/* BE518 80127E18 8E630000 */  lw        $v1, ($s3)
/* BE51C 80127E1C 3C028015 */  lui       $v0, %hi(D_80151338)
/* BE520 80127E20 8C421338 */  lw        $v0, %lo(D_80151338)($v0)
/* BE524 80127E24 10620003 */  beq       $v1, $v0, .L80127E34
/* BE528 80127E28 A7A70076 */   sh       $a3, 0x76($sp)
/* BE52C 80127E2C 0C04B0B8 */  jal       msg_reset_gfx_state
/* BE530 80127E30 00000000 */   nop
.L80127E34:
/* BE534 80127E34 8E040000 */  lw        $a0, ($s0)
/* BE538 80127E38 94820034 */  lhu       $v0, 0x34($a0)
/* BE53C 80127E3C 241900FF */  addiu     $t9, $zero, 0xff
/* BE540 80127E40 A7B9008E */  sh        $t9, 0x8e($sp)
/* BE544 80127E44 34420101 */  ori       $v0, $v0, 0x101
/* BE548 80127E48 A4820034 */  sh        $v0, 0x34($a0)
/* BE54C 80127E4C 32220001 */  andi      $v0, $s1, 1
/* BE550 80127E50 10400003 */  beqz      $v0, .L80127E60
/* BE554 80127E54 00000000 */   nop
/* BE558 80127E58 325200FF */  andi      $s2, $s2, 0xff
/* BE55C 80127E5C A7B2008E */  sh        $s2, 0x8e($sp)
.L80127E60:
/* BE560 80127E60 3C013F80 */  lui       $at, 0x3f80
/* BE564 80127E64 44810000 */  mtc1      $at, $f0
/* BE568 80127E68 2402013F */  addiu     $v0, $zero, 0x13f
/* BE56C 80127E6C A4800046 */  sh        $zero, 0x46($a0)
/* BE570 80127E70 A4800048 */  sh        $zero, 0x48($a0)
/* BE574 80127E74 AC800000 */  sw        $zero, ($a0)
/* BE578 80127E78 AC800008 */  sw        $zero, 8($a0)
/* BE57C 80127E7C AC820004 */  sw        $v0, 4($a0)
/* BE580 80127E80 A0800029 */  sb        $zero, 0x29($a0)
/* BE584 80127E84 8E030000 */  lw        $v1, ($s0)
/* BE588 80127E88 240200EF */  addiu     $v0, $zero, 0xef
/* BE58C 80127E8C AC82000C */  sw        $v0, 0xc($a0)
/* BE590 80127E90 E4800010 */  swc1      $f0, 0x10($a0)
/* BE594 80127E94 E4800014 */  swc1      $f0, 0x14($a0)
/* BE598 80127E98 A060002B */  sb        $zero, 0x2b($v1)
/* BE59C 80127E9C 8E020000 */  lw        $v0, ($s0)
/* BE5A0 80127EA0 241800FF */  addiu     $t8, $zero, 0xff
/* BE5A4 80127EA4 A7B80096 */  sh        $t8, 0x96($sp)
/* BE5A8 80127EA8 A040002C */  sb        $zero, 0x2c($v0)
/* BE5AC 80127EAC 8E020000 */  lw        $v0, ($s0)
/* BE5B0 80127EB0 0300C82D */  daddu     $t9, $t8, $zero
/* BE5B4 80127EB4 A7B900AE */  sh        $t9, 0xae($sp)
/* BE5B8 80127EB8 A040002E */  sb        $zero, 0x2e($v0)
/* BE5BC 80127EBC 8E030000 */  lw        $v1, ($s0)
/* BE5C0 80127EC0 A7A000B6 */  sh        $zero, 0xb6($sp)
/* BE5C4 80127EC4 AC400030 */  sw        $zero, 0x30($v0)
/* BE5C8 80127EC8 A0600040 */  sb        $zero, 0x40($v1)
/* BE5CC 80127ECC 8E020000 */  lw        $v0, ($s0)
/* BE5D0 80127ED0 A3A000B8 */  sb        $zero, 0xb8($sp)
/* BE5D4 80127ED4 A460003E */  sh        $zero, 0x3e($v1)
/* BE5D8 80127ED8 A0400050 */  sb        $zero, 0x50($v0)
/* BE5DC 80127EDC 8E030000 */  lw        $v1, ($s0)
/* BE5E0 80127EE0 2418FFFF */  addiu     $t8, $zero, -1
/* BE5E4 80127EE4 A7B8009E */  sh        $t8, 0x9e($sp)
/* BE5E8 80127EE8 A4400042 */  sh        $zero, 0x42($v0)
/* BE5EC 80127EEC A4400044 */  sh        $zero, 0x44($v0)
/* BE5F0 80127EF0 A440003C */  sh        $zero, 0x3c($v0)
/* BE5F4 80127EF4 AC400038 */  sw        $zero, 0x38($v0)
/* BE5F8 80127EF8 32220002 */  andi      $v0, $s1, 2
/* BE5FC 80127EFC 10400003 */  beqz      $v0, .L80127F0C
/* BE600 80127F00 A460004A */   sh       $zero, 0x4a($v1)
/* BE604 80127F04 24020001 */  addiu     $v0, $zero, 1
/* BE608 80127F08 A462003C */  sh        $v0, 0x3c($v1)
.L80127F0C:
/* BE60C 80127F0C 32220004 */  andi      $v0, $s1, 4
/* BE610 80127F10 10400009 */  beqz      $v0, .L80127F38
/* BE614 80127F14 3C04004F */   lui      $a0, 0x4f
/* BE618 80127F18 8E620000 */  lw        $v0, ($s3)
/* BE61C 80127F1C 3484C3BC */  ori       $a0, $a0, 0xc3bc
/* BE620 80127F20 0040182D */  daddu     $v1, $v0, $zero
/* BE624 80127F24 24420008 */  addiu     $v0, $v0, 8
/* BE628 80127F28 AE620000 */  sw        $v0, ($s3)
/* BE62C 80127F2C 3C02ED00 */  lui       $v0, 0xed00
/* BE630 80127F30 AC620000 */  sw        $v0, ($v1)
/* BE634 80127F34 AC640004 */  sw        $a0, 4($v1)
.L80127F38:
/* BE638 80127F38 0260B82D */  daddu     $s7, $s3, $zero
/* BE63C 80127F3C 3C19FD48 */  lui       $t9, 0xfd48
/* BE640 80127F40 3739000F */  ori       $t9, $t9, 0xf
/* BE644 80127F44 3C18F548 */  lui       $t8, 0xf548
/* BE648 80127F48 37180400 */  ori       $t8, $t8, 0x400
/* BE64C 80127F4C AFB900C4 */  sw        $t9, 0xc4($sp)
/* BE650 80127F50 3C190701 */  lui       $t9, 0x701
/* BE654 80127F54 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* BE658 80127F58 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* BE65C 80127F5C 37390050 */  ori       $t9, $t9, 0x50
/* BE660 80127F60 A7A00080 */  sh        $zero, 0x80($sp)
/* BE664 80127F64 AFB800C8 */  sw        $t8, 0xc8($sp)
/* BE668 80127F68 AFB900CC */  sw        $t9, 0xcc($sp)
/* BE66C 80127F6C AC400020 */  sw        $zero, 0x20($v0)
.L80127F70:
/* BE670 80127F70 3C038015 */  lui       $v1, %hi(gMessageDrawStatePtr)
/* BE674 80127F74 8C635D74 */  lw        $v1, %lo(gMessageDrawStatePtr)($v1)
/* BE678 80127F78 8C62004C */  lw        $v0, 0x4c($v1)
/* BE67C 80127F7C 8C630020 */  lw        $v1, 0x20($v1)
/* BE680 80127F80 00431021 */  addu      $v0, $v0, $v1
/* BE684 80127F84 90420000 */  lbu       $v0, ($v0)
/* BE688 80127F88 2443FF10 */  addiu     $v1, $v0, -0xf0
/* BE68C 80127F8C 2C620010 */  sltiu     $v0, $v1, 0x10
/* BE690 80127F90 10400AF2 */  beqz      $v0, L8012AB5C_C125C
/* BE694 80127F94 00031080 */   sll      $v0, $v1, 2
/* BE698 80127F98 3C018015 */  lui       $at, %hi(jtbl_80150730)
/* BE69C 80127F9C 00220821 */  addu      $at, $at, $v0
/* BE6A0 80127FA0 8C220730 */  lw        $v0, %lo(jtbl_80150730)($at)
/* BE6A4 80127FA4 00400008 */  jr        $v0
/* BE6A8 80127FA8 00000000 */   nop
glabel L80127FAC_BE6AC
/* BE6AC 80127FAC 3C048015 */  lui       $a0, %hi(gMessageDrawStatePtr)
/* BE6B0 80127FB0 8C845D74 */  lw        $a0, %lo(gMessageDrawStatePtr)($a0)
/* BE6B4 80127FB4 9482003C */  lhu       $v0, 0x3c($a0)
/* BE6B8 80127FB8 A4800042 */  sh        $zero, 0x42($a0)
/* BE6BC 80127FBC 00021080 */  sll       $v0, $v0, 2
/* BE6C0 80127FC0 3C01802F */  lui       $at, %hi(gMsgCharsets)
/* BE6C4 80127FC4 00220821 */  addu      $at, $at, $v0
/* BE6C8 80127FC8 8C22B5A8 */  lw        $v0, %lo(gMsgCharsets)($at)
/* BE6CC 80127FCC 90420003 */  lbu       $v0, 3($v0)
/* BE6D0 80127FD0 C4820014 */  lwc1      $f2, 0x14($a0)
/* BE6D4 80127FD4 44820000 */  mtc1      $v0, $f0
/* BE6D8 80127FD8 00000000 */  nop
/* BE6DC 80127FDC 46800020 */  cvt.s.w   $f0, $f0
/* BE6E0 80127FE0 93C20508 */  lbu       $v0, 0x508($fp)
/* BE6E4 80127FE4 46001082 */  mul.s     $f2, $f2, $f0
/* BE6E8 80127FE8 00000000 */  nop
/* BE6EC 80127FEC 00021040 */  sll       $v0, $v0, 1
/* BE6F0 80127FF0 3C01802F */  lui       $at, %hi(D_802EB644)
/* BE6F4 80127FF4 00220821 */  addu      $at, $at, $v0
/* BE6F8 80127FF8 8422B644 */  lh        $v0, %lo(D_802EB644)($at)
/* BE6FC 80127FFC 44820000 */  mtc1      $v0, $f0
/* BE700 80128000 00000000 */  nop
/* BE704 80128004 46800020 */  cvt.s.w   $f0, $f0
/* BE708 80128008 46001080 */  add.s     $f2, $f2, $f0
/* BE70C 8012800C 94850034 */  lhu       $a1, 0x34($a0)
/* BE710 80128010 94820044 */  lhu       $v0, 0x44($a0)
/* BE714 80128014 4600130D */  trunc.w.s $f12, $f2
/* BE718 80128018 44036000 */  mfc1      $v1, $f12
/* BE71C 8012801C 00000000 */  nop
/* BE720 80128020 00431021 */  addu      $v0, $v0, $v1
/* BE724 80128024 A4820044 */  sh        $v0, 0x44($a0)
/* BE728 80128028 30A20040 */  andi      $v0, $a1, 0x40
/* BE72C 8012802C 104009A5 */  beqz      $v0, L8012A6C4_C0DC4
/* BE730 80128030 34A20080 */   ori      $v0, $a1, 0x80
/* BE734 80128034 0804A9B1 */  j         L8012A6C4_C0DC4
/* BE738 80128038 A4820034 */   sh       $v0, 0x34($a0)
glabel L8012803C_BE73C
/* BE73C 8012803C 3C048015 */  lui       $a0, %hi(gMessageDrawStatePtr)
/* BE740 80128040 8C845D74 */  lw        $a0, %lo(gMessageDrawStatePtr)($a0)
/* BE744 80128044 8C83004C */  lw        $v1, 0x4c($a0)
/* BE748 80128048 8C820020 */  lw        $v0, 0x20($a0)
/* BE74C 8012804C 00621821 */  addu      $v1, $v1, $v0
/* BE750 80128050 90630000 */  lbu       $v1, ($v1)
/* BE754 80128054 24420001 */  addiu     $v0, $v0, 1
/* BE758 80128058 AC820020 */  sw        $v0, 0x20($a0)
/* BE75C 8012805C 2463FF0F */  addiu     $v1, $v1, -0xf1
/* BE760 80128060 0804AFDC */  j         L8012BF70_C2670
/* BE764 80128064 A483003E */   sh       $v1, 0x3e($a0)
glabel L80128068_BE768
/* BE768 80128068 3C078015 */  lui       $a3, %hi(gMessageDrawStatePtr)
/* BE76C 8012806C 8CE75D74 */  lw        $a3, %lo(gMessageDrawStatePtr)($a3)
/* BE770 80128070 8CE2004C */  lw        $v0, 0x4c($a3)
/* BE774 80128074 8CE30020 */  lw        $v1, 0x20($a3)
/* BE778 80128078 94E5003C */  lhu       $a1, 0x3c($a3)
/* BE77C 8012807C 94E6003E */  lhu       $a2, 0x3e($a3)
/* BE780 80128080 00431021 */  addu      $v0, $v0, $v1
/* BE784 80128084 90440000 */  lbu       $a0, ($v0)
/* BE788 80128088 90E20040 */  lbu       $v0, 0x40($a3)
/* BE78C 8012808C AFA20010 */  sw        $v0, 0x10($sp)
/* BE790 80128090 94E20034 */  lhu       $v0, 0x34($a3)
/* BE794 80128094 AFA20014 */  sw        $v0, 0x14($sp)
/* BE798 80128098 0804AFD2 */  j         .L8012BF48
/* BE79C 8012809C 8CE70010 */   lw       $a3, 0x10($a3)
glabel L801280A0_BE7A0
/* BE7A0 801280A0 3C038015 */  lui       $v1, %hi(gMessageDrawStatePtr)
/* BE7A4 801280A4 8C635D74 */  lw        $v1, %lo(gMessageDrawStatePtr)($v1)
/* BE7A8 801280A8 8C620020 */  lw        $v0, 0x20($v1)
/* BE7AC 801280AC 8C63004C */  lw        $v1, 0x4c($v1)
/* BE7B0 801280B0 00431021 */  addu      $v0, $v0, $v1
/* BE7B4 801280B4 90420001 */  lbu       $v0, 1($v0)
/* BE7B8 801280B8 2443FFFF */  addiu     $v1, $v0, -1
/* BE7BC 801280BC 2C62000F */  sltiu     $v0, $v1, 0xf
/* BE7C0 801280C0 10400FAB */  beqz      $v0, L8012BF70_C2670
/* BE7C4 801280C4 00031080 */   sll      $v0, $v1, 2
/* BE7C8 801280C8 3C018015 */  lui       $at, %hi(jtbl_80150770)
/* BE7CC 801280CC 00220821 */  addu      $at, $at, $v0
/* BE7D0 801280D0 8C220770 */  lw        $v0, %lo(jtbl_80150770)($at)
/* BE7D4 801280D4 00400008 */  jr        $v0
/* BE7D8 801280D8 00000000 */   nop
glabel L801280DC_BE7DC
/* BE7DC 801280DC 93C204F8 */  lbu       $v0, 0x4f8($fp)
/* BE7E0 801280E0 24190002 */  addiu     $t9, $zero, 2
/* BE7E4 801280E4 14590008 */  bne       $v0, $t9, .L80128108
/* BE7E8 801280E8 00000000 */   nop
/* BE7EC 801280EC 93C20509 */  lbu       $v0, 0x509($fp)
/* BE7F0 801280F0 14400005 */  bnez      $v0, .L80128108
/* BE7F4 801280F4 00000000 */   nop
/* BE7F8 801280F8 97C2050A */  lhu       $v0, 0x50a($fp)
/* BE7FC 801280FC 97C3050C */  lhu       $v1, 0x50c($fp)
/* BE800 80128100 A7C2050E */  sh        $v0, 0x50e($fp)
/* BE804 80128104 A7C30510 */  sh        $v1, 0x510($fp)
.L80128108:
/* BE808 80128108 97C20514 */  lhu       $v0, 0x514($fp)
/* BE80C 8012810C 3C013FE0 */  lui       $at, 0x3fe0
/* BE810 80128110 44816800 */  mtc1      $at, $f13
/* BE814 80128114 44806000 */  mtc1      $zero, $f12
/* BE818 80128118 97D6050E */  lhu       $s6, 0x50e($fp)
/* BE81C 8012811C 44820000 */  mtc1      $v0, $f0
/* BE820 80128120 00000000 */  nop
/* BE824 80128124 46800020 */  cvt.s.w   $f0, $f0
/* BE828 80128128 46000021 */  cvt.d.s   $f0, $f0
/* BE82C 8012812C 462C0002 */  mul.d     $f0, $f0, $f12
/* BE830 80128130 00000000 */  nop
/* BE834 80128134 97D50510 */  lhu       $s5, 0x510($fp)
/* BE838 80128138 3C058015 */  lui       $a1, %hi(gMessageDrawStatePtr)
/* BE83C 8012813C 8CA55D74 */  lw        $a1, %lo(gMessageDrawStatePtr)($a1)
/* BE840 80128140 87C3045A */  lh        $v1, 0x45a($fp)
/* BE844 80128144 97C20516 */  lhu       $v0, 0x516($fp)
/* BE848 80128148 87C4045C */  lh        $a0, 0x45c($fp)
/* BE84C 8012814C 44822000 */  mtc1      $v0, $f4
/* BE850 80128150 00000000 */  nop
/* BE854 80128154 46802120 */  cvt.s.w   $f4, $f4
/* BE858 80128158 46002121 */  cvt.d.s   $f4, $f4
/* BE85C 8012815C 462C2102 */  mul.d     $f4, $f4, $f12
/* BE860 80128160 00000000 */  nop
/* BE864 80128164 2418000A */  addiu     $t8, $zero, 0xa
/* BE868 80128168 94A20034 */  lhu       $v0, 0x34($a1)
/* BE86C 8012816C 44831000 */  mtc1      $v1, $f2
/* BE870 80128170 00000000 */  nop
/* BE874 80128174 468010A1 */  cvt.d.w   $f2, $f2
/* BE878 80128178 A4B8004A */  sh        $t8, 0x4a($a1)
/* BE87C 8012817C 34420010 */  ori       $v0, $v0, 0x10
/* BE880 80128180 A4A20034 */  sh        $v0, 0x34($a1)
/* BE884 80128184 93C20508 */  lbu       $v0, 0x508($fp)
/* BE888 80128188 46201080 */  add.d     $f2, $f2, $f0
/* BE88C 8012818C 2442FFFF */  addiu     $v0, $v0, -1
/* BE890 80128190 44840000 */  mtc1      $a0, $f0
/* BE894 80128194 00000000 */  nop
/* BE898 80128198 46800021 */  cvt.d.w   $f0, $f0
/* BE89C 8012819C 46240000 */  add.d     $f0, $f0, $f4
/* BE8A0 801281A0 2C420003 */  sltiu     $v0, $v0, 3
/* BE8A4 801281A4 4620130D */  trunc.w.d $f12, $f2
/* BE8A8 801281A8 44146000 */  mfc1      $s4, $f12
/* BE8AC 801281AC 4620030D */  trunc.w.d $f12, $f0
/* BE8B0 801281B0 44136000 */  mfc1      $s3, $f12
/* BE8B4 801281B4 10400013 */  beqz      $v0, .L80128204
/* BE8B8 801281B8 241000DA */   addiu    $s0, $zero, 0xda
/* BE8BC 801281BC 24120020 */  addiu     $s2, $zero, 0x20
/* BE8C0 801281C0 24110044 */  addiu     $s1, $zero, 0x44
/* BE8C4 801281C4 24020016 */  addiu     $v0, $zero, 0x16
/* BE8C8 801281C8 A7C2045A */  sh        $v0, 0x45a($fp)
/* BE8CC 801281CC 2402000D */  addiu     $v0, $zero, 0xd
/* BE8D0 801281D0 A7C2045C */  sh        $v0, 0x45c($fp)
/* BE8D4 801281D4 24020128 */  addiu     $v0, $zero, 0x128
/* BE8D8 801281D8 A7C20514 */  sh        $v0, 0x514($fp)
/* BE8DC 801281DC 0220102D */  daddu     $v0, $s1, $zero
/* BE8E0 801281E0 A7C20516 */  sh        $v0, 0x516($fp)
/* BE8E4 801281E4 2402001A */  addiu     $v0, $zero, 0x1a
/* BE8E8 801281E8 A4A20046 */  sh        $v0, 0x46($a1)
/* BE8EC 801281EC 24020006 */  addiu     $v0, $zero, 6
/* BE8F0 801281F0 A4A20048 */  sh        $v0, 0x48($a1)
/* BE8F4 801281F4 24020114 */  addiu     $v0, $zero, 0x114
/* BE8F8 801281F8 A7C20482 */  sh        $v0, 0x482($fp)
/* BE8FC 801281FC 0804A0DF */  j         .L8012837C
/* BE900 80128200 24020039 */   addiu    $v0, $zero, 0x39
.L80128204:
/* BE904 80128204 93C3053C */  lbu       $v1, 0x53c($fp)
/* BE908 80128208 24190002 */  addiu     $t9, $zero, 2
/* BE90C 8012820C 10790012 */  beq       $v1, $t9, .L80128258
/* BE910 80128210 28620003 */   slti     $v0, $v1, 3
/* BE914 80128214 10400005 */  beqz      $v0, .L8012822C
/* BE918 80128218 24180001 */   addiu    $t8, $zero, 1
/* BE91C 8012821C 10780008 */  beq       $v1, $t8, .L80128240
/* BE920 80128220 24120020 */   addiu    $s2, $zero, 0x20
/* BE924 80128224 0804A0A1 */  j         .L80128284
/* BE928 80128228 00000000 */   nop
.L8012822C:
/* BE92C 8012822C 24190003 */  addiu     $t9, $zero, 3
/* BE930 80128230 1079000F */  beq       $v1, $t9, .L80128270
/* BE934 80128234 24120020 */   addiu    $s2, $zero, 0x20
/* BE938 80128238 0804A0A1 */  j         .L80128284
/* BE93C 8012823C 00000000 */   nop
.L80128240:
/* BE940 80128240 24120018 */  addiu     $s2, $zero, 0x18
/* BE944 80128244 24020012 */  addiu     $v0, $zero, 0x12
/* BE948 80128248 2418000A */  addiu     $t8, $zero, 0xa
/* BE94C 8012824C A4A20046 */  sh        $v0, 0x46($a1)
/* BE950 80128250 0804A0A7 */  j         .L8012829C
/* BE954 80128254 A4B80048 */   sh       $t8, 0x48($a1)
.L80128258:
/* BE958 80128258 2412001C */  addiu     $s2, $zero, 0x1c
/* BE95C 8012825C 24020016 */  addiu     $v0, $zero, 0x16
/* BE960 80128260 A4A20046 */  sh        $v0, 0x46($a1)
/* BE964 80128264 24020006 */  addiu     $v0, $zero, 6
/* BE968 80128268 0804A0A7 */  j         .L8012829C
/* BE96C 8012826C A4A20048 */   sh       $v0, 0x48($a1)
.L80128270:
/* BE970 80128270 2402001A */  addiu     $v0, $zero, 0x1a
/* BE974 80128274 A4A20046 */  sh        $v0, 0x46($a1)
/* BE978 80128278 24020008 */  addiu     $v0, $zero, 8
/* BE97C 8012827C 0804A0A7 */  j         .L8012829C
/* BE980 80128280 A4A20048 */   sh       $v0, 0x48($a1)
.L80128284:
/* BE984 80128284 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* BE988 80128288 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* BE98C 8012828C 2403001A */  addiu     $v1, $zero, 0x1a
/* BE990 80128290 A4430046 */  sh        $v1, 0x46($v0)
/* BE994 80128294 24030006 */  addiu     $v1, $zero, 6
/* BE998 80128298 A4430048 */  sh        $v1, 0x48($v0)
.L8012829C:
/* BE99C 8012829C 97D00538 */  lhu       $s0, 0x538($fp)
/* BE9A0 801282A0 2A020101 */  slti      $v0, $s0, 0x101
/* BE9A4 801282A4 50400001 */  beql      $v0, $zero, .L801282AC
/* BE9A8 801282A8 24100100 */   addiu    $s0, $zero, 0x100
.L801282AC:
/* BE9AC 801282AC 2A020046 */  slti      $v0, $s0, 0x46
/* BE9B0 801282B0 54400001 */  bnel      $v0, $zero, .L801282B8
/* BE9B4 801282B4 24100046 */   addiu    $s0, $zero, 0x46
.L801282B8:
/* BE9B8 801282B8 2610FFF4 */  addiu     $s0, $s0, -0xc
/* BE9BC 801282BC 00121040 */  sll       $v0, $s2, 1
/* BE9C0 801282C0 93C3053C */  lbu       $v1, 0x53c($fp)
/* BE9C4 801282C4 02021021 */  addu      $v0, $s0, $v0
/* BE9C8 801282C8 A7C20514 */  sh        $v0, 0x514($fp)
/* BE9CC 801282CC 000310C0 */  sll       $v0, $v1, 3
/* BE9D0 801282D0 00431023 */  subu      $v0, $v0, $v1
/* BE9D4 801282D4 00021040 */  sll       $v0, $v0, 1
/* BE9D8 801282D8 24510010 */  addiu     $s1, $v0, 0x10
/* BE9DC 801282DC 2A220045 */  slti      $v0, $s1, 0x45
/* BE9E0 801282E0 50400001 */  beql      $v0, $zero, .L801282E8
/* BE9E4 801282E4 24110044 */   addiu    $s1, $zero, 0x44
.L801282E8:
/* BE9E8 801282E8 2A220024 */  slti      $v0, $s1, 0x24
/* BE9EC 801282EC 54400001 */  bnel      $v0, $zero, .L801282F4
/* BE9F0 801282F0 24110024 */   addiu    $s1, $zero, 0x24
.L801282F4:
/* BE9F4 801282F4 97C40514 */  lhu       $a0, 0x514($fp)
/* BE9F8 801282F8 97C2050E */  lhu       $v0, 0x50e($fp)
/* BE9FC 801282FC 00041842 */  srl       $v1, $a0, 1
/* BEA00 80128300 00433023 */  subu      $a2, $v0, $v1
/* BEA04 80128304 28C20012 */  slti      $v0, $a2, 0x12
/* BEA08 80128308 10400002 */  beqz      $v0, .L80128314
/* BEA0C 8012830C A7D10516 */   sh       $s1, 0x516($fp)
/* BEA10 80128310 24060012 */  addiu     $a2, $zero, 0x12
.L80128314:
/* BEA14 80128314 00C41021 */  addu      $v0, $a2, $a0
/* BEA18 80128318 2842012F */  slti      $v0, $v0, 0x12f
/* BEA1C 8012831C 14400002 */  bnez      $v0, .L80128328
/* BEA20 80128320 2402012E */   addiu    $v0, $zero, 0x12e
/* BEA24 80128324 00443023 */  subu      $a2, $v0, $a0
.L80128328:
/* BEA28 80128328 97C50516 */  lhu       $a1, 0x516($fp)
/* BEA2C 8012832C 97C20510 */  lhu       $v0, 0x510($fp)
/* BEA30 80128330 24A30026 */  addiu     $v1, $a1, 0x26
/* BEA34 80128334 00432023 */  subu      $a0, $v0, $v1
/* BEA38 80128338 28820014 */  slti      $v0, $a0, 0x14
/* BEA3C 8012833C 54400001 */  bnel      $v0, $zero, .L80128344
/* BEA40 80128340 24040014 */   addiu    $a0, $zero, 0x14
.L80128344:
/* BEA44 80128344 00851021 */  addu      $v0, $a0, $a1
/* BEA48 80128348 284200AB */  slti      $v0, $v0, 0xab
/* BEA4C 8012834C 14400002 */  bnez      $v0, .L80128358
/* BEA50 80128350 240200AA */   addiu    $v0, $zero, 0xaa
/* BEA54 80128354 00452023 */  subu      $a0, $v0, $a1
.L80128358:
/* BEA58 80128358 97C30514 */  lhu       $v1, 0x514($fp)
/* BEA5C 8012835C 97C20516 */  lhu       $v0, 0x516($fp)
/* BEA60 80128360 A7C6045A */  sh        $a2, 0x45a($fp)
/* BEA64 80128364 A7C4045C */  sh        $a0, 0x45c($fp)
/* BEA68 80128368 00661821 */  addu      $v1, $v1, $a2
/* BEA6C 8012836C 2463FFE2 */  addiu     $v1, $v1, -0x1e
/* BEA70 80128370 00441021 */  addu      $v0, $v0, $a0
/* BEA74 80128374 2442FFEE */  addiu     $v0, $v0, -0x12
/* BEA78 80128378 A7C30482 */  sh        $v1, 0x482($fp)
.L8012837C:
/* BEA7C 8012837C A7C20484 */  sh        $v0, 0x484($fp)
/* BEA80 80128380 93C204F8 */  lbu       $v0, 0x4f8($fp)
/* BEA84 80128384 2442FFF5 */  addiu     $v0, $v0, -0xb
/* BEA88 80128388 2C420002 */  sltiu     $v0, $v0, 2
/* BEA8C 8012838C 10400004 */  beqz      $v0, .L801283A0
/* BEA90 80128390 24190001 */   addiu    $t9, $zero, 1
/* BEA94 80128394 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* BEA98 80128398 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* BEA9C 8012839C A059002B */  sb        $t9, 0x2b($v0)
.L801283A0:
/* BEAA0 801283A0 93C204F8 */  lbu       $v0, 0x4f8($fp)
/* BEAA4 801283A4 24180002 */  addiu     $t8, $zero, 2
/* BEAA8 801283A8 1458008A */  bne       $v0, $t8, .L801285D4
/* BEAAC 801283AC 24190003 */   addiu    $t9, $zero, 3
/* BEAB0 801283B0 0000202D */  daddu     $a0, $zero, $zero
/* BEAB4 801283B4 3C053D8F */  lui       $a1, 0x3d8f
/* BEAB8 801283B8 34A55C29 */  ori       $a1, $a1, 0x5c29
/* BEABC 801283BC 3C063F80 */  lui       $a2, 0x3f80
/* BEAC0 801283C0 93C70509 */  lbu       $a3, 0x509($fp)
/* BEAC4 801283C4 24190007 */  addiu     $t9, $zero, 7
/* BEAC8 801283C8 0C00A8ED */  jal       update_lerp
/* BEACC 801283CC AFB90010 */   sw       $t9, 0x10($sp)
/* BEAD0 801283D0 3C053E99 */  lui       $a1, 0x3e99
/* BEAD4 801283D4 34A5999A */  ori       $a1, $a1, 0x999a
/* BEAD8 801283D8 3C063F80 */  lui       $a2, 0x3f80
/* BEADC 801283DC 0000202D */  daddu     $a0, $zero, $zero
/* BEAE0 801283E0 E7A000BC */  swc1      $f0, 0xbc($sp)
/* BEAE4 801283E4 93C70509 */  lbu       $a3, 0x509($fp)
/* BEAE8 801283E8 24180007 */  addiu     $t8, $zero, 7
/* BEAEC 801283EC 0C00A8ED */  jal       update_lerp
/* BEAF0 801283F0 AFB80010 */   sw       $t8, 0x10($sp)
/* BEAF4 801283F4 46000786 */  mov.s     $f30, $f0
/* BEAF8 801283F8 0000202D */  daddu     $a0, $zero, $zero
/* BEAFC 801283FC 3C0542C0 */  lui       $a1, 0x42c0
/* BEB00 80128400 3C064348 */  lui       $a2, 0x4348
/* BEB04 80128404 93C70509 */  lbu       $a3, 0x509($fp)
/* BEB08 80128408 24190007 */  addiu     $t9, $zero, 7
/* BEB0C 8012840C 0C00A8ED */  jal       update_lerp
/* BEB10 80128410 AFB90010 */   sw       $t9, 0x10($sp)
/* BEB14 80128414 46000706 */  mov.s     $f28, $f0
/* BEB18 80128418 2404000B */  addiu     $a0, $zero, 0xb
/* BEB1C 8012841C 00151400 */  sll       $v0, $s5, 0x10
/* BEB20 80128420 00021403 */  sra       $v0, $v0, 0x10
/* BEB24 80128424 44826000 */  mtc1      $v0, $f12
/* BEB28 80128428 00000000 */  nop
/* BEB2C 8012842C 46806320 */  cvt.s.w   $f12, $f12
/* BEB30 80128430 00131400 */  sll       $v0, $s3, 0x10
/* BEB34 80128434 00021403 */  sra       $v0, $v0, 0x10
/* BEB38 80128438 44056000 */  mfc1      $a1, $f12
/* BEB3C 8012843C 44826000 */  mtc1      $v0, $f12
/* BEB40 80128440 00000000 */  nop
/* BEB44 80128444 46806320 */  cvt.s.w   $f12, $f12
/* BEB48 80128448 93C70509 */  lbu       $a3, 0x509($fp)
/* BEB4C 8012844C 44066000 */  mfc1      $a2, $f12
/* BEB50 80128450 24180007 */  addiu     $t8, $zero, 7
/* BEB54 80128454 0C00A8ED */  jal       update_lerp
/* BEB58 80128458 AFB80010 */   sw       $t8, 0x10($sp)
/* BEB5C 8012845C 46000506 */  mov.s     $f20, $f0
/* BEB60 80128460 2404000B */  addiu     $a0, $zero, 0xb
/* BEB64 80128464 00161400 */  sll       $v0, $s6, 0x10
/* BEB68 80128468 00021403 */  sra       $v0, $v0, 0x10
/* BEB6C 8012846C 44826000 */  mtc1      $v0, $f12
/* BEB70 80128470 00000000 */  nop
/* BEB74 80128474 46806320 */  cvt.s.w   $f12, $f12
/* BEB78 80128478 00141400 */  sll       $v0, $s4, 0x10
/* BEB7C 8012847C 00021403 */  sra       $v0, $v0, 0x10
/* BEB80 80128480 44056000 */  mfc1      $a1, $f12
/* BEB84 80128484 44826000 */  mtc1      $v0, $f12
/* BEB88 80128488 00000000 */  nop
/* BEB8C 8012848C 46806320 */  cvt.s.w   $f12, $f12
/* BEB90 80128490 93C70509 */  lbu       $a3, 0x509($fp)
/* BEB94 80128494 44066000 */  mfc1      $a2, $f12
/* BEB98 80128498 24180007 */  addiu     $t8, $zero, 7
/* BEB9C 8012849C 0C00A8ED */  jal       update_lerp
/* BEBA0 801284A0 AFB80010 */   sw       $t8, 0x10($sp)
/* BEBA4 801284A4 97C20514 */  lhu       $v0, 0x514($fp)
/* BEBA8 801284A8 C7AC00BC */  lwc1      $f12, 0xbc($sp)
/* BEBAC 801284AC 44822000 */  mtc1      $v0, $f4
/* BEBB0 801284B0 00000000 */  nop
/* BEBB4 801284B4 46802120 */  cvt.s.w   $f4, $f4
/* BEBB8 801284B8 460C2102 */  mul.s     $f4, $f4, $f12
/* BEBBC 801284BC 00000000 */  nop
/* BEBC0 801284C0 3C013FE0 */  lui       $at, 0x3fe0
/* BEBC4 801284C4 44816800 */  mtc1      $at, $f13
/* BEBC8 801284C8 44806000 */  mtc1      $zero, $f12
/* BEBCC 801284CC 46002121 */  cvt.d.s   $f4, $f4
/* BEBD0 801284D0 462C2102 */  mul.d     $f4, $f4, $f12
/* BEBD4 801284D4 00000000 */  nop
/* BEBD8 801284D8 97C20516 */  lhu       $v0, 0x516($fp)
/* BEBDC 801284DC 44821000 */  mtc1      $v0, $f2
/* BEBE0 801284E0 00000000 */  nop
/* BEBE4 801284E4 468010A0 */  cvt.s.w   $f2, $f2
/* BEBE8 801284E8 461E1082 */  mul.s     $f2, $f2, $f30
/* BEBEC 801284EC 00000000 */  nop
/* BEBF0 801284F0 460010A1 */  cvt.d.s   $f2, $f2
/* BEBF4 801284F4 462C1082 */  mul.d     $f2, $f2, $f12
/* BEBF8 801284F8 00000000 */  nop
/* BEBFC 801284FC 46000021 */  cvt.d.s   $f0, $f0
/* BEC00 80128500 46240001 */  sub.d     $f0, $f0, $f4
/* BEC04 80128504 4600A121 */  cvt.d.s   $f4, $f20
/* BEC08 80128508 46222101 */  sub.d     $f4, $f4, $f2
/* BEC0C 8012850C AFB20010 */  sw        $s2, 0x10($sp)
/* BEC10 80128510 3C014F00 */  lui       $at, 0x4f00
/* BEC14 80128514 44811000 */  mtc1      $at, $f2
/* BEC18 80128518 462C0000 */  add.d     $f0, $f0, $f12
/* BEC1C 8012851C AFB10014 */  sw        $s1, 0x14($sp)
/* BEC20 80128520 E7BE001C */  swc1      $f30, 0x1c($sp)
/* BEC24 80128524 461C103E */  c.le.s    $f2, $f28
/* BEC28 80128528 462C2100 */  add.d     $f4, $f4, $f12
/* BEC2C 8012852C C7AC00BC */  lwc1      $f12, 0xbc($sp)
/* BEC30 80128530 46200620 */  cvt.s.d   $f24, $f0
/* BEC34 80128534 E7AC0018 */  swc1      $f12, 0x18($sp)
/* BEC38 80128538 4600C30D */  trunc.w.s $f12, $f24
/* BEC3C 8012853C 44026000 */  mfc1      $v0, $f12
/* BEC40 80128540 00000000 */  nop
/* BEC44 80128544 00021400 */  sll       $v0, $v0, 0x10
/* BEC48 80128548 00022C03 */  sra       $a1, $v0, 0x10
/* BEC4C 8012854C 462026A0 */  cvt.s.d   $f26, $f4
/* BEC50 80128550 4600D30D */  trunc.w.s $f12, $f26
/* BEC54 80128554 44026000 */  mfc1      $v0, $f12
/* BEC58 80128558 00000000 */  nop
/* BEC5C 8012855C 00021400 */  sll       $v0, $v0, 0x10
/* BEC60 80128560 00023403 */  sra       $a2, $v0, 0x10
/* BEC64 80128564 00101400 */  sll       $v0, $s0, 0x10
/* BEC68 80128568 45010005 */  bc1t      .L80128580
/* BEC6C 8012856C 00023C03 */   sra      $a3, $v0, 0x10
/* BEC70 80128570 4600E30D */  trunc.w.s $f12, $f28
/* BEC74 80128574 44036000 */  mfc1      $v1, $f12
/* BEC78 80128578 0804A167 */  j         .L8012859C
/* BEC7C 8012857C 03C0202D */   daddu    $a0, $fp, $zero
.L80128580:
/* BEC80 80128580 4602E001 */  sub.s     $f0, $f28, $f2
/* BEC84 80128584 3C028000 */  lui       $v0, 0x8000
/* BEC88 80128588 4600030D */  trunc.w.s $f12, $f0
/* BEC8C 8012858C 44036000 */  mfc1      $v1, $f12
/* BEC90 80128590 00000000 */  nop
/* BEC94 80128594 00621825 */  or        $v1, $v1, $v0
/* BEC98 80128598 03C0202D */  daddu     $a0, $fp, $zero
.L8012859C:
/* BEC9C 8012859C 306200FF */  andi      $v0, $v1, 0xff
/* BECA0 801285A0 24190001 */  addiu     $t9, $zero, 1
/* BECA4 801285A4 AFA20020 */  sw        $v0, 0x20($sp)
/* BECA8 801285A8 0C04B302 */  jal       msg_draw_speech_bubble
/* BECAC 801285AC AFB90024 */   sw       $t9, 0x24($sp)
/* BECB0 801285B0 93C20509 */  lbu       $v0, 0x509($fp)
/* BECB4 801285B4 24180007 */  addiu     $t8, $zero, 7
/* BECB8 801285B8 24420001 */  addiu     $v0, $v0, 1
/* BECBC 801285BC A3C20509 */  sb        $v0, 0x509($fp)
/* BECC0 801285C0 304200FF */  andi      $v0, $v0, 0xff
/* BECC4 801285C4 145800D8 */  bne       $v0, $t8, .L80128928
/* BECC8 801285C8 24020004 */   addiu    $v0, $zero, 4
/* BECCC 801285CC 0804A24A */  j         .L80128928
/* BECD0 801285D0 A3C204F8 */   sb       $v0, 0x4f8($fp)
.L801285D4:
/* BECD4 801285D4 145900A2 */  bne       $v0, $t9, .L80128860
/* BECD8 801285D8 03C0202D */   daddu    $a0, $fp, $zero
/* BECDC 801285DC 0000202D */  daddu     $a0, $zero, $zero
/* BECE0 801285E0 3C053F80 */  lui       $a1, 0x3f80
/* BECE4 801285E4 93C20512 */  lbu       $v0, 0x512($fp)
/* BECE8 801285E8 3C063F19 */  lui       $a2, 0x3f19
/* BECEC 801285EC 34C6999A */  ori       $a2, $a2, 0x999a
/* BECF0 801285F0 24420001 */  addiu     $v0, $v0, 1
/* BECF4 801285F4 A3C20512 */  sb        $v0, 0x512($fp)
/* BECF8 801285F8 304700FF */  andi      $a3, $v0, 0xff
/* BECFC 801285FC 24180005 */  addiu     $t8, $zero, 5
/* BED00 80128600 0C00A8ED */  jal       update_lerp
/* BED04 80128604 AFB80010 */   sw       $t8, 0x10($sp)
/* BED08 80128608 3C053F80 */  lui       $a1, 0x3f80
/* BED0C 8012860C 3C063F4C */  lui       $a2, 0x3f4c
/* BED10 80128610 34C6CCCD */  ori       $a2, $a2, 0xcccd
/* BED14 80128614 0000202D */  daddu     $a0, $zero, $zero
/* BED18 80128618 E7A000BC */  swc1      $f0, 0xbc($sp)
/* BED1C 8012861C 93C70512 */  lbu       $a3, 0x512($fp)
/* BED20 80128620 24190005 */  addiu     $t9, $zero, 5
/* BED24 80128624 0C00A8ED */  jal       update_lerp
/* BED28 80128628 AFB90010 */   sw       $t9, 0x10($sp)
/* BED2C 8012862C 97C20514 */  lhu       $v0, 0x514($fp)
/* BED30 80128630 C7AC00BC */  lwc1      $f12, 0xbc($sp)
/* BED34 80128634 44821000 */  mtc1      $v0, $f2
/* BED38 80128638 00000000 */  nop
/* BED3C 8012863C 468010A0 */  cvt.s.w   $f2, $f2
/* BED40 80128640 460C1082 */  mul.s     $f2, $f2, $f12
/* BED44 80128644 00000000 */  nop
/* BED48 80128648 3C013FE0 */  lui       $at, 0x3fe0
/* BED4C 8012864C 44816800 */  mtc1      $at, $f13
/* BED50 80128650 44806000 */  mtc1      $zero, $f12
/* BED54 80128654 460010A1 */  cvt.d.s   $f2, $f2
/* BED58 80128658 462C1082 */  mul.d     $f2, $f2, $f12
/* BED5C 8012865C 00000000 */  nop
/* BED60 80128660 97C20516 */  lhu       $v0, 0x516($fp)
/* BED64 80128664 46000786 */  mov.s     $f30, $f0
/* BED68 80128668 44820000 */  mtc1      $v0, $f0
/* BED6C 8012866C 00000000 */  nop
/* BED70 80128670 46800020 */  cvt.s.w   $f0, $f0
/* BED74 80128674 461E0002 */  mul.s     $f0, $f0, $f30
/* BED78 80128678 00000000 */  nop
/* BED7C 8012867C 46000021 */  cvt.d.s   $f0, $f0
/* BED80 80128680 462C0002 */  mul.d     $f0, $f0, $f12
/* BED84 80128684 00000000 */  nop
/* BED88 80128688 00141400 */  sll       $v0, $s4, 0x10
/* BED8C 8012868C 00021403 */  sra       $v0, $v0, 0x10
/* BED90 80128690 4482B000 */  mtc1      $v0, $f22
/* BED94 80128694 00000000 */  nop
/* BED98 80128698 4680B5A0 */  cvt.s.w   $f22, $f22
/* BED9C 8012869C 4600B5A1 */  cvt.d.s   $f22, $f22
/* BEDA0 801286A0 4622B181 */  sub.d     $f6, $f22, $f2
/* BEDA4 801286A4 00131400 */  sll       $v0, $s3, 0x10
/* BEDA8 801286A8 00021403 */  sra       $v0, $v0, 0x10
/* BEDAC 801286AC 4622B580 */  add.d     $f22, $f22, $f2
/* BEDB0 801286B0 4482A000 */  mtc1      $v0, $f20
/* BEDB4 801286B4 00000000 */  nop
/* BEDB8 801286B8 4680A520 */  cvt.s.w   $f20, $f20
/* BEDBC 801286BC 4600A521 */  cvt.d.s   $f20, $f20
/* BEDC0 801286C0 4620A101 */  sub.d     $f4, $f20, $f0
/* BEDC4 801286C4 4620A500 */  add.d     $f20, $f20, $f0
/* BEDC8 801286C8 462C3180 */  add.d     $f6, $f6, $f12
/* BEDCC 801286CC 0000202D */  daddu     $a0, $zero, $zero
/* BEDD0 801286D0 3C05437F */  lui       $a1, 0x437f
/* BEDD4 801286D4 462CB581 */  sub.d     $f22, $f22, $f12
/* BEDD8 801286D8 3C064280 */  lui       $a2, 0x4280
/* BEDDC 801286DC 93C70512 */  lbu       $a3, 0x512($fp)
/* BEDE0 801286E0 462C2100 */  add.d     $f4, $f4, $f12
/* BEDE4 801286E4 24180005 */  addiu     $t8, $zero, 5
/* BEDE8 801286E8 AFB80010 */  sw        $t8, 0x10($sp)
/* BEDEC 801286EC 462CA501 */  sub.d     $f20, $f20, $f12
/* BEDF0 801286F0 46203620 */  cvt.s.d   $f24, $f6
/* BEDF4 801286F4 4620B5A0 */  cvt.s.d   $f22, $f22
/* BEDF8 801286F8 462026A0 */  cvt.s.d   $f26, $f4
/* BEDFC 801286FC 0C00A8ED */  jal       update_lerp
/* BEE00 80128700 4620A520 */   cvt.s.d  $f20, $f20
/* BEE04 80128704 46000706 */  mov.s     $f28, $f0
/* BEE08 80128708 3C018015 */  lui       $at, %hi(D_801507B0)
/* BEE0C 8012870C D42007B0 */  ldc1      $f0, %lo(D_801507B0)($at)
/* BEE10 80128710 4600E1A1 */  cvt.d.s   $f6, $f28
/* BEE14 80128714 46203182 */  mul.d     $f6, $f6, $f0
/* BEE18 80128718 00000000 */  nop
/* BEE1C 8012871C 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* BEE20 80128720 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* BEE24 80128724 4600E30D */  trunc.w.s $f12, $f28
/* BEE28 80128728 44046000 */  mfc1      $a0, $f12
/* BEE2C 8012872C 00000000 */  nop
/* BEE30 80128730 A7A400AE */  sh        $a0, 0xae($sp)
/* BEE34 80128734 84430046 */  lh        $v1, 0x46($v0)
/* BEE38 80128738 3C014F00 */  lui       $at, 0x4f00
/* BEE3C 8012873C 44814000 */  mtc1      $at, $f8
/* BEE40 80128740 44831000 */  mtc1      $v1, $f2
/* BEE44 80128744 00000000 */  nop
/* BEE48 80128748 468010A0 */  cvt.s.w   $f2, $f2
/* BEE4C 8012874C 84430048 */  lh        $v1, 0x48($v0)
/* BEE50 80128750 4602C080 */  add.s     $f2, $f24, $f2
/* BEE54 80128754 44832000 */  mtc1      $v1, $f4
/* BEE58 80128758 00000000 */  nop
/* BEE5C 8012875C 46802120 */  cvt.s.w   $f4, $f4
/* BEE60 80128760 84430046 */  lh        $v1, 0x46($v0)
/* BEE64 80128764 4604D100 */  add.s     $f4, $f26, $f4
/* BEE68 80128768 44830000 */  mtc1      $v1, $f0
/* BEE6C 8012876C 00000000 */  nop
/* BEE70 80128770 46800020 */  cvt.s.w   $f0, $f0
/* BEE74 80128774 84430048 */  lh        $v1, 0x48($v0)
/* BEE78 80128778 4600B581 */  sub.s     $f22, $f22, $f0
/* BEE7C 8012877C 4600130D */  trunc.w.s $f12, $f2
/* BEE80 80128780 E44C0000 */  swc1      $f12, ($v0)
/* BEE84 80128784 44830000 */  mtc1      $v1, $f0
/* BEE88 80128788 00000000 */  nop
/* BEE8C 8012878C 46800020 */  cvt.s.w   $f0, $f0
/* BEE90 80128790 4600A501 */  sub.s     $f20, $f20, $f0
/* BEE94 80128794 4600230D */  trunc.w.s $f12, $f4
/* BEE98 80128798 E44C0008 */  swc1      $f12, 8($v0)
/* BEE9C 8012879C 4600B30D */  trunc.w.s $f12, $f22
/* BEEA0 801287A0 E44C0004 */  swc1      $f12, 4($v0)
/* BEEA4 801287A4 4600A30D */  trunc.w.s $f12, $f20
/* BEEA8 801287A8 E44C000C */  swc1      $f12, 0xc($v0)
/* BEEAC 801287AC C7AC00BC */  lwc1      $f12, 0xbc($sp)
/* BEEB0 801287B0 461C403E */  c.le.s    $f8, $f28
/* BEEB4 801287B4 AFB20010 */  sw        $s2, 0x10($sp)
/* BEEB8 801287B8 AFB10014 */  sw        $s1, 0x14($sp)
/* BEEBC 801287BC E7BE001C */  swc1      $f30, 0x1c($sp)
/* BEEC0 801287C0 E7AC0018 */  swc1      $f12, 0x18($sp)
/* BEEC4 801287C4 4620330D */  trunc.w.d $f12, $f6
/* BEEC8 801287C8 44186000 */  mfc1      $t8, $f12
/* BEECC 801287CC 00000000 */  nop
/* BEED0 801287D0 A7B8008E */  sh        $t8, 0x8e($sp)
/* BEED4 801287D4 4600C30D */  trunc.w.s $f12, $f24
/* BEED8 801287D8 44026000 */  mfc1      $v0, $f12
/* BEEDC 801287DC 00000000 */  nop
/* BEEE0 801287E0 00021400 */  sll       $v0, $v0, 0x10
/* BEEE4 801287E4 00022C03 */  sra       $a1, $v0, 0x10
/* BEEE8 801287E8 4600D30D */  trunc.w.s $f12, $f26
/* BEEEC 801287EC 44026000 */  mfc1      $v0, $f12
/* BEEF0 801287F0 00000000 */  nop
/* BEEF4 801287F4 00021400 */  sll       $v0, $v0, 0x10
/* BEEF8 801287F8 00023403 */  sra       $a2, $v0, 0x10
/* BEEFC 801287FC 00101400 */  sll       $v0, $s0, 0x10
/* BEF00 80128800 45010003 */  bc1t      .L80128810
/* BEF04 80128804 00023C03 */   sra      $a3, $v0, 0x10
/* BEF08 80128808 0804A20A */  j         .L80128828
/* BEF0C 8012880C 0080182D */   daddu    $v1, $a0, $zero
.L80128810:
/* BEF10 80128810 4608E001 */  sub.s     $f0, $f28, $f8
/* BEF14 80128814 3C028000 */  lui       $v0, 0x8000
/* BEF18 80128818 4600030D */  trunc.w.s $f12, $f0
/* BEF1C 8012881C 44036000 */  mfc1      $v1, $f12
/* BEF20 80128820 00000000 */  nop
/* BEF24 80128824 00621825 */  or        $v1, $v1, $v0
.L80128828:
/* BEF28 80128828 03C0202D */  daddu     $a0, $fp, $zero
/* BEF2C 8012882C 306200FF */  andi      $v0, $v1, 0xff
/* BEF30 80128830 24190001 */  addiu     $t9, $zero, 1
/* BEF34 80128834 AFA20020 */  sw        $v0, 0x20($sp)
/* BEF38 80128838 0C04B302 */  jal       msg_draw_speech_bubble
/* BEF3C 8012883C AFB90024 */   sw       $t9, 0x24($sp)
/* BEF40 80128840 93C20512 */  lbu       $v0, 0x512($fp)
/* BEF44 80128844 2C420005 */  sltiu     $v0, $v0, 5
/* BEF48 80128848 14400037 */  bnez      $v0, .L80128928
/* BEF4C 8012884C 00000000 */   nop
/* BEF50 80128850 8FC204FC */  lw        $v0, 0x4fc($fp)
/* BEF54 80128854 34420001 */  ori       $v0, $v0, 1
/* BEF58 80128858 0804A24A */  j         .L80128928
/* BEF5C 8012885C AFC204FC */   sw       $v0, 0x4fc($fp)
.L80128860:
/* BEF60 80128860 00103C00 */  sll       $a3, $s0, 0x10
/* BEF64 80128864 87C3045A */  lh        $v1, 0x45a($fp)
/* BEF68 80128868 87C5045C */  lh        $a1, 0x45c($fp)
/* BEF6C 8012886C 3C013F80 */  lui       $at, 0x3f80
/* BEF70 80128870 44816000 */  mtc1      $at, $f12
/* BEF74 80128874 241800FF */  addiu     $t8, $zero, 0xff
/* BEF78 80128878 AFB80020 */  sw        $t8, 0x20($sp)
/* BEF7C 8012887C 97B80066 */  lhu       $t8, 0x66($sp)
/* BEF80 80128880 24190001 */  addiu     $t9, $zero, 1
/* BEF84 80128884 AFB90024 */  sw        $t9, 0x24($sp)
/* BEF88 80128888 97B9006E */  lhu       $t9, 0x6e($sp)
/* BEF8C 8012888C 00073C03 */  sra       $a3, $a3, 0x10
/* BEF90 80128890 AFB20010 */  sw        $s2, 0x10($sp)
/* BEF94 80128894 AFB10014 */  sw        $s1, 0x14($sp)
/* BEF98 80128898 00181400 */  sll       $v0, $t8, 0x10
/* BEF9C 8012889C 00021403 */  sra       $v0, $v0, 0x10
/* BEFA0 801288A0 00431021 */  addu      $v0, $v0, $v1
/* BEFA4 801288A4 4482C000 */  mtc1      $v0, $f24
/* BEFA8 801288A8 00000000 */  nop
/* BEFAC 801288AC 4680C620 */  cvt.s.w   $f24, $f24
/* BEFB0 801288B0 00191400 */  sll       $v0, $t9, 0x10
/* BEFB4 801288B4 00021403 */  sra       $v0, $v0, 0x10
/* BEFB8 801288B8 00451021 */  addu      $v0, $v0, $a1
/* BEFBC 801288BC 4482D000 */  mtc1      $v0, $f26
/* BEFC0 801288C0 00000000 */  nop
/* BEFC4 801288C4 4680D6A0 */  cvt.s.w   $f26, $f26
/* BEFC8 801288C8 E7AC0018 */  swc1      $f12, 0x18($sp)
/* BEFCC 801288CC E7AC001C */  swc1      $f12, 0x1c($sp)
/* BEFD0 801288D0 4600C30D */  trunc.w.s $f12, $f24
/* BEFD4 801288D4 44056000 */  mfc1      $a1, $f12
/* BEFD8 801288D8 00000000 */  nop
/* BEFDC 801288DC 00052C00 */  sll       $a1, $a1, 0x10
/* BEFE0 801288E0 00052C03 */  sra       $a1, $a1, 0x10
/* BEFE4 801288E4 4600D30D */  trunc.w.s $f12, $f26
/* BEFE8 801288E8 44066000 */  mfc1      $a2, $f12
/* BEFEC 801288EC 00000000 */  nop
/* BEFF0 801288F0 00063400 */  sll       $a2, $a2, 0x10
/* BEFF4 801288F4 0C04B302 */  jal       msg_draw_speech_bubble
/* BEFF8 801288F8 00063403 */   sra      $a2, $a2, 0x10
/* BEFFC 801288FC 97C2050E */  lhu       $v0, 0x50e($fp)
/* BF000 80128900 2442FFEC */  addiu     $v0, $v0, -0x14
/* BF004 80128904 2C420119 */  sltiu     $v0, $v0, 0x119
/* BF008 80128908 10400007 */  beqz      $v0, .L80128928
/* BF00C 8012890C 00000000 */   nop
/* BF010 80128910 97C20510 */  lhu       $v0, 0x510($fp)
/* BF014 80128914 2C4200DD */  sltiu     $v0, $v0, 0xdd
/* BF018 80128918 10400003 */  beqz      $v0, .L80128928
/* BF01C 8012891C 00000000 */   nop
/* BF020 80128920 0C04B4F7 */  jal       msg_draw_speech_arrow
/* BF024 80128924 03C0202D */   daddu    $a0, $fp, $zero
.L80128928:
/* BF028 80128928 93C204F8 */  lbu       $v0, 0x4f8($fp)
/* BF02C 8012892C 24190003 */  addiu     $t9, $zero, 3
/* BF030 80128930 10590466 */  beq       $v0, $t9, .L80129ACC
/* BF034 80128934 24020014 */   addiu    $v0, $zero, 0x14
/* BF038 80128938 3C048015 */  lui       $a0, %hi(gMessageDrawStatePtr)
/* BF03C 8012893C 8C845D74 */  lw        $a0, %lo(gMessageDrawStatePtr)($a0)
/* BF040 80128940 AC820000 */  sw        $v0, ($a0)
/* BF044 80128944 87C30458 */  lh        $v1, 0x458($fp)
/* BF048 80128948 87C5045C */  lh        $a1, 0x45c($fp)
/* BF04C 8012894C 2402012C */  addiu     $v0, $zero, 0x12c
/* BF050 80128950 AC820004 */  sw        $v0, 4($a0)
/* BF054 80128954 84820048 */  lh        $v0, 0x48($a0)
/* BF058 80128958 00651821 */  addu      $v1, $v1, $a1
/* BF05C 8012895C 00621821 */  addu      $v1, $v1, $v0
/* BF060 80128960 AC830008 */  sw        $v1, 8($a0)
/* BF064 80128964 97C30516 */  lhu       $v1, 0x516($fp)
/* BF068 80128968 8C820008 */  lw        $v0, 8($a0)
/* BF06C 8012896C 00431021 */  addu      $v0, $v0, $v1
/* BF070 80128970 2442FFF0 */  addiu     $v0, $v0, -0x10
/* BF074 80128974 0804A6B3 */  j         .L80129ACC
/* BF078 80128978 AC82000C */   sw       $v0, 0xc($a0)
glabel L8012897C_BF07C
/* BF07C 8012897C 0000A82D */  daddu     $s5, $zero, $zero
/* BF080 80128980 97D20514 */  lhu       $s2, 0x514($fp)
/* BF084 80128984 97D30516 */  lhu       $s3, 0x516($fp)
/* BF088 80128988 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* BF08C 8012898C 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* BF090 80128990 A040002B */  sb        $zero, 0x2b($v0)
/* BF094 80128994 3C038015 */  lui       $v1, %hi(gMessageDrawStatePtr)
/* BF098 80128998 8C635D74 */  lw        $v1, %lo(gMessageDrawStatePtr)($v1)
/* BF09C 8012899C 2402000C */  addiu     $v0, $zero, 0xc
/* BF0A0 801289A0 A4620046 */  sh        $v0, 0x46($v1)
/* BF0A4 801289A4 24020006 */  addiu     $v0, $zero, 6
/* BF0A8 801289A8 A4620048 */  sh        $v0, 0x48($v1)
/* BF0AC 801289AC 93C204F8 */  lbu       $v0, 0x4f8($fp)
/* BF0B0 801289B0 24180002 */  addiu     $t8, $zero, 2
/* BF0B4 801289B4 14580078 */  bne       $v0, $t8, .L80128B98
/* BF0B8 801289B8 241400FF */   addiu    $s4, $zero, 0xff
/* BF0BC 801289BC 93C20509 */  lbu       $v0, 0x509($fp)
/* BF0C0 801289C0 24030006 */  addiu     $v1, $zero, 6
/* BF0C4 801289C4 24420001 */  addiu     $v0, $v0, 1
/* BF0C8 801289C8 A3C20509 */  sb        $v0, 0x509($fp)
/* BF0CC 801289CC 304200FF */  andi      $v0, $v0, 0xff
/* BF0D0 801289D0 14430002 */  bne       $v0, $v1, .L801289DC
/* BF0D4 801289D4 24020004 */   addiu    $v0, $zero, 4
/* BF0D8 801289D8 A3C204F8 */  sb        $v0, 0x4f8($fp)
.L801289DC:
/* BF0DC 801289DC 93C20509 */  lbu       $v0, 0x509($fp)
/* BF0E0 801289E0 3C018015 */  lui       $at, %hi(D_801507B8)
/* BF0E4 801289E4 D42207B8 */  ldc1      $f2, %lo(D_801507B8)($at)
/* BF0E8 801289E8 44820000 */  mtc1      $v0, $f0
/* BF0EC 801289EC 00000000 */  nop
/* BF0F0 801289F0 46800020 */  cvt.s.w   $f0, $f0
/* BF0F4 801289F4 46000021 */  cvt.d.s   $f0, $f0
/* BF0F8 801289F8 46220002 */  mul.d     $f0, $f0, $f2
/* BF0FC 801289FC 00000000 */  nop
/* BF100 80128A00 3C018015 */  lui       $at, %hi(D_801507C0)
/* BF104 80128A04 D42207C0 */  ldc1      $f2, %lo(D_801507C0)($at)
/* BF108 80128A08 46220000 */  add.d     $f0, $f0, $f2
/* BF10C 80128A0C 44922000 */  mtc1      $s2, $f4
/* BF110 80128A10 00000000 */  nop
/* BF114 80128A14 46802120 */  cvt.s.w   $f4, $f4
/* BF118 80128A18 462002A0 */  cvt.s.d   $f10, $f0
/* BF11C 80128A1C 460A2102 */  mul.s     $f4, $f4, $f10
/* BF120 80128A20 00000000 */  nop
/* BF124 80128A24 3C013FE0 */  lui       $at, 0x3fe0
/* BF128 80128A28 44816800 */  mtc1      $at, $f13
/* BF12C 80128A2C 44806000 */  mtc1      $zero, $f12
/* BF130 80128A30 46002121 */  cvt.d.s   $f4, $f4
/* BF134 80128A34 462C2002 */  mul.d     $f0, $f4, $f12
/* BF138 80128A38 00000000 */  nop
/* BF13C 80128A3C 44933000 */  mtc1      $s3, $f6
/* BF140 80128A40 00000000 */  nop
/* BF144 80128A44 468031A0 */  cvt.s.w   $f6, $f6
/* BF148 80128A48 460A3182 */  mul.s     $f6, $f6, $f10
/* BF14C 80128A4C 00000000 */  nop
/* BF150 80128A50 87C3045A */  lh        $v1, 0x45a($fp)
/* BF154 80128A54 001217C2 */  srl       $v0, $s2, 0x1f
/* BF158 80128A58 02421021 */  addu      $v0, $s2, $v0
/* BF15C 80128A5C 460031A1 */  cvt.d.s   $f6, $f6
/* BF160 80128A60 462C3202 */  mul.d     $f8, $f6, $f12
/* BF164 80128A64 00000000 */  nop
/* BF168 80128A68 00021043 */  sra       $v0, $v0, 1
/* BF16C 80128A6C 00621821 */  addu      $v1, $v1, $v0
/* BF170 80128A70 001317C2 */  srl       $v0, $s3, 0x1f
/* BF174 80128A74 02621021 */  addu      $v0, $s3, $v0
/* BF178 80128A78 00021043 */  sra       $v0, $v0, 1
/* BF17C 80128A7C 44831000 */  mtc1      $v1, $f2
/* BF180 80128A80 00000000 */  nop
/* BF184 80128A84 468010A0 */  cvt.s.w   $f2, $f2
/* BF188 80128A88 87C3045C */  lh        $v1, 0x45c($fp)
/* BF18C 80128A8C 462C2100 */  add.d     $f4, $f4, $f12
/* BF190 80128A90 460010A1 */  cvt.d.s   $f2, $f2
/* BF194 80128A94 00621821 */  addu      $v1, $v1, $v0
/* BF198 80128A98 46201081 */  sub.d     $f2, $f2, $f0
/* BF19C 80128A9C 44830000 */  mtc1      $v1, $f0
/* BF1A0 80128AA0 00000000 */  nop
/* BF1A4 80128AA4 46800020 */  cvt.s.w   $f0, $f0
/* BF1A8 80128AA8 46000021 */  cvt.d.s   $f0, $f0
/* BF1AC 80128AAC 46280001 */  sub.d     $f0, $f0, $f8
/* BF1B0 80128AB0 462010A0 */  cvt.s.d   $f2, $f2
/* BF1B4 80128AB4 460010A1 */  cvt.d.s   $f2, $f2
/* BF1B8 80128AB8 462C1080 */  add.d     $f2, $f2, $f12
/* BF1BC 80128ABC 4620230D */  trunc.w.d $f12, $f4
/* BF1C0 80128AC0 44126000 */  mfc1      $s2, $f12
/* BF1C4 80128AC4 3C013FE0 */  lui       $at, 0x3fe0
/* BF1C8 80128AC8 44816800 */  mtc1      $at, $f13
/* BF1CC 80128ACC 44806000 */  mtc1      $zero, $f12
/* BF1D0 80128AD0 46200020 */  cvt.s.d   $f0, $f0
/* BF1D4 80128AD4 462C3180 */  add.d     $f6, $f6, $f12
/* BF1D8 80128AD8 46000021 */  cvt.d.s   $f0, $f0
/* BF1DC 80128ADC 2A420018 */  slti      $v0, $s2, 0x18
/* BF1E0 80128AE0 462C0000 */  add.d     $f0, $f0, $f12
/* BF1E4 80128AE4 4620330D */  trunc.w.d $f12, $f6
/* BF1E8 80128AE8 44136000 */  mfc1      $s3, $f12
/* BF1EC 80128AEC 4620130D */  trunc.w.d $f12, $f2
/* BF1F0 80128AF0 44116000 */  mfc1      $s1, $f12
/* BF1F4 80128AF4 4620030D */  trunc.w.d $f12, $f0
/* BF1F8 80128AF8 44106000 */  mfc1      $s0, $f12
/* BF1FC 80128AFC 54400001 */  bnel      $v0, $zero, .L80128B04
/* BF200 80128B00 24120018 */   addiu    $s2, $zero, 0x18
.L80128B04:
/* BF204 80128B04 2A620018 */  slti      $v0, $s3, 0x18
/* BF208 80128B08 54400001 */  bnel      $v0, $zero, .L80128B10
/* BF20C 80128B0C 24130018 */   addiu    $s3, $zero, 0x18
.L80128B10:
/* BF210 80128B10 3C018015 */  lui       $at, %hi(D_801507C8)
/* BF214 80128B14 D42207C8 */  ldc1      $f2, %lo(D_801507C8)($at)
/* BF218 80128B18 46005021 */  cvt.d.s   $f0, $f10
/* BF21C 80128B1C 46220002 */  mul.d     $f0, $f0, $f2
/* BF220 80128B20 00000000 */  nop
/* BF224 80128B24 3C0141E0 */  lui       $at, 0x41e0
/* BF228 80128B28 44811800 */  mtc1      $at, $f3
/* BF22C 80128B2C 44801000 */  mtc1      $zero, $f2
/* BF230 80128B30 00000000 */  nop
/* BF234 80128B34 4620103E */  c.le.d    $f2, $f0
/* BF238 80128B38 00000000 */  nop
/* BF23C 80128B3C 45030005 */  bc1tl     .L80128B54
/* BF240 80128B40 46220001 */   sub.d    $f0, $f0, $f2
/* BF244 80128B44 4620030D */  trunc.w.d $f12, $f0
/* BF248 80128B48 44036000 */  mfc1      $v1, $f12
/* BF24C 80128B4C 0804A2DB */  j         .L80128B6C
/* BF250 80128B50 306200FF */   andi     $v0, $v1, 0xff
.L80128B54:
/* BF254 80128B54 3C028000 */  lui       $v0, 0x8000
/* BF258 80128B58 4620030D */  trunc.w.d $f12, $f0
/* BF25C 80128B5C 44036000 */  mfc1      $v1, $f12
/* BF260 80128B60 00000000 */  nop
/* BF264 80128B64 00621825 */  or        $v1, $v1, $v0
/* BF268 80128B68 306200FF */  andi      $v0, $v1, 0xff
.L80128B6C:
/* BF26C 80128B6C 3C018015 */  lui       $at, %hi(D_801507D0)
/* BF270 80128B70 D42207D0 */  ldc1      $f2, %lo(D_801507D0)($at)
/* BF274 80128B74 44820000 */  mtc1      $v0, $f0
/* BF278 80128B78 00000000 */  nop
/* BF27C 80128B7C 46800021 */  cvt.d.w   $f0, $f0
/* BF280 80128B80 46220002 */  mul.d     $f0, $f0, $f2
/* BF284 80128B84 00000000 */  nop
/* BF288 80128B88 4620030D */  trunc.w.d $f12, $f0
/* BF28C 80128B8C 44186000 */  mfc1      $t8, $f12
/* BF290 80128B90 0804A323 */  j         .L80128C8C
/* BF294 80128B94 A7B8008E */   sh       $t8, 0x8e($sp)
.L80128B98:
/* BF298 80128B98 24180003 */  addiu     $t8, $zero, 3
/* BF29C 80128B9C 14580029 */  bne       $v0, $t8, .L80128C44
/* BF2A0 80128BA0 240400FF */   addiu    $a0, $zero, 0xff
/* BF2A4 80128BA4 93C20512 */  lbu       $v0, 0x512($fp)
/* BF2A8 80128BA8 24420001 */  addiu     $v0, $v0, 1
/* BF2AC 80128BAC A3C20512 */  sb        $v0, 0x512($fp)
/* BF2B0 80128BB0 304200FF */  andi      $v0, $v0, 0xff
/* BF2B4 80128BB4 2C420005 */  sltiu     $v0, $v0, 5
/* BF2B8 80128BB8 14400004 */  bnez      $v0, .L80128BCC
/* BF2BC 80128BBC 00000000 */   nop
/* BF2C0 80128BC0 8FC204FC */  lw        $v0, 0x4fc($fp)
/* BF2C4 80128BC4 34420001 */  ori       $v0, $v0, 1
/* BF2C8 80128BC8 AFC204FC */  sw        $v0, 0x4fc($fp)
.L80128BCC:
/* BF2CC 80128BCC 93C30512 */  lbu       $v1, 0x512($fp)
/* BF2D0 80128BD0 3C018015 */  lui       $at, %hi(D_801507D8)
/* BF2D4 80128BD4 D42207D8 */  ldc1      $f2, %lo(D_801507D8)($at)
/* BF2D8 80128BD8 00031040 */  sll       $v0, $v1, 1
/* BF2DC 80128BDC 00431021 */  addu      $v0, $v0, $v1
/* BF2E0 80128BE0 000210C0 */  sll       $v0, $v0, 3
/* BF2E4 80128BE4 00431023 */  subu      $v0, $v0, $v1
/* BF2E8 80128BE8 00021040 */  sll       $v0, $v0, 1
/* BF2EC 80128BEC 0002A027 */  nor       $s4, $zero, $v0
/* BF2F0 80128BF0 328200FF */  andi      $v0, $s4, 0xff
/* BF2F4 80128BF4 44820000 */  mtc1      $v0, $f0
/* BF2F8 80128BF8 00000000 */  nop
/* BF2FC 80128BFC 46800021 */  cvt.d.w   $f0, $f0
/* BF300 80128C00 46220002 */  mul.d     $f0, $f0, $f2
/* BF304 80128C04 00000000 */  nop
/* BF308 80128C08 24150001 */  addiu     $s5, $zero, 1
/* BF30C 80128C0C 4620030D */  trunc.w.d $f12, $f0
/* BF310 80128C10 44036000 */  mfc1      $v1, $f12
/* BF314 80128C14 00000000 */  nop
/* BF318 80128C18 00031400 */  sll       $v0, $v1, 0x10
/* BF31C 80128C1C 00021403 */  sra       $v0, $v0, 0x10
/* BF320 80128C20 28420020 */  slti      $v0, $v0, 0x20
/* BF324 80128C24 14400003 */  bnez      $v0, .L80128C34
/* BF328 80128C28 A7A3008E */   sh       $v1, 0x8e($sp)
/* BF32C 80128C2C 2463FFE0 */  addiu     $v1, $v1, -0x20
/* BF330 80128C30 A7A3008E */  sh        $v1, 0x8e($sp)
.L80128C34:
/* BF334 80128C34 87D1045A */  lh        $s1, 0x45a($fp)
/* BF338 80128C38 87D0045C */  lh        $s0, 0x45c($fp)
/* BF33C 80128C3C 0804A324 */  j         .L80128C90
/* BF340 80128C40 0220202D */   daddu    $a0, $s1, $zero
.L80128C44:
/* BF344 80128C44 24050020 */  addiu     $a1, $zero, 0x20
/* BF348 80128C48 00A0302D */  daddu     $a2, $a1, $zero
/* BF34C 80128C4C 0000382D */  daddu     $a3, $zero, $zero
/* BF350 80128C50 26420002 */  addiu     $v0, $s2, 2
/* BF354 80128C54 87D1045A */  lh        $s1, 0x45a($fp)
/* BF358 80128C58 87D0045C */  lh        $s0, 0x45c($fp)
/* BF35C 80128C5C 3042FFFF */  andi      $v0, $v0, 0xffff
/* BF360 80128C60 AFA20018 */  sw        $v0, 0x18($sp)
/* BF364 80128C64 26620002 */  addiu     $v0, $s3, 2
/* BF368 80128C68 3042FFFF */  andi      $v0, $v0, 0xffff
/* BF36C 80128C6C AFA2001C */  sw        $v0, 0x1c($sp)
/* BF370 80128C70 2622FFFF */  addiu     $v0, $s1, -1
/* BF374 80128C74 3042FFFF */  andi      $v0, $v0, 0xffff
/* BF378 80128C78 AFA20010 */  sw        $v0, 0x10($sp)
/* BF37C 80128C7C 2602FFFF */  addiu     $v0, $s0, -1
/* BF380 80128C80 3042FFFF */  andi      $v0, $v0, 0xffff
/* BF384 80128C84 0C04B26A */  jal       msg_draw_prim_rect
/* BF388 80128C88 AFA20014 */   sw       $v0, 0x14($sp)
.L80128C8C:
/* BF38C 80128C8C 0220202D */  daddu     $a0, $s1, $zero
.L80128C90:
/* BF390 80128C90 0200282D */  daddu     $a1, $s0, $zero
/* BF394 80128C94 0240302D */  daddu     $a2, $s2, $zero
/* BF398 80128C98 24820002 */  addiu     $v0, $a0, 2
/* BF39C 80128C9C 3C038015 */  lui       $v1, %hi(gMessageDrawStatePtr)
/* BF3A0 80128CA0 8C635D74 */  lw        $v1, %lo(gMessageDrawStatePtr)($v1)
/* BF3A4 80128CA4 0260382D */  daddu     $a3, $s3, $zero
/* BF3A8 80128CA8 AC620000 */  sw        $v0, ($v1)
/* BF3AC 80128CAC 24A20002 */  addiu     $v0, $a1, 2
/* BF3B0 80128CB0 AC620008 */  sw        $v0, 8($v1)
/* BF3B4 80128CB4 00861021 */  addu      $v0, $a0, $a2
/* BF3B8 80128CB8 2442FFFE */  addiu     $v0, $v0, -2
/* BF3BC 80128CBC AC620004 */  sw        $v0, 4($v1)
/* BF3C0 80128CC0 00B31021 */  addu      $v0, $a1, $s3
/* BF3C4 80128CC4 2442FFFE */  addiu     $v0, $v0, -2
/* BF3C8 80128CC8 AC62000C */  sw        $v0, 0xc($v1)
/* BF3CC 80128CCC 24190005 */  addiu     $t9, $zero, 5
/* BF3D0 80128CD0 AFB90010 */  sw        $t9, 0x10($sp)
/* BF3D4 80128CD4 9063002B */  lbu       $v1, 0x2b($v1)
/* BF3D8 80128CD8 328200FF */  andi      $v0, $s4, 0xff
/* BF3DC 80128CDC AFB50018 */  sw        $s5, 0x18($sp)
/* BF3E0 80128CE0 AFA2001C */  sw        $v0, 0x1c($sp)
/* BF3E4 80128CE4 AFA20020 */  sw        $v0, 0x20($sp)
/* BF3E8 80128CE8 0C04B6D6 */  jal       msg_draw_frame
/* BF3EC 80128CEC AFA30014 */   sw       $v1, 0x14($sp)
/* BF3F0 80128CF0 0C04B0B8 */  jal       msg_reset_gfx_state
/* BF3F4 80128CF4 329400FF */   andi     $s4, $s4, 0xff
/* BF3F8 80128CF8 3C048015 */  lui       $a0, %hi(gMessageDrawStatePtr)
/* BF3FC 80128CFC 8C845D74 */  lw        $a0, %lo(gMessageDrawStatePtr)($a0)
/* BF400 80128D00 A7B400AE */  sh        $s4, 0xae($sp)
/* BF404 80128D04 8C820020 */  lw        $v0, 0x20($a0)
/* BF408 80128D08 94830034 */  lhu       $v1, 0x34($a0)
/* BF40C 80128D0C 2418000A */  addiu     $t8, $zero, 0xa
/* BF410 80128D10 A498004A */  sh        $t8, 0x4a($a0)
/* BF414 80128D14 24420002 */  addiu     $v0, $v0, 2
/* BF418 80128D18 34630010 */  ori       $v1, $v1, 0x10
/* BF41C 80128D1C AC820020 */  sw        $v0, 0x20($a0)
/* BF420 80128D20 0804AFDC */  j         L8012BF70_C2670
/* BF424 80128D24 A4830034 */   sh       $v1, 0x34($a0)
glabel L80128D28_BF428
/* BF428 80128D28 3C058015 */  lui       $a1, %hi(gMessageDrawStatePtr)
/* BF42C 80128D2C 8CA55D74 */  lw        $a1, %lo(gMessageDrawStatePtr)($a1)
/* BF430 80128D30 24020010 */  addiu     $v0, $zero, 0x10
/* BF434 80128D34 24190003 */  addiu     $t9, $zero, 3
/* BF438 80128D38 A4A20046 */  sh        $v0, 0x46($a1)
/* BF43C 80128D3C A4B90048 */  sh        $t9, 0x48($a1)
/* BF440 80128D40 87C2045A */  lh        $v0, 0x45a($fp)
/* BF444 80128D44 24420005 */  addiu     $v0, $v0, 5
/* BF448 80128D48 ACA20000 */  sw        $v0, ($a1)
/* BF44C 80128D4C 87C2045C */  lh        $v0, 0x45c($fp)
/* BF450 80128D50 24420004 */  addiu     $v0, $v0, 4
/* BF454 80128D54 ACA20008 */  sw        $v0, 8($a1)
/* BF458 80128D58 87C2045A */  lh        $v0, 0x45a($fp)
/* BF45C 80128D5C 97C30514 */  lhu       $v1, 0x514($fp)
/* BF460 80128D60 0000882D */  daddu     $s1, $zero, $zero
/* BF464 80128D64 00431021 */  addu      $v0, $v0, $v1
/* BF468 80128D68 2442FFF8 */  addiu     $v0, $v0, -8
/* BF46C 80128D6C ACA20004 */  sw        $v0, 4($a1)
/* BF470 80128D70 87C2045C */  lh        $v0, 0x45c($fp)
/* BF474 80128D74 97C30516 */  lhu       $v1, 0x516($fp)
/* BF478 80128D78 240400FF */  addiu     $a0, $zero, 0xff
/* BF47C 80128D7C 00431021 */  addu      $v0, $v0, $v1
/* BF480 80128D80 94A30006 */  lhu       $v1, 6($a1)
/* BF484 80128D84 2442FFFB */  addiu     $v0, $v0, -5
/* BF488 80128D88 ACA2000C */  sw        $v0, 0xc($a1)
/* BF48C 80128D8C 2463FFEF */  addiu     $v1, $v1, -0x11
/* BF490 80128D90 A7C30482 */  sh        $v1, 0x482($fp)
/* BF494 80128D94 94A2000E */  lhu       $v0, 0xe($a1)
/* BF498 80128D98 0000382D */  daddu     $a3, $zero, $zero
/* BF49C 80128D9C 2442FFEF */  addiu     $v0, $v0, -0x11
/* BF4A0 80128DA0 A7C20484 */  sh        $v0, 0x484($fp)
/* BF4A4 80128DA4 A4A0004A */  sh        $zero, 0x4a($a1)
/* BF4A8 80128DA8 97C2045A */  lhu       $v0, 0x45a($fp)
/* BF4AC 80128DAC 24050020 */  addiu     $a1, $zero, 0x20
/* BF4B0 80128DB0 24420003 */  addiu     $v0, $v0, 3
/* BF4B4 80128DB4 3042FFFF */  andi      $v0, $v0, 0xffff
/* BF4B8 80128DB8 AFA20010 */  sw        $v0, 0x10($sp)
/* BF4BC 80128DBC 97C2045C */  lhu       $v0, 0x45c($fp)
/* BF4C0 80128DC0 00A0302D */  daddu     $a2, $a1, $zero
/* BF4C4 80128DC4 2442FFFF */  addiu     $v0, $v0, -1
/* BF4C8 80128DC8 3042FFFF */  andi      $v0, $v0, 0xffff
/* BF4CC 80128DCC AFA20014 */  sw        $v0, 0x14($sp)
/* BF4D0 80128DD0 97C20514 */  lhu       $v0, 0x514($fp)
/* BF4D4 80128DD4 24180001 */  addiu     $t8, $zero, 1
/* BF4D8 80128DD8 AFB8001C */  sw        $t8, 0x1c($sp)
/* BF4DC 80128DDC 2442FFFA */  addiu     $v0, $v0, -6
/* BF4E0 80128DE0 3042FFFF */  andi      $v0, $v0, 0xffff
/* BF4E4 80128DE4 0C04B26A */  jal       msg_draw_prim_rect
/* BF4E8 80128DE8 AFA20018 */   sw       $v0, 0x18($sp)
/* BF4EC 80128DEC 24040020 */  addiu     $a0, $zero, 0x20
/* BF4F0 80128DF0 240500FF */  addiu     $a1, $zero, 0xff
/* BF4F4 80128DF4 97C2045A */  lhu       $v0, 0x45a($fp)
/* BF4F8 80128DF8 0080302D */  daddu     $a2, $a0, $zero
/* BF4FC 80128DFC 24420003 */  addiu     $v0, $v0, 3
/* BF500 80128E00 3042FFFF */  andi      $v0, $v0, 0xffff
/* BF504 80128E04 AFA20010 */  sw        $v0, 0x10($sp)
/* BF508 80128E08 97C2045C */  lhu       $v0, 0x45c($fp)
/* BF50C 80128E0C 97C30516 */  lhu       $v1, 0x516($fp)
/* BF510 80128E10 0000382D */  daddu     $a3, $zero, $zero
/* BF514 80128E14 00431021 */  addu      $v0, $v0, $v1
/* BF518 80128E18 3042FFFF */  andi      $v0, $v0, 0xffff
/* BF51C 80128E1C AFA20014 */  sw        $v0, 0x14($sp)
/* BF520 80128E20 97C20514 */  lhu       $v0, 0x514($fp)
/* BF524 80128E24 24190001 */  addiu     $t9, $zero, 1
/* BF528 80128E28 AFB9001C */  sw        $t9, 0x1c($sp)
/* BF52C 80128E2C 2442FFFA */  addiu     $v0, $v0, -6
/* BF530 80128E30 3042FFFF */  andi      $v0, $v0, 0xffff
/* BF534 80128E34 0C04B26A */  jal       msg_draw_prim_rect
/* BF538 80128E38 AFA20018 */   sw       $v0, 0x18($sp)
/* BF53C 80128E3C 93C204F8 */  lbu       $v0, 0x4f8($fp)
/* BF540 80128E40 24180002 */  addiu     $t8, $zero, 2
/* BF544 80128E44 14580011 */  bne       $v0, $t8, .L80128E8C
/* BF548 80128E48 241000FF */   addiu    $s0, $zero, 0xff
/* BF54C 80128E4C 93C30509 */  lbu       $v1, 0x509($fp)
/* BF550 80128E50 00031040 */  sll       $v0, $v1, 1
/* BF554 80128E54 00431021 */  addu      $v0, $v0, $v1
/* BF558 80128E58 00021100 */  sll       $v0, $v0, 4
/* BF55C 80128E5C 24500050 */  addiu     $s0, $v0, 0x50
/* BF560 80128E60 320200FF */  andi      $v0, $s0, 0xff
/* BF564 80128E64 2442FFD0 */  addiu     $v0, $v0, -0x30
/* BF568 80128E68 24630001 */  addiu     $v1, $v1, 1
/* BF56C 80128E6C A7A2008E */  sh        $v0, 0x8e($sp)
/* BF570 80128E70 A3C30509 */  sb        $v1, 0x509($fp)
/* BF574 80128E74 306300FF */  andi      $v1, $v1, 0xff
/* BF578 80128E78 24020004 */  addiu     $v0, $zero, 4
/* BF57C 80128E7C 14620017 */  bne       $v1, $v0, .L80128EDC
/* BF580 80128E80 24110001 */   addiu    $s1, $zero, 1
/* BF584 80128E84 0804A3B7 */  j         .L80128EDC
/* BF588 80128E88 A3C304F8 */   sb       $v1, 0x4f8($fp)
.L80128E8C:
/* BF58C 80128E8C 24190003 */  addiu     $t9, $zero, 3
/* BF590 80128E90 14590012 */  bne       $v0, $t9, .L80128EDC
/* BF594 80128E94 2403FFD0 */   addiu    $v1, $zero, -0x30
/* BF598 80128E98 93C40512 */  lbu       $a0, 0x512($fp)
/* BF59C 80128E9C 00041080 */  sll       $v0, $a0, 2
/* BF5A0 80128EA0 00441021 */  addu      $v0, $v0, $a0
/* BF5A4 80128EA4 03221004 */  sllv      $v0, $v0, $t9
/* BF5A8 80128EA8 00628023 */  subu      $s0, $v1, $v0
/* BF5AC 80128EAC 320200FF */  andi      $v0, $s0, 0xff
/* BF5B0 80128EB0 00431021 */  addu      $v0, $v0, $v1
/* BF5B4 80128EB4 24840001 */  addiu     $a0, $a0, 1
/* BF5B8 80128EB8 A7A2008E */  sh        $v0, 0x8e($sp)
/* BF5BC 80128EBC A3C40512 */  sb        $a0, 0x512($fp)
/* BF5C0 80128EC0 308400FF */  andi      $a0, $a0, 0xff
/* BF5C4 80128EC4 24020004 */  addiu     $v0, $zero, 4
/* BF5C8 80128EC8 14820004 */  bne       $a0, $v0, .L80128EDC
/* BF5CC 80128ECC 24110001 */   addiu    $s1, $zero, 1
/* BF5D0 80128ED0 8FC204FC */  lw        $v0, 0x4fc($fp)
/* BF5D4 80128ED4 34420001 */  ori       $v0, $v0, 1
/* BF5D8 80128ED8 AFC204FC */  sw        $v0, 0x4fc($fp)
.L80128EDC:
/* BF5DC 80128EDC 87C4045A */  lh        $a0, 0x45a($fp)
/* BF5E0 80128EE0 87C5045C */  lh        $a1, 0x45c($fp)
/* BF5E4 80128EE4 97C60514 */  lhu       $a2, 0x514($fp)
/* BF5E8 80128EE8 97C70516 */  lhu       $a3, 0x516($fp)
/* BF5EC 80128EEC 24020006 */  addiu     $v0, $zero, 6
/* BF5F0 80128EF0 AFA20010 */  sw        $v0, 0x10($sp)
/* BF5F4 80128EF4 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* BF5F8 80128EF8 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* BF5FC 80128EFC 9043002B */  lbu       $v1, 0x2b($v0)
/* BF600 80128F00 320200FF */  andi      $v0, $s0, 0xff
/* BF604 80128F04 AFB10018 */  sw        $s1, 0x18($sp)
/* BF608 80128F08 AFA2001C */  sw        $v0, 0x1c($sp)
/* BF60C 80128F0C AFA20020 */  sw        $v0, 0x20($sp)
/* BF610 80128F10 0C04B6D6 */  jal       msg_draw_frame
/* BF614 80128F14 AFA30014 */   sw       $v1, 0x14($sp)
/* BF618 80128F18 0C04B0B8 */  jal       msg_reset_gfx_state
/* BF61C 80128F1C 321000FF */   andi     $s0, $s0, 0xff
/* BF620 80128F20 3C038015 */  lui       $v1, %hi(gMessageDrawStatePtr)
/* BF624 80128F24 8C635D74 */  lw        $v1, %lo(gMessageDrawStatePtr)($v1)
/* BF628 80128F28 8C620020 */  lw        $v0, 0x20($v1)
/* BF62C 80128F2C 0804AAD4 */  j         .L8012AB50
/* BF630 80128F30 A7B000AE */   sh       $s0, 0xae($sp)
glabel L80128F34_BF634
/* BF634 80128F34 24020012 */  addiu     $v0, $zero, 0x12
/* BF638 80128F38 2404001C */  addiu     $a0, $zero, 0x1c
/* BF63C 80128F3C 3C038015 */  lui       $v1, %hi(gMessageDrawStatePtr)
/* BF640 80128F40 8C635D74 */  lw        $v1, %lo(gMessageDrawStatePtr)($v1)
/* BF644 80128F44 A4620046 */  sh        $v0, 0x46($v1)
/* BF648 80128F48 2402000B */  addiu     $v0, $zero, 0xb
/* BF64C 80128F4C A4620048 */  sh        $v0, 0x48($v1)
/* BF650 80128F50 24020014 */  addiu     $v0, $zero, 0x14
/* BF654 80128F54 A7C2045A */  sh        $v0, 0x45a($fp)
/* BF658 80128F58 24020118 */  addiu     $v0, $zero, 0x118
/* BF65C 80128F5C A7C20514 */  sh        $v0, 0x514($fp)
/* BF660 80128F60 2402000F */  addiu     $v0, $zero, 0xf
/* BF664 80128F64 A7C4045C */  sh        $a0, 0x45c($fp)
/* BF668 80128F68 A062002B */  sb        $v0, 0x2b($v1)
/* BF66C 80128F6C 93C20508 */  lbu       $v0, 0x508($fp)
/* BF670 80128F70 24180007 */  addiu     $t8, $zero, 7
/* BF674 80128F74 1458000D */  bne       $v0, $t8, .L80128FAC
/* BF678 80128F78 241100FF */   addiu    $s1, $zero, 0xff
/* BF67C 80128F7C 3C19802F */  lui       $t9, %hi(D_802EC770)
/* BF680 80128F80 2739C770 */  addiu     $t9, $t9, %lo(D_802EC770)
/* BF684 80128F84 3C16802F */  lui       $s6, %hi(D_802ECD10)
/* BF688 80128F88 26D6CD10 */  addiu     $s6, $s6, %lo(D_802ECD10)
/* BF68C 80128F8C 3C038015 */  lui       $v1, %hi(gMessageDrawStatePtr)
/* BF690 80128F90 8C635D74 */  lw        $v1, %lo(gMessageDrawStatePtr)($v1)
/* BF694 80128F94 24020048 */  addiu     $v0, $zero, 0x48
/* BF698 80128F98 AFB900C0 */  sw        $t9, 0xc0($sp)
/* BF69C 80128F9C A7C20516 */  sh        $v0, 0x516($fp)
/* BF6A0 80128FA0 24020018 */  addiu     $v0, $zero, 0x18
/* BF6A4 80128FA4 0804A3F3 */  j         .L80128FCC
/* BF6A8 80128FA8 A462004A */   sh       $v0, 0x4a($v1)
.L80128FAC:
/* BF6AC 80128FAC 3C18802F */  lui       $t8, %hi(D_802EC7F0)
/* BF6B0 80128FB0 2718C7F0 */  addiu     $t8, $t8, %lo(D_802EC7F0)
/* BF6B4 80128FB4 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* BF6B8 80128FB8 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* BF6BC 80128FBC 3C16802F */  lui       $s6, %hi(D_802ECD30)
/* BF6C0 80128FC0 26D6CD30 */  addiu     $s6, $s6, %lo(D_802ECD30)
/* BF6C4 80128FC4 AFB800C0 */  sw        $t8, 0xc0($sp)
/* BF6C8 80128FC8 A444004A */  sh        $a0, 0x4a($v0)
.L80128FCC:
/* BF6CC 80128FCC 24020022 */  addiu     $v0, $zero, 0x22
/* BF6D0 80128FD0 3C048015 */  lui       $a0, %hi(gMessageDrawStatePtr)
/* BF6D4 80128FD4 8C845D74 */  lw        $a0, %lo(gMessageDrawStatePtr)($a0)
/* BF6D8 80128FD8 24190002 */  addiu     $t9, $zero, 2
/* BF6DC 80128FDC AC820000 */  sw        $v0, ($a0)
/* BF6E0 80128FE0 24020028 */  addiu     $v0, $zero, 0x28
/* BF6E4 80128FE4 AC820008 */  sw        $v0, 8($a0)
/* BF6E8 80128FE8 2402011B */  addiu     $v0, $zero, 0x11b
/* BF6EC 80128FEC AC820004 */  sw        $v0, 4($a0)
/* BF6F0 80128FF0 97C20516 */  lhu       $v0, 0x516($fp)
/* BF6F4 80128FF4 94830006 */  lhu       $v1, 6($a0)
/* BF6F8 80128FF8 24420011 */  addiu     $v0, $v0, 0x11
/* BF6FC 80128FFC 2463FFF0 */  addiu     $v1, $v1, -0x10
/* BF700 80129000 AC82000C */  sw        $v0, 0xc($a0)
/* BF704 80129004 A7C30482 */  sh        $v1, 0x482($fp)
/* BF708 80129008 9482000E */  lhu       $v0, 0xe($a0)
/* BF70C 8012900C 93C304F8 */  lbu       $v1, 0x4f8($fp)
/* BF710 80129010 2442FFF7 */  addiu     $v0, $v0, -9
/* BF714 80129014 14790010 */  bne       $v1, $t9, .L80129058
/* BF718 80129018 A7C20484 */   sh       $v0, 0x484($fp)
/* BF71C 8012901C 93C20509 */  lbu       $v0, 0x509($fp)
/* BF720 80129020 24180003 */  addiu     $t8, $zero, 3
/* BF724 80129024 00021980 */  sll       $v1, $v0, 6
/* BF728 80129028 24710050 */  addiu     $s1, $v1, 0x50
/* BF72C 8012902C 322300FF */  andi      $v1, $s1, 0xff
/* BF730 80129030 2463FFD0 */  addiu     $v1, $v1, -0x30
/* BF734 80129034 24420001 */  addiu     $v0, $v0, 1
/* BF738 80129038 A7A3008E */  sh        $v1, 0x8e($sp)
/* BF73C 8012903C A3C20509 */  sb        $v0, 0x509($fp)
/* BF740 80129040 304200FF */  andi      $v0, $v0, 0xff
/* BF744 80129044 14580018 */  bne       $v0, $t8, .L801290A8
/* BF748 80129048 323800FF */   andi     $t8, $s1, 0xff
/* BF74C 8012904C 24020004 */  addiu     $v0, $zero, 4
/* BF750 80129050 0804A42A */  j         .L801290A8
/* BF754 80129054 A3C204F8 */   sb       $v0, 0x4f8($fp)
.L80129058:
/* BF758 80129058 24190003 */  addiu     $t9, $zero, 3
/* BF75C 8012905C 14790012 */  bne       $v1, $t9, .L801290A8
/* BF760 80129060 323800FF */   andi     $t8, $s1, 0xff
/* BF764 80129064 93C40512 */  lbu       $a0, 0x512($fp)
/* BF768 80129068 2403FFD0 */  addiu     $v1, $zero, -0x30
/* BF76C 8012906C 00041040 */  sll       $v0, $a0, 1
/* BF770 80129070 00441021 */  addu      $v0, $v0, $a0
/* BF774 80129074 00021100 */  sll       $v0, $v0, 4
/* BF778 80129078 00628823 */  subu      $s1, $v1, $v0
/* BF77C 8012907C 322200FF */  andi      $v0, $s1, 0xff
/* BF780 80129080 00431021 */  addu      $v0, $v0, $v1
/* BF784 80129084 24840001 */  addiu     $a0, $a0, 1
/* BF788 80129088 A7A2008E */  sh        $v0, 0x8e($sp)
/* BF78C 8012908C A3C40512 */  sb        $a0, 0x512($fp)
/* BF790 80129090 308400FF */  andi      $a0, $a0, 0xff
/* BF794 80129094 14990004 */  bne       $a0, $t9, .L801290A8
/* BF798 80129098 323800FF */   andi     $t8, $s1, 0xff
/* BF79C 8012909C 8FC204FC */  lw        $v0, 0x4fc($fp)
/* BF7A0 801290A0 34420001 */  ori       $v0, $v0, 1
/* BF7A4 801290A4 AFC204FC */  sw        $v0, 0x4fc($fp)
.L801290A8:
/* BF7A8 801290A8 3C04802F */  lui       $a0, %hi(D_802EC5F0)
/* BF7AC 801290AC 2484C5F0 */  addiu     $a0, $a0, %lo(D_802EC5F0)
/* BF7B0 801290B0 24050010 */  addiu     $a1, $zero, 0x10
/* BF7B4 801290B4 00A0302D */  daddu     $a2, $a1, $zero
/* BF7B8 801290B8 24070002 */  addiu     $a3, $zero, 2
/* BF7BC 801290BC 24150014 */  addiu     $s5, $zero, 0x14
/* BF7C0 801290C0 2410001C */  addiu     $s0, $zero, 0x1c
/* BF7C4 801290C4 2419000A */  addiu     $t9, $zero, 0xa
/* BF7C8 801290C8 A7B800AE */  sh        $t8, 0xae($sp)
/* BF7CC 801290CC 0320C02D */  daddu     $t8, $t9, $zero
/* BF7D0 801290D0 24130136 */  addiu     $s3, $zero, 0x136
/* BF7D4 801290D4 241200E6 */  addiu     $s2, $zero, 0xe6
/* BF7D8 801290D8 323100FF */  andi      $s1, $s1, 0xff
/* BF7DC 801290DC AFA00010 */  sw        $zero, 0x10($sp)
/* BF7E0 801290E0 AFB60014 */  sw        $s6, 0x14($sp)
/* BF7E4 801290E4 AFB50018 */  sw        $s5, 0x18($sp)
/* BF7E8 801290E8 AFB0001C */  sw        $s0, 0x1c($sp)
/* BF7EC 801290EC AFB90020 */  sw        $t9, 0x20($sp)
/* BF7F0 801290F0 AFB80024 */  sw        $t8, 0x24($sp)
/* BF7F4 801290F4 AFB30028 */  sw        $s3, 0x28($sp)
/* BF7F8 801290F8 AFB2002C */  sw        $s2, 0x2c($sp)
/* BF7FC 801290FC 0C04BA68 */  jal       draw_ci_image_with_clipping
/* BF800 80129100 AFB10030 */   sw       $s1, 0x30($sp)
/* BF804 80129104 3C04802F */  lui       $a0, %hi(D_802EC670)
/* BF808 80129108 2484C670 */  addiu     $a0, $a0, %lo(D_802EC670)
/* BF80C 8012910C 24050010 */  addiu     $a1, $zero, 0x10
/* BF810 80129110 00A0302D */  daddu     $a2, $a1, $zero
/* BF814 80129114 24070002 */  addiu     $a3, $zero, 2
/* BF818 80129118 2414011C */  addiu     $s4, $zero, 0x11c
/* BF81C 8012911C 2419000A */  addiu     $t9, $zero, 0xa
/* BF820 80129120 0320C02D */  daddu     $t8, $t9, $zero
/* BF824 80129124 AFA00010 */  sw        $zero, 0x10($sp)
/* BF828 80129128 AFB60014 */  sw        $s6, 0x14($sp)
/* BF82C 8012912C AFB40018 */  sw        $s4, 0x18($sp)
/* BF830 80129130 AFB0001C */  sw        $s0, 0x1c($sp)
/* BF834 80129134 AFB90020 */  sw        $t9, 0x20($sp)
/* BF838 80129138 AFB80024 */  sw        $t8, 0x24($sp)
/* BF83C 8012913C AFB30028 */  sw        $s3, 0x28($sp)
/* BF840 80129140 AFB2002C */  sw        $s2, 0x2c($sp)
/* BF844 80129144 0C04BA68 */  jal       draw_ci_image_with_clipping
/* BF848 80129148 AFB10030 */   sw       $s1, 0x30($sp)
/* BF84C 8012914C 3C04802F */  lui       $a0, %hi(D_802EC6F0)
/* BF850 80129150 2484C6F0 */  addiu     $a0, $a0, %lo(D_802EC6F0)
/* BF854 80129154 24050010 */  addiu     $a1, $zero, 0x10
/* BF858 80129158 00A0302D */  daddu     $a2, $a1, $zero
/* BF85C 8012915C 24070002 */  addiu     $a3, $zero, 2
/* BF860 80129160 AFA00010 */  sw        $zero, 0x10($sp)
/* BF864 80129164 AFB60014 */  sw        $s6, 0x14($sp)
/* BF868 80129168 AFB50018 */  sw        $s5, 0x18($sp)
/* BF86C 8012916C 97C20516 */  lhu       $v0, 0x516($fp)
/* BF870 80129170 2419000A */  addiu     $t9, $zero, 0xa
/* BF874 80129174 0320C02D */  daddu     $t8, $t9, $zero
/* BF878 80129178 AFB90020 */  sw        $t9, 0x20($sp)
/* BF87C 8012917C AFB80024 */  sw        $t8, 0x24($sp)
/* BF880 80129180 AFB30028 */  sw        $s3, 0x28($sp)
/* BF884 80129184 AFB2002C */  sw        $s2, 0x2c($sp)
/* BF888 80129188 AFB10030 */  sw        $s1, 0x30($sp)
/* BF88C 8012918C 2442000C */  addiu     $v0, $v0, 0xc
/* BF890 80129190 00A21004 */  sllv      $v0, $v0, $a1
/* BF894 80129194 00A21007 */  srav      $v0, $v0, $a1
/* BF898 80129198 0C04BA68 */  jal       draw_ci_image_with_clipping
/* BF89C 8012919C AFA2001C */   sw       $v0, 0x1c($sp)
/* BF8A0 801291A0 24050010 */  addiu     $a1, $zero, 0x10
/* BF8A4 801291A4 00A0302D */  daddu     $a2, $a1, $zero
/* BF8A8 801291A8 24070002 */  addiu     $a3, $zero, 2
/* BF8AC 801291AC AFA00010 */  sw        $zero, 0x10($sp)
/* BF8B0 801291B0 AFB60014 */  sw        $s6, 0x14($sp)
/* BF8B4 801291B4 AFB40018 */  sw        $s4, 0x18($sp)
/* BF8B8 801291B8 97C20516 */  lhu       $v0, 0x516($fp)
/* BF8BC 801291BC 2419000A */  addiu     $t9, $zero, 0xa
/* BF8C0 801291C0 8FA400C0 */  lw        $a0, 0xc0($sp)
/* BF8C4 801291C4 0320C02D */  daddu     $t8, $t9, $zero
/* BF8C8 801291C8 AFB90020 */  sw        $t9, 0x20($sp)
/* BF8CC 801291CC AFB80024 */  sw        $t8, 0x24($sp)
/* BF8D0 801291D0 AFB30028 */  sw        $s3, 0x28($sp)
/* BF8D4 801291D4 AFB2002C */  sw        $s2, 0x2c($sp)
/* BF8D8 801291D8 AFB10030 */  sw        $s1, 0x30($sp)
/* BF8DC 801291DC 2442000C */  addiu     $v0, $v0, 0xc
/* BF8E0 801291E0 00A21004 */  sllv      $v0, $v0, $a1
/* BF8E4 801291E4 00A21007 */  srav      $v0, $v0, $a1
/* BF8E8 801291E8 0C04BA68 */  jal       draw_ci_image_with_clipping
/* BF8EC 801291EC AFA2001C */   sw       $v0, 0x1c($sp)
/* BF8F0 801291F0 3C120703 */  lui       $s2, 0x703
/* BF8F4 801291F4 3652E03C */  ori       $s2, $s2, 0xe03c
/* BF8F8 801291F8 3C14F540 */  lui       $s4, 0xf540
/* BF8FC 801291FC 36940400 */  ori       $s4, $s4, 0x400
/* BF900 80129200 3C130001 */  lui       $s3, 1
/* BF904 80129204 36730050 */  ori       $s3, $s3, 0x50
/* BF908 80129208 3C150007 */  lui       $s5, 7
/* BF90C 8012920C 36B5C03C */  ori       $s5, $s5, 0xc03c
/* BF910 80129210 3C06E447 */  lui       $a2, 0xe447
/* BF914 80129214 34C600B0 */  ori       $a2, $a2, 0xb0
/* BF918 80129218 3C050009 */  lui       $a1, 9
/* BF91C 8012921C 34A50070 */  ori       $a1, $a1, 0x70
/* BF920 80129220 3C090400 */  lui       $t1, 0x400
/* BF924 80129224 35290400 */  ori       $t1, $t1, 0x400
/* BF928 80129228 3C0BFD48 */  lui       $t3, 0xfd48
/* BF92C 8012922C 356B0007 */  ori       $t3, $t3, 7
/* BF930 80129230 3C0AF548 */  lui       $t2, 0xf548
/* BF934 80129234 354A0200 */  ori       $t2, $t2, 0x200
/* BF938 80129238 3C0D0701 */  lui       $t5, 0x701
/* BF93C 8012923C 35AD4040 */  ori       $t5, $t5, 0x4040
/* BF940 80129240 3C0E0701 */  lui       $t6, 0x701
/* BF944 80129244 35CEE07C */  ori       $t6, $t6, 0xe07c
/* BF948 80129248 3C0CF540 */  lui       $t4, 0xf540
/* BF94C 8012924C 358C0200 */  ori       $t4, $t4, 0x200
/* BF950 80129250 3C0F0001 */  lui       $t7, 1
/* BF954 80129254 35EF4040 */  ori       $t7, $t7, 0x4040
/* BF958 80129258 3C100003 */  lui       $s0, 3
/* BF95C 8012925C 3610C07C */  ori       $s0, $s0, 0xc07c
/* BF960 80129260 3C110005 */  lui       $s1, 5
/* BF964 80129264 363100B0 */  ori       $s1, $s1, 0xb0
/* BF968 80129268 3C160047 */  lui       $s6, 0x47
/* BF96C 8012926C 36D600B0 */  ori       $s6, $s6, 0xb0
/* BF970 80129270 3C19FD48 */  lui       $t9, 0xfd48
/* BF974 80129274 37390003 */  ori       $t9, $t9, 3
/* BF978 80129278 3C180700 */  lui       $t8, 0x700
/* BF97C 8012927C 3718C030 */  ori       $t8, $t8, 0xc030
/* BF980 80129280 AFB900D0 */  sw        $t9, 0xd0($sp)
/* BF984 80129284 3C190700 */  lui       $t9, 0x700
/* BF988 80129288 3739E01C */  ori       $t9, $t9, 0xe01c
/* BF98C 8012928C AFB800E0 */  sw        $t8, 0xe0($sp)
/* BF990 80129290 3C180001 */  lui       $t8, 1
/* BF994 80129294 3718C01C */  ori       $t8, $t8, 0xc01c
/* BF998 80129298 AFB900E4 */  sw        $t9, 0xe4($sp)
/* BF99C 8012929C 3C190009 */  lui       $t9, 9
/* BF9A0 801292A0 373900B0 */  ori       $t9, $t9, 0xb0
/* BF9A4 801292A4 3C03802F */  lui       $v1, %hi(D_802EC870)
/* BF9A8 801292A8 2463C870 */  addiu     $v1, $v1, %lo(D_802EC870)
/* BF9AC 801292AC AFB800D4 */  sw        $t8, 0xd4($sp)
/* BF9B0 801292B0 8EE20000 */  lw        $v0, ($s7)
/* BF9B4 801292B4 3C08F200 */  lui       $t0, 0xf200
/* BF9B8 801292B8 AFB900D8 */  sw        $t9, 0xd8($sp)
/* BF9BC 801292BC 0040202D */  daddu     $a0, $v0, $zero
/* BF9C0 801292C0 24420008 */  addiu     $v0, $v0, 8
/* BF9C4 801292C4 AEE20000 */  sw        $v0, ($s7)
/* BF9C8 801292C8 8FB800C4 */  lw        $t8, 0xc4($sp)
/* BF9CC 801292CC 3C07E100 */  lui       $a3, 0xe100
/* BF9D0 801292D0 AC830004 */  sw        $v1, 4($a0)
/* BF9D4 801292D4 24430008 */  addiu     $v1, $v0, 8
/* BF9D8 801292D8 AC980000 */  sw        $t8, ($a0)
/* BF9DC 801292DC AEE30000 */  sw        $v1, ($s7)
/* BF9E0 801292E0 8FB900C8 */  lw        $t9, 0xc8($sp)
/* BF9E4 801292E4 24430010 */  addiu     $v1, $v0, 0x10
/* BF9E8 801292E8 AC590000 */  sw        $t9, ($v0)
/* BF9EC 801292EC 8FB800CC */  lw        $t8, 0xcc($sp)
/* BF9F0 801292F0 3C19E600 */  lui       $t9, 0xe600
/* BF9F4 801292F4 AC580004 */  sw        $t8, 4($v0)
/* BF9F8 801292F8 AEE30000 */  sw        $v1, ($s7)
/* BF9FC 801292FC 24430018 */  addiu     $v1, $v0, 0x18
/* BFA00 80129300 3C18F400 */  lui       $t8, 0xf400
/* BFA04 80129304 AC590008 */  sw        $t9, 8($v0)
/* BFA08 80129308 AC40000C */  sw        $zero, 0xc($v0)
/* BFA0C 8012930C AEE30000 */  sw        $v1, ($s7)
/* BFA10 80129310 24430020 */  addiu     $v1, $v0, 0x20
/* BFA14 80129314 3C19E700 */  lui       $t9, 0xe700
/* BFA18 80129318 AC580010 */  sw        $t8, 0x10($v0)
/* BFA1C 8012931C AC520014 */  sw        $s2, 0x14($v0)
/* BFA20 80129320 AEE30000 */  sw        $v1, ($s7)
/* BFA24 80129324 24430028 */  addiu     $v1, $v0, 0x28
/* BFA28 80129328 AC590018 */  sw        $t9, 0x18($v0)
/* BFA2C 8012932C AC40001C */  sw        $zero, 0x1c($v0)
/* BFA30 80129330 AEE30000 */  sw        $v1, ($s7)
/* BFA34 80129334 24430030 */  addiu     $v1, $v0, 0x30
/* BFA38 80129338 AC540020 */  sw        $s4, 0x20($v0)
/* BFA3C 8012933C AC530024 */  sw        $s3, 0x24($v0)
/* BFA40 80129340 AEE30000 */  sw        $v1, ($s7)
/* BFA44 80129344 24430038 */  addiu     $v1, $v0, 0x38
/* BFA48 80129348 AC480028 */  sw        $t0, 0x28($v0)
/* BFA4C 8012934C AC55002C */  sw        $s5, 0x2c($v0)
/* BFA50 80129350 AEE30000 */  sw        $v1, ($s7)
/* BFA54 80129354 24430040 */  addiu     $v1, $v0, 0x40
/* BFA58 80129358 AC460030 */  sw        $a2, 0x30($v0)
/* BFA5C 8012935C AC450034 */  sw        $a1, 0x34($v0)
/* BFA60 80129360 AEE30000 */  sw        $v1, ($s7)
/* BFA64 80129364 24430048 */  addiu     $v1, $v0, 0x48
/* BFA68 80129368 3C06F100 */  lui       $a2, 0xf100
/* BFA6C 8012936C AC470038 */  sw        $a3, 0x38($v0)
/* BFA70 80129370 AC40003C */  sw        $zero, 0x3c($v0)
/* BFA74 80129374 AEE30000 */  sw        $v1, ($s7)
/* BFA78 80129378 24430050 */  addiu     $v1, $v0, 0x50
/* BFA7C 8012937C AC460040 */  sw        $a2, 0x40($v0)
/* BFA80 80129380 AC490044 */  sw        $t1, 0x44($v0)
/* BFA84 80129384 AEE30000 */  sw        $v1, ($s7)
/* BFA88 80129388 3C03802F */  lui       $v1, %hi(D_802EC970)
/* BFA8C 8012938C 2463C970 */  addiu     $v1, $v1, %lo(D_802EC970)
/* BFA90 80129390 AC4B0048 */  sw        $t3, 0x48($v0)
/* BFA94 80129394 AC43004C */  sw        $v1, 0x4c($v0)
/* BFA98 80129398 24430058 */  addiu     $v1, $v0, 0x58
/* BFA9C 8012939C AEE30000 */  sw        $v1, ($s7)
/* BFAA0 801293A0 24430060 */  addiu     $v1, $v0, 0x60
/* BFAA4 801293A4 3C18E600 */  lui       $t8, 0xe600
/* BFAA8 801293A8 AC4A0050 */  sw        $t2, 0x50($v0)
/* BFAAC 801293AC AC4D0054 */  sw        $t5, 0x54($v0)
/* BFAB0 801293B0 AEE30000 */  sw        $v1, ($s7)
/* BFAB4 801293B4 24430068 */  addiu     $v1, $v0, 0x68
/* BFAB8 801293B8 3C19F400 */  lui       $t9, 0xf400
/* BFABC 801293BC AC580058 */  sw        $t8, 0x58($v0)
/* BFAC0 801293C0 AC40005C */  sw        $zero, 0x5c($v0)
/* BFAC4 801293C4 AEE30000 */  sw        $v1, ($s7)
/* BFAC8 801293C8 24430070 */  addiu     $v1, $v0, 0x70
/* BFACC 801293CC 3C18E700 */  lui       $t8, 0xe700
/* BFAD0 801293D0 AC590060 */  sw        $t9, 0x60($v0)
/* BFAD4 801293D4 AC4E0064 */  sw        $t6, 0x64($v0)
/* BFAD8 801293D8 AEE30000 */  sw        $v1, ($s7)
/* BFADC 801293DC 24430078 */  addiu     $v1, $v0, 0x78
/* BFAE0 801293E0 AC580068 */  sw        $t8, 0x68($v0)
/* BFAE4 801293E4 AC40006C */  sw        $zero, 0x6c($v0)
/* BFAE8 801293E8 AEE30000 */  sw        $v1, ($s7)
/* BFAEC 801293EC 24430080 */  addiu     $v1, $v0, 0x80
/* BFAF0 801293F0 AC4C0070 */  sw        $t4, 0x70($v0)
/* BFAF4 801293F4 AC4F0074 */  sw        $t7, 0x74($v0)
/* BFAF8 801293F8 AEE30000 */  sw        $v1, ($s7)
/* BFAFC 801293FC AC480078 */  sw        $t0, 0x78($v0)
/* BFB00 80129400 AC50007C */  sw        $s0, 0x7c($v0)
/* BFB04 80129404 97C40516 */  lhu       $a0, 0x516($fp)
/* BFB08 80129408 24430088 */  addiu     $v1, $v0, 0x88
/* BFB0C 8012940C AEE30000 */  sw        $v1, ($s7)
/* BFB10 80129410 24430090 */  addiu     $v1, $v0, 0x90
/* BFB14 80129414 AC510084 */  sw        $s1, 0x84($v0)
/* BFB18 80129418 AEE30000 */  sw        $v1, ($s7)
/* BFB1C 8012941C 24430098 */  addiu     $v1, $v0, 0x98
/* BFB20 80129420 AC470088 */  sw        $a3, 0x88($v0)
/* BFB24 80129424 AC40008C */  sw        $zero, 0x8c($v0)
/* BFB28 80129428 AEE30000 */  sw        $v1, ($s7)
/* BFB2C 8012942C 244300A0 */  addiu     $v1, $v0, 0xa0
/* BFB30 80129430 AC460090 */  sw        $a2, 0x90($v0)
/* BFB34 80129434 AC490094 */  sw        $t1, 0x94($v0)
/* BFB38 80129438 AEE30000 */  sw        $v1, ($s7)
/* BFB3C 8012943C 3C03802F */  lui       $v1, %hi(D_802ECAB0)
/* BFB40 80129440 2463CAB0 */  addiu     $v1, $v1, %lo(D_802ECAB0)
/* BFB44 80129444 AC43009C */  sw        $v1, 0x9c($v0)
/* BFB48 80129448 244300A8 */  addiu     $v1, $v0, 0xa8
/* BFB4C 8012944C AC4B0098 */  sw        $t3, 0x98($v0)
/* BFB50 80129450 AEE30000 */  sw        $v1, ($s7)
/* BFB54 80129454 3C03E409 */  lui       $v1, 0xe409
/* BFB58 80129458 3C05E447 */  lui       $a1, 0xe447
/* BFB5C 8012945C AC4A00A0 */  sw        $t2, 0xa0($v0)
/* BFB60 80129460 2484000C */  addiu     $a0, $a0, 0xc
/* BFB64 80129464 00042080 */  sll       $a0, $a0, 2
/* BFB68 80129468 30840FFF */  andi      $a0, $a0, 0xfff
/* BFB6C 8012946C 00832025 */  or        $a0, $a0, $v1
/* BFB70 80129470 244300B0 */  addiu     $v1, $v0, 0xb0
/* BFB74 80129474 AC440080 */  sw        $a0, 0x80($v0)
/* BFB78 80129478 AC4D00A4 */  sw        $t5, 0xa4($v0)
/* BFB7C 8012947C 3C19E600 */  lui       $t9, 0xe600
/* BFB80 80129480 AEE30000 */  sw        $v1, ($s7)
/* BFB84 80129484 244300B8 */  addiu     $v1, $v0, 0xb8
/* BFB88 80129488 3C18F400 */  lui       $t8, 0xf400
/* BFB8C 8012948C AC5900A8 */  sw        $t9, 0xa8($v0)
/* BFB90 80129490 AC4000AC */  sw        $zero, 0xac($v0)
/* BFB94 80129494 AEE30000 */  sw        $v1, ($s7)
/* BFB98 80129498 244300C0 */  addiu     $v1, $v0, 0xc0
/* BFB9C 8012949C 3C19E700 */  lui       $t9, 0xe700
/* BFBA0 801294A0 AC5800B0 */  sw        $t8, 0xb0($v0)
/* BFBA4 801294A4 AC4E00B4 */  sw        $t6, 0xb4($v0)
/* BFBA8 801294A8 AEE30000 */  sw        $v1, ($s7)
/* BFBAC 801294AC 244300C8 */  addiu     $v1, $v0, 0xc8
/* BFBB0 801294B0 AC5900B8 */  sw        $t9, 0xb8($v0)
/* BFBB4 801294B4 AC4000BC */  sw        $zero, 0xbc($v0)
/* BFBB8 801294B8 AEE30000 */  sw        $v1, ($s7)
/* BFBBC 801294BC 244300D0 */  addiu     $v1, $v0, 0xd0
/* BFBC0 801294C0 AC4C00C0 */  sw        $t4, 0xc0($v0)
/* BFBC4 801294C4 AC4F00C4 */  sw        $t7, 0xc4($v0)
/* BFBC8 801294C8 AEE30000 */  sw        $v1, ($s7)
/* BFBCC 801294CC AC4800C8 */  sw        $t0, 0xc8($v0)
/* BFBD0 801294D0 AC5000CC */  sw        $s0, 0xcc($v0)
/* BFBD4 801294D4 97C40516 */  lhu       $a0, 0x516($fp)
/* BFBD8 801294D8 244300D8 */  addiu     $v1, $v0, 0xd8
/* BFBDC 801294DC AEE30000 */  sw        $v1, ($s7)
/* BFBE0 801294E0 244300E0 */  addiu     $v1, $v0, 0xe0
/* BFBE4 801294E4 AC5600D4 */  sw        $s6, 0xd4($v0)
/* BFBE8 801294E8 AEE30000 */  sw        $v1, ($s7)
/* BFBEC 801294EC 244300E8 */  addiu     $v1, $v0, 0xe8
/* BFBF0 801294F0 AC4700D8 */  sw        $a3, 0xd8($v0)
/* BFBF4 801294F4 AC4000DC */  sw        $zero, 0xdc($v0)
/* BFBF8 801294F8 AEE30000 */  sw        $v1, ($s7)
/* BFBFC 801294FC 244300F0 */  addiu     $v1, $v0, 0xf0
/* BFC00 80129500 AC4600E0 */  sw        $a2, 0xe0($v0)
/* BFC04 80129504 AC4900E4 */  sw        $t1, 0xe4($v0)
/* BFC08 80129508 AEE30000 */  sw        $v1, ($s7)
/* BFC0C 8012950C 8FB800C4 */  lw        $t8, 0xc4($sp)
/* BFC10 80129510 3C03802F */  lui       $v1, %hi(D_802ECBF0)
/* BFC14 80129514 2463CBF0 */  addiu     $v1, $v1, %lo(D_802ECBF0)
/* BFC18 80129518 AC5800E8 */  sw        $t8, 0xe8($v0)
/* BFC1C 8012951C AC4300EC */  sw        $v1, 0xec($v0)
/* BFC20 80129520 244300F8 */  addiu     $v1, $v0, 0xf8
/* BFC24 80129524 AEE30000 */  sw        $v1, ($s7)
/* BFC28 80129528 24430100 */  addiu     $v1, $v0, 0x100
/* BFC2C 8012952C 2484000C */  addiu     $a0, $a0, 0xc
/* BFC30 80129530 00042080 */  sll       $a0, $a0, 2
/* BFC34 80129534 8FB900C8 */  lw        $t9, 0xc8($sp)
/* BFC38 80129538 30840FFF */  andi      $a0, $a0, 0xfff
/* BFC3C 8012953C AC5900F0 */  sw        $t9, 0xf0($v0)
/* BFC40 80129540 8FB800CC */  lw        $t8, 0xcc($sp)
/* BFC44 80129544 3C19E600 */  lui       $t9, 0xe600
/* BFC48 80129548 AC5800F4 */  sw        $t8, 0xf4($v0)
/* BFC4C 8012954C AEE30000 */  sw        $v1, ($s7)
/* BFC50 80129550 3C03E44B */  lui       $v1, 0xe44b
/* BFC54 80129554 00832025 */  or        $a0, $a0, $v1
/* BFC58 80129558 24430108 */  addiu     $v1, $v0, 0x108
/* BFC5C 8012955C AC4400D0 */  sw        $a0, 0xd0($v0)
/* BFC60 80129560 AC4000FC */  sw        $zero, 0xfc($v0)
/* BFC64 80129564 3C18F400 */  lui       $t8, 0xf400
/* BFC68 80129568 AC5900F8 */  sw        $t9, 0xf8($v0)
/* BFC6C 8012956C AEE30000 */  sw        $v1, ($s7)
/* BFC70 80129570 24430110 */  addiu     $v1, $v0, 0x110
/* BFC74 80129574 3C19E700 */  lui       $t9, 0xe700
/* BFC78 80129578 AC580100 */  sw        $t8, 0x100($v0)
/* BFC7C 8012957C AC520104 */  sw        $s2, 0x104($v0)
/* BFC80 80129580 AEE30000 */  sw        $v1, ($s7)
/* BFC84 80129584 24430118 */  addiu     $v1, $v0, 0x118
/* BFC88 80129588 AC590108 */  sw        $t9, 0x108($v0)
/* BFC8C 8012958C AC40010C */  sw        $zero, 0x10c($v0)
/* BFC90 80129590 AEE30000 */  sw        $v1, ($s7)
/* BFC94 80129594 24430120 */  addiu     $v1, $v0, 0x120
/* BFC98 80129598 AC540110 */  sw        $s4, 0x110($v0)
/* BFC9C 8012959C AC530114 */  sw        $s3, 0x114($v0)
/* BFCA0 801295A0 AEE30000 */  sw        $v1, ($s7)
/* BFCA4 801295A4 24430128 */  addiu     $v1, $v0, 0x128
/* BFCA8 801295A8 AC480118 */  sw        $t0, 0x118($v0)
/* BFCAC 801295AC AC55011C */  sw        $s5, 0x11c($v0)
/* BFCB0 801295B0 AEE30000 */  sw        $v1, ($s7)
/* BFCB4 801295B4 24430130 */  addiu     $v1, $v0, 0x130
/* BFCB8 801295B8 AEE30000 */  sw        $v1, ($s7)
/* BFCBC 801295BC 24430138 */  addiu     $v1, $v0, 0x138
/* BFCC0 801295C0 AEE30000 */  sw        $v1, ($s7)
/* BFCC4 801295C4 24430140 */  addiu     $v1, $v0, 0x140
/* BFCC8 801295C8 AEE30000 */  sw        $v1, ($s7)
/* BFCCC 801295CC 24430148 */  addiu     $v1, $v0, 0x148
/* BFCD0 801295D0 AEE30000 */  sw        $v1, ($s7)
/* BFCD4 801295D4 97C30516 */  lhu       $v1, 0x516($fp)
/* BFCD8 801295D8 24440150 */  addiu     $a0, $v0, 0x150
/* BFCDC 801295DC AEE40000 */  sw        $a0, ($s7)
/* BFCE0 801295E0 2463001C */  addiu     $v1, $v1, 0x1c
/* BFCE4 801295E4 00031880 */  sll       $v1, $v1, 2
/* BFCE8 801295E8 30630FFF */  andi      $v1, $v1, 0xfff
/* BFCEC 801295EC 00651825 */  or        $v1, $v1, $a1
/* BFCF0 801295F0 AC430120 */  sw        $v1, 0x120($v0)
/* BFCF4 801295F4 97C40516 */  lhu       $a0, 0x516($fp)
/* BFCF8 801295F8 24430158 */  addiu     $v1, $v0, 0x158
/* BFCFC 801295FC AEE30000 */  sw        $v1, ($s7)
/* BFD00 80129600 AC470128 */  sw        $a3, 0x128($v0)
/* BFD04 80129604 AC40012C */  sw        $zero, 0x12c($v0)
/* BFD08 80129608 AC460130 */  sw        $a2, 0x130($v0)
/* BFD0C 8012960C AC490134 */  sw        $t1, 0x134($v0)
/* BFD10 80129610 8FB800D0 */  lw        $t8, 0xd0($sp)
/* BFD14 80129614 3C03802F */  lui       $v1, %hi(D_802ECCF0)
/* BFD18 80129618 2463CCF0 */  addiu     $v1, $v1, %lo(D_802ECCF0)
/* BFD1C 8012961C AC580138 */  sw        $t8, 0x138($v0)
/* BFD20 80129620 3C18E600 */  lui       $t8, 0xe600
/* BFD24 80129624 2484000C */  addiu     $a0, $a0, 0xc
/* BFD28 80129628 00042080 */  sll       $a0, $a0, 2
/* BFD2C 8012962C 30840FFF */  andi      $a0, $a0, 0xfff
/* BFD30 80129630 AC43013C */  sw        $v1, 0x13c($v0)
/* BFD34 80129634 3C030009 */  lui       $v1, 9
/* BFD38 80129638 00832025 */  or        $a0, $a0, $v1
/* BFD3C 8012963C AC4A0140 */  sw        $t2, 0x140($v0)
/* BFD40 80129640 8FB900E0 */  lw        $t9, 0xe0($sp)
/* BFD44 80129644 24430160 */  addiu     $v1, $v0, 0x160
/* BFD48 80129648 AC590144 */  sw        $t9, 0x144($v0)
/* BFD4C 8012964C AC40014C */  sw        $zero, 0x14c($v0)
/* BFD50 80129650 AC440124 */  sw        $a0, 0x124($v0)
/* BFD54 80129654 3C19F400 */  lui       $t9, 0xf400
/* BFD58 80129658 AC580148 */  sw        $t8, 0x148($v0)
/* BFD5C 8012965C AC590150 */  sw        $t9, 0x150($v0)
/* BFD60 80129660 8FB800E4 */  lw        $t8, 0xe4($sp)
/* BFD64 80129664 3C19E700 */  lui       $t9, 0xe700
/* BFD68 80129668 AC580154 */  sw        $t8, 0x154($v0)
/* BFD6C 8012966C AEE30000 */  sw        $v1, ($s7)
/* BFD70 80129670 24430168 */  addiu     $v1, $v0, 0x168
/* BFD74 80129674 AC590158 */  sw        $t9, 0x158($v0)
/* BFD78 80129678 AC40015C */  sw        $zero, 0x15c($v0)
/* BFD7C 8012967C AEE30000 */  sw        $v1, ($s7)
/* BFD80 80129680 3403C030 */  ori       $v1, $zero, 0xc030
/* BFD84 80129684 AC430164 */  sw        $v1, 0x164($v0)
/* BFD88 80129688 24430170 */  addiu     $v1, $v0, 0x170
/* BFD8C 8012968C AC4C0160 */  sw        $t4, 0x160($v0)
/* BFD90 80129690 AEE30000 */  sw        $v1, ($s7)
/* BFD94 80129694 AC480168 */  sw        $t0, 0x168($v0)
/* BFD98 80129698 8FB800D4 */  lw        $t8, 0xd4($sp)
/* BFD9C 8012969C AC58016C */  sw        $t8, 0x16c($v0)
/* BFDA0 801296A0 97C40516 */  lhu       $a0, 0x516($fp)
/* BFDA4 801296A4 24430178 */  addiu     $v1, $v0, 0x178
/* BFDA8 801296A8 AEE30000 */  sw        $v1, ($s7)
/* BFDAC 801296AC 8FB900D8 */  lw        $t9, 0xd8($sp)
/* BFDB0 801296B0 24430180 */  addiu     $v1, $v0, 0x180
/* BFDB4 801296B4 AC590174 */  sw        $t9, 0x174($v0)
/* BFDB8 801296B8 AEE30000 */  sw        $v1, ($s7)
/* BFDBC 801296BC 24430188 */  addiu     $v1, $v0, 0x188
/* BFDC0 801296C0 2484000C */  addiu     $a0, $a0, 0xc
/* BFDC4 801296C4 00042080 */  sll       $a0, $a0, 2
/* BFDC8 801296C8 30840FFF */  andi      $a0, $a0, 0xfff
/* BFDCC 801296CC 00852025 */  or        $a0, $a0, $a1
/* BFDD0 801296D0 AC470178 */  sw        $a3, 0x178($v0)
/* BFDD4 801296D4 AC40017C */  sw        $zero, 0x17c($v0)
/* BFDD8 801296D8 AEE30000 */  sw        $v1, ($s7)
/* BFDDC 801296DC AC460180 */  sw        $a2, 0x180($v0)
/* BFDE0 801296E0 AC490184 */  sw        $t1, 0x184($v0)
/* BFDE4 801296E4 0804A6B3 */  j         .L80129ACC
/* BFDE8 801296E8 AC440170 */   sw       $a0, 0x170($v0)
glabel L801296EC_BFDEC
/* BFDEC 801296EC 0000902D */  daddu     $s2, $zero, $zero
/* BFDF0 801296F0 240400FF */  addiu     $a0, $zero, 0xff
/* BFDF4 801296F4 24050020 */  addiu     $a1, $zero, 0x20
/* BFDF8 801296F8 2402000C */  addiu     $v0, $zero, 0xc
/* BFDFC 801296FC 00A0302D */  daddu     $a2, $a1, $zero
/* BFE00 80129700 3C078015 */  lui       $a3, %hi(gMessageDrawStatePtr)
/* BFE04 80129704 8CE75D74 */  lw        $a3, %lo(gMessageDrawStatePtr)($a3)
/* BFE08 80129708 2411002B */  addiu     $s1, $zero, 0x2b
/* BFE0C 8012970C 24180005 */  addiu     $t8, $zero, 5
/* BFE10 80129710 A4E20046 */  sh        $v0, 0x46($a3)
/* BFE14 80129714 24020028 */  addiu     $v0, $zero, 0x28
/* BFE18 80129718 A4F80048 */  sh        $t8, 0x48($a3)
/* BFE1C 8012971C A7C2045A */  sh        $v0, 0x45a($fp)
/* BFE20 80129720 2402001C */  addiu     $v0, $zero, 0x1c
/* BFE24 80129724 A7C2045C */  sh        $v0, 0x45c($fp)
/* BFE28 80129728 2402002D */  addiu     $v0, $zero, 0x2d
/* BFE2C 8012972C ACE20000 */  sw        $v0, ($a3)
/* BFE30 80129730 00A0102D */  daddu     $v0, $a1, $zero
/* BFE34 80129734 ACE20008 */  sw        $v0, 8($a3)
/* BFE38 80129738 24020110 */  addiu     $v0, $zero, 0x110
/* BFE3C 8012973C ACE20004 */  sw        $v0, 4($a3)
/* BFE40 80129740 94E30006 */  lhu       $v1, 6($a3)
/* BFE44 80129744 24020051 */  addiu     $v0, $zero, 0x51
/* BFE48 80129748 ACE2000C */  sw        $v0, 0xc($a3)
/* BFE4C 8012974C 2463FFEB */  addiu     $v1, $v1, -0x15
/* BFE50 80129750 A7C30482 */  sh        $v1, 0x482($fp)
/* BFE54 80129754 94E2000E */  lhu       $v0, 0xe($a3)
/* BFE58 80129758 241000EA */  addiu     $s0, $zero, 0xea
/* BFE5C 8012975C 2442FFEC */  addiu     $v0, $v0, -0x14
/* BFE60 80129760 A7C20484 */  sh        $v0, 0x484($fp)
/* BFE64 80129764 A0E0002B */  sb        $zero, 0x2b($a3)
/* BFE68 80129768 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* BFE6C 8012976C 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* BFE70 80129770 0000382D */  daddu     $a3, $zero, $zero
/* BFE74 80129774 A440004A */  sh        $zero, 0x4a($v0)
/* BFE78 80129778 2402001B */  addiu     $v0, $zero, 0x1b
/* BFE7C 8012977C 24190001 */  addiu     $t9, $zero, 1
/* BFE80 80129780 AFB10010 */  sw        $s1, 0x10($sp)
/* BFE84 80129784 AFA20014 */  sw        $v0, 0x14($sp)
/* BFE88 80129788 AFB00018 */  sw        $s0, 0x18($sp)
/* BFE8C 8012978C 0C04B26A */  jal       msg_draw_prim_rect
/* BFE90 80129790 AFB9001C */   sw       $t9, 0x1c($sp)
/* BFE94 80129794 24040020 */  addiu     $a0, $zero, 0x20
/* BFE98 80129798 240500FF */  addiu     $a1, $zero, 0xff
/* BFE9C 8012979C 0080302D */  daddu     $a2, $a0, $zero
/* BFEA0 801297A0 0000382D */  daddu     $a3, $zero, $zero
/* BFEA4 801297A4 24020056 */  addiu     $v0, $zero, 0x56
/* BFEA8 801297A8 24180001 */  addiu     $t8, $zero, 1
/* BFEAC 801297AC AFB10010 */  sw        $s1, 0x10($sp)
/* BFEB0 801297B0 AFA20014 */  sw        $v0, 0x14($sp)
/* BFEB4 801297B4 AFB00018 */  sw        $s0, 0x18($sp)
/* BFEB8 801297B8 0C04B26A */  jal       msg_draw_prim_rect
/* BFEBC 801297BC AFB8001C */   sw       $t8, 0x1c($sp)
/* BFEC0 801297C0 93C204F8 */  lbu       $v0, 0x4f8($fp)
/* BFEC4 801297C4 24190002 */  addiu     $t9, $zero, 2
/* BFEC8 801297C8 14590010 */  bne       $v0, $t9, .L8012980C
/* BFECC 801297CC 241300FF */   addiu    $s3, $zero, 0xff
/* BFED0 801297D0 93C20509 */  lbu       $v0, 0x509($fp)
/* BFED4 801297D4 24180003 */  addiu     $t8, $zero, 3
/* BFED8 801297D8 00021980 */  sll       $v1, $v0, 6
/* BFEDC 801297DC 24730050 */  addiu     $s3, $v1, 0x50
/* BFEE0 801297E0 326300FF */  andi      $v1, $s3, 0xff
/* BFEE4 801297E4 2463FFD0 */  addiu     $v1, $v1, -0x30
/* BFEE8 801297E8 24420001 */  addiu     $v0, $v0, 1
/* BFEEC 801297EC A7A3008E */  sh        $v1, 0x8e($sp)
/* BFEF0 801297F0 A3C20509 */  sb        $v0, 0x509($fp)
/* BFEF4 801297F4 304200FF */  andi      $v0, $v0, 0xff
/* BFEF8 801297F8 14580018 */  bne       $v0, $t8, .L8012985C
/* BFEFC 801297FC 24120001 */   addiu    $s2, $zero, 1
/* BFF00 80129800 24020004 */  addiu     $v0, $zero, 4
/* BFF04 80129804 0804A617 */  j         .L8012985C
/* BFF08 80129808 A3C204F8 */   sb       $v0, 0x4f8($fp)
.L8012980C:
/* BFF0C 8012980C 24190003 */  addiu     $t9, $zero, 3
/* BFF10 80129810 14590013 */  bne       $v0, $t9, .L80129860
/* BFF14 80129814 24040028 */   addiu    $a0, $zero, 0x28
/* BFF18 80129818 93C40512 */  lbu       $a0, 0x512($fp)
/* BFF1C 8012981C 2403FFD0 */  addiu     $v1, $zero, -0x30
/* BFF20 80129820 00041040 */  sll       $v0, $a0, 1
/* BFF24 80129824 00441021 */  addu      $v0, $v0, $a0
/* BFF28 80129828 00021100 */  sll       $v0, $v0, 4
/* BFF2C 8012982C 00629823 */  subu      $s3, $v1, $v0
/* BFF30 80129830 326200FF */  andi      $v0, $s3, 0xff
/* BFF34 80129834 00431021 */  addu      $v0, $v0, $v1
/* BFF38 80129838 24840001 */  addiu     $a0, $a0, 1
/* BFF3C 8012983C A7A2008E */  sh        $v0, 0x8e($sp)
/* BFF40 80129840 A3C40512 */  sb        $a0, 0x512($fp)
/* BFF44 80129844 308400FF */  andi      $a0, $a0, 0xff
/* BFF48 80129848 14990004 */  bne       $a0, $t9, .L8012985C
/* BFF4C 8012984C 24120001 */   addiu    $s2, $zero, 1
/* BFF50 80129850 8FC204FC */  lw        $v0, 0x4fc($fp)
/* BFF54 80129854 34420001 */  ori       $v0, $v0, 1
/* BFF58 80129858 AFC204FC */  sw        $v0, 0x4fc($fp)
.L8012985C:
/* BFF5C 8012985C 24040028 */  addiu     $a0, $zero, 0x28
.L80129860:
/* BFF60 80129860 2405001C */  addiu     $a1, $zero, 0x1c
/* BFF64 80129864 240600F0 */  addiu     $a2, $zero, 0xf0
/* BFF68 80129868 24020006 */  addiu     $v0, $zero, 6
/* BFF6C 8012986C 3C038015 */  lui       $v1, %hi(gMessageDrawStatePtr)
/* BFF70 80129870 8C635D74 */  lw        $v1, %lo(gMessageDrawStatePtr)($v1)
/* BFF74 80129874 2407003A */  addiu     $a3, $zero, 0x3a
/* BFF78 80129878 AFA20010 */  sw        $v0, 0x10($sp)
/* BFF7C 8012987C 9062002B */  lbu       $v0, 0x2b($v1)
/* BFF80 80129880 327000FF */  andi      $s0, $s3, 0xff
/* BFF84 80129884 AFB20018 */  sw        $s2, 0x18($sp)
/* BFF88 80129888 AFB0001C */  sw        $s0, 0x1c($sp)
/* BFF8C 8012988C AFB00020 */  sw        $s0, 0x20($sp)
/* BFF90 80129890 0C04B6D6 */  jal       msg_draw_frame
/* BFF94 80129894 AFA20014 */   sw       $v0, 0x14($sp)
/* BFF98 80129898 24050096 */  addiu     $a1, $zero, 0x96
/* BFF9C 8012989C 24060069 */  addiu     $a2, $zero, 0x69
/* BFFA0 801298A0 AFA00010 */  sw        $zero, 0x10($sp)
/* BFFA4 801298A4 8FC30548 */  lw        $v1, 0x548($fp)
/* BFFA8 801298A8 24020055 */  addiu     $v0, $zero, 0x55
/* BFFAC 801298AC AFA20018 */  sw        $v0, 0x18($sp)
/* BFFB0 801298B0 24020061 */  addiu     $v0, $zero, 0x61
/* BFFB4 801298B4 2418000A */  addiu     $t8, $zero, 0xa
/* BFFB8 801298B8 0300C82D */  daddu     $t9, $t8, $zero
/* BFFBC 801298BC 2412012C */  addiu     $s2, $zero, 0x12c
/* BFFC0 801298C0 241100DC */  addiu     $s1, $zero, 0xdc
/* BFFC4 801298C4 AFA2001C */  sw        $v0, 0x1c($sp)
/* BFFC8 801298C8 AFB80020 */  sw        $t8, 0x20($sp)
/* BFFCC 801298CC AFB90024 */  sw        $t9, 0x24($sp)
/* BFFD0 801298D0 AFB20028 */  sw        $s2, 0x28($sp)
/* BFFD4 801298D4 AFB1002C */  sw        $s1, 0x2c($sp)
/* BFFD8 801298D8 AFB00030 */  sw        $s0, 0x30($sp)
/* BFFDC 801298DC AFA30014 */  sw        $v1, 0x14($sp)
/* BFFE0 801298E0 8FC40544 */  lw        $a0, 0x544($fp)
/* BFFE4 801298E4 0C04BA68 */  jal       draw_ci_image_with_clipping
/* BFFE8 801298E8 24070002 */   addiu    $a3, $zero, 2
/* BFFEC 801298EC 24050046 */  addiu     $a1, $zero, 0x46
/* BFFF0 801298F0 2406005F */  addiu     $a2, $zero, 0x5f
/* BFFF4 801298F4 24180001 */  addiu     $t8, $zero, 1
/* BFFF8 801298F8 AFB80010 */  sw        $t8, 0x10($sp)
/* BFFFC 801298FC 8FC30550 */  lw        $v1, 0x550($fp)
/* C0000 80129900 240200A0 */  addiu     $v0, $zero, 0xa0
/* C0004 80129904 AFA20018 */  sw        $v0, 0x18($sp)
/* C0008 80129908 24020066 */  addiu     $v0, $zero, 0x66
/* C000C 8012990C 2419000A */  addiu     $t9, $zero, 0xa
/* C0010 80129910 0320C02D */  daddu     $t8, $t9, $zero
/* C0014 80129914 AFA2001C */  sw        $v0, 0x1c($sp)
/* C0018 80129918 AFB90020 */  sw        $t9, 0x20($sp)
/* C001C 8012991C AFB80024 */  sw        $t8, 0x24($sp)
/* C0020 80129920 AFB20028 */  sw        $s2, 0x28($sp)
/* C0024 80129924 AFB1002C */  sw        $s1, 0x2c($sp)
/* C0028 80129928 AFB00030 */  sw        $s0, 0x30($sp)
/* C002C 8012992C AFA30014 */  sw        $v1, 0x14($sp)
/* C0030 80129930 8FC4054C */  lw        $a0, 0x54c($fp)
/* C0034 80129934 0C04BA68 */  jal       draw_ci_image_with_clipping
/* C0038 80129938 24070002 */   addiu    $a3, $zero, 2
/* C003C 8012993C 0C04B0B8 */  jal       msg_reset_gfx_state
/* C0040 80129940 327300FF */   andi     $s3, $s3, 0xff
/* C0044 80129944 3C038015 */  lui       $v1, %hi(gMessageDrawStatePtr)
/* C0048 80129948 8C635D74 */  lw        $v1, %lo(gMessageDrawStatePtr)($v1)
/* C004C 8012994C 8C620020 */  lw        $v0, 0x20($v1)
/* C0050 80129950 0804AAD4 */  j         .L8012AB50
/* C0054 80129954 A7B300AE */   sh       $s3, 0xae($sp)
glabel L80129958_C0058
/* C0058 80129958 3C038015 */  lui       $v1, %hi(gMessageDrawStatePtr)
/* C005C 8012995C 8C635D74 */  lw        $v1, %lo(gMessageDrawStatePtr)($v1)
/* C0060 80129960 94640034 */  lhu       $a0, 0x34($v1)
/* C0064 80129964 24020010 */  addiu     $v0, $zero, 0x10
/* C0068 80129968 A4620046 */  sh        $v0, 0x46($v1)
/* C006C 8012996C 24020004 */  addiu     $v0, $zero, 4
/* C0070 80129970 A4620048 */  sh        $v0, 0x48($v1)
/* C0074 80129974 2402013F */  addiu     $v0, $zero, 0x13f
/* C0078 80129978 AC620004 */  sw        $v0, 4($v1)
/* C007C 8012997C 240200EF */  addiu     $v0, $zero, 0xef
/* C0080 80129980 AC600000 */  sw        $zero, ($v1)
/* C0084 80129984 AC600008 */  sw        $zero, 8($v1)
/* C0088 80129988 AC62000C */  sw        $v0, 0xc($v1)
/* C008C 8012998C A460004A */  sh        $zero, 0x4a($v1)
/* C0090 80129990 34840010 */  ori       $a0, $a0, 0x10
/* C0094 80129994 A4640034 */  sh        $a0, 0x34($v1)
/* C0098 80129998 93C204F8 */  lbu       $v0, 0x4f8($fp)
/* C009C 8012999C 2442FFF3 */  addiu     $v0, $v0, -0xd
/* C00A0 801299A0 2C420002 */  sltiu     $v0, $v0, 2
/* C00A4 801299A4 10400004 */  beqz      $v0, .L801299B8
/* C00A8 801299A8 0000202D */   daddu    $a0, $zero, $zero
/* C00AC 801299AC A7C0045A */  sh        $zero, 0x45a($fp)
/* C00B0 801299B0 0804A6B3 */  j         .L80129ACC
/* C00B4 801299B4 A7C0045C */   sh       $zero, 0x45c($fp)
.L801299B8:
/* C00B8 801299B8 0080282D */  daddu     $a1, $a0, $zero
/* C00BC 801299BC 97C30514 */  lhu       $v1, 0x514($fp)
/* C00C0 801299C0 240200A0 */  addiu     $v0, $zero, 0xa0
/* C00C4 801299C4 00031842 */  srl       $v1, $v1, 1
/* C00C8 801299C8 00431023 */  subu      $v0, $v0, $v1
/* C00CC 801299CC A7C2045A */  sh        $v0, 0x45a($fp)
/* C00D0 801299D0 87C6045A */  lh        $a2, 0x45a($fp)
/* C00D4 801299D4 24020038 */  addiu     $v0, $zero, 0x38
/* C00D8 801299D8 A7C2045C */  sh        $v0, 0x45c($fp)
/* C00DC 801299DC AFA00010 */  sw        $zero, 0x10($sp)
/* C00E0 801299E0 97C20514 */  lhu       $v0, 0x514($fp)
/* C00E4 801299E4 24070038 */  addiu     $a3, $zero, 0x38
/* C00E8 801299E8 AFA20014 */  sw        $v0, 0x14($sp)
/* C00EC 801299EC 97C30516 */  lhu       $v1, 0x516($fp)
/* C00F0 801299F0 241900FF */  addiu     $t9, $zero, 0xff
/* C00F4 801299F4 24020140 */  addiu     $v0, $zero, 0x140
/* C00F8 801299F8 AFA20044 */  sw        $v0, 0x44($sp)
/* C00FC 801299FC 240200F0 */  addiu     $v0, $zero, 0xf0
/* C0100 80129A00 AFB9001C */  sw        $t9, 0x1c($sp)
/* C0104 80129A04 AFA00020 */  sw        $zero, 0x20($sp)
/* C0108 80129A08 AFA00024 */  sw        $zero, 0x24($sp)
/* C010C 80129A0C AFA00028 */  sw        $zero, 0x28($sp)
/* C0110 80129A10 AFA0002C */  sw        $zero, 0x2c($sp)
/* C0114 80129A14 AFA00030 */  sw        $zero, 0x30($sp)
/* C0118 80129A18 AFA00034 */  sw        $zero, 0x34($sp)
/* C011C 80129A1C AFA00038 */  sw        $zero, 0x38($sp)
/* C0120 80129A20 AFA0003C */  sw        $zero, 0x3c($sp)
/* C0124 80129A24 AFA00040 */  sw        $zero, 0x40($sp)
/* C0128 80129A28 AFA20048 */  sw        $v0, 0x48($sp)
/* C012C 80129A2C AFA0004C */  sw        $zero, 0x4c($sp)
/* C0130 80129A30 0C03D4B8 */  jal       draw_box
/* C0134 80129A34 AFA30018 */   sw       $v1, 0x18($sp)
/* C0138 80129A38 0804A6B3 */  j         .L80129ACC
/* C013C 80129A3C 00000000 */   nop
glabel L80129A40_C0140
/* C0140 80129A40 3C048015 */  lui       $a0, %hi(gMessageDrawStatePtr)
/* C0144 80129A44 8C845D74 */  lw        $a0, %lo(gMessageDrawStatePtr)($a0)
/* C0148 80129A48 2402003C */  addiu     $v0, $zero, 0x3c
/* C014C 80129A4C A7C2045A */  sh        $v0, 0x45a($fp)
/* C0150 80129A50 2402006E */  addiu     $v0, $zero, 0x6e
/* C0154 80129A54 A7C2045C */  sh        $v0, 0x45c($fp)
/* C0158 80129A58 240200C8 */  addiu     $v0, $zero, 0xc8
/* C015C 80129A5C A7C20514 */  sh        $v0, 0x514($fp)
/* C0160 80129A60 24020032 */  addiu     $v0, $zero, 0x32
/* C0164 80129A64 A7C20516 */  sh        $v0, 0x516($fp)
/* C0168 80129A68 2402FFFE */  addiu     $v0, $zero, -2
/* C016C 80129A6C A4800046 */  sh        $zero, 0x46($a0)
/* C0170 80129A70 A4820048 */  sh        $v0, 0x48($a0)
/* C0174 80129A74 87C2045A */  lh        $v0, 0x45a($fp)
/* C0178 80129A78 AC820000 */  sw        $v0, ($a0)
/* C017C 80129A7C 87C2045C */  lh        $v0, 0x45c($fp)
/* C0180 80129A80 AC820008 */  sw        $v0, 8($a0)
/* C0184 80129A84 87C2045A */  lh        $v0, 0x45a($fp)
/* C0188 80129A88 97C30514 */  lhu       $v1, 0x514($fp)
/* C018C 80129A8C 00431021 */  addu      $v0, $v0, $v1
/* C0190 80129A90 AC820004 */  sw        $v0, 4($a0)
/* C0194 80129A94 87C2045C */  lh        $v0, 0x45c($fp)
/* C0198 80129A98 97C30516 */  lhu       $v1, 0x516($fp)
/* C019C 80129A9C 00431021 */  addu      $v0, $v0, $v1
/* C01A0 80129AA0 AC82000C */  sw        $v0, 0xc($a0)
/* C01A4 80129AA4 97C3045A */  lhu       $v1, 0x45a($fp)
/* C01A8 80129AA8 97C20514 */  lhu       $v0, 0x514($fp)
/* C01AC 80129AAC 97C40516 */  lhu       $a0, 0x516($fp)
/* C01B0 80129AB0 00621821 */  addu      $v1, $v1, $v0
/* C01B4 80129AB4 97C2045C */  lhu       $v0, 0x45c($fp)
/* C01B8 80129AB8 2463FFF6 */  addiu     $v1, $v1, -0xa
/* C01BC 80129ABC A7C30482 */  sh        $v1, 0x482($fp)
/* C01C0 80129AC0 00441021 */  addu      $v0, $v0, $a0
/* C01C4 80129AC4 2442FFF6 */  addiu     $v0, $v0, -0xa
/* C01C8 80129AC8 A7C20484 */  sh        $v0, 0x484($fp)
.L80129ACC:
/* C01CC 80129ACC 0C04B0B8 */  jal       msg_reset_gfx_state
/* C01D0 80129AD0 00000000 */   nop
/* C01D4 80129AD4 0804AAD1 */  j         L8012AB44_C1244
/* C01D8 80129AD8 00000000 */   nop
glabel L80129ADC_C01DC
/* C01DC 80129ADC 93C304F8 */  lbu       $v1, 0x4f8($fp)
/* C01E0 80129AE0 2402000C */  addiu     $v0, $zero, 0xc
/* C01E4 80129AE4 1462000A */  bne       $v1, $v0, .L80129B10
/* C01E8 80129AE8 2402000B */   addiu    $v0, $zero, 0xb
/* C01EC 80129AEC 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* C01F0 80129AF0 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* C01F4 80129AF4 93C30487 */  lbu       $v1, 0x487($fp)
/* C01F8 80129AF8 90420050 */  lbu       $v0, 0x50($v0)
/* C01FC 80129AFC 0043102B */  sltu      $v0, $v0, $v1
/* C0200 80129B00 14400037 */  bnez      $v0, .L80129BE0
/* C0204 80129B04 24180001 */   addiu    $t8, $zero, 1
/* C0208 80129B08 0804A6F8 */  j         .L80129BE0
/* C020C 80129B0C A7B80080 */   sh       $t8, 0x80($sp)
.L80129B10:
/* C0210 80129B10 14620033 */  bne       $v1, $v0, .L80129BE0
/* C0214 80129B14 00000000 */   nop
/* C0218 80129B18 93C50487 */  lbu       $a1, 0x487($fp)
/* C021C 80129B1C 00051040 */  sll       $v0, $a1, 1
/* C0220 80129B20 03C21021 */  addu      $v0, $fp, $v0
/* C0224 80129B24 94430488 */  lhu       $v1, 0x488($v0)
/* C0228 80129B28 8FC20460 */  lw        $v0, 0x460($fp)
/* C022C 80129B2C 0043102A */  slt       $v0, $v0, $v1
/* C0230 80129B30 10400009 */  beqz      $v0, .L80129B58
/* C0234 80129B34 00A0182D */   daddu    $v1, $a1, $zero
/* C0238 80129B38 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* C023C 80129B3C 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* C0240 80129B40 90420050 */  lbu       $v0, 0x50($v0)
/* C0244 80129B44 0045102B */  sltu      $v0, $v0, $a1
/* C0248 80129B48 14400025 */  bnez      $v0, .L80129BE0
/* C024C 80129B4C 24190001 */   addiu    $t9, $zero, 1
/* C0250 80129B50 0804A6F8 */  j         .L80129BE0
/* C0254 80129B54 A7B90080 */   sh       $t9, 0x80($sp)
.L80129B58:
/* C0258 80129B58 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* C025C 80129B5C 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* C0260 80129B60 90440050 */  lbu       $a0, 0x50($v0)
/* C0264 80129B64 0064102B */  sltu      $v0, $v1, $a0
/* C0268 80129B68 10400003 */  beqz      $v0, .L80129B78
/* C026C 80129B6C 24180001 */   addiu    $t8, $zero, 1
/* C0270 80129B70 0804A6F8 */  j         .L80129BE0
/* C0274 80129B74 A7B80080 */   sh       $t8, 0x80($sp)
.L80129B78:
/* C0278 80129B78 0083102B */  sltu      $v0, $a0, $v1
/* C027C 80129B7C 14400018 */  bnez      $v0, .L80129BE0
/* C0280 80129B80 00000000 */   nop
/* C0284 80129B84 93C3053C */  lbu       $v1, 0x53c($fp)
/* C0288 80129B88 2C620002 */  sltiu     $v0, $v1, 2
/* C028C 80129B8C 14400014 */  bnez      $v0, .L80129BE0
/* C0290 80129B90 24040024 */   addiu    $a0, $zero, 0x24
/* C0294 80129B94 24190002 */  addiu     $t9, $zero, 2
/* C0298 80129B98 14790002 */  bne       $v1, $t9, .L80129BA4
/* C029C 80129B9C 24020030 */   addiu    $v0, $zero, 0x30
/* C02A0 80129BA0 24020020 */  addiu     $v0, $zero, 0x20
.L80129BA4:
/* C02A4 80129BA4 97C304C8 */  lhu       $v1, 0x4c8($fp)
/* C02A8 80129BA8 0062102A */  slt       $v0, $v1, $v0
/* C02AC 80129BAC 1040000C */  beqz      $v0, .L80129BE0
/* C02B0 80129BB0 2C620011 */   sltiu    $v0, $v1, 0x11
/* C02B4 80129BB4 54400001 */  bnel      $v0, $zero, .L80129BBC
/* C02B8 80129BB8 24040038 */   addiu    $a0, $zero, 0x38
.L80129BBC:
/* C02BC 80129BBC 97C204CC */  lhu       $v0, 0x4cc($fp)
/* C02C0 80129BC0 00820018 */  mult      $a0, $v0
/* C02C4 80129BC4 241800FF */  addiu     $t8, $zero, 0xff
/* C02C8 80129BC8 0000C812 */  mflo      $t9
/* C02CC 80129BCC 03191023 */  subu      $v0, $t8, $t9
/* C02D0 80129BD0 A7A2008E */  sh        $v0, 0x8e($sp)
/* C02D4 80129BD4 00021400 */  sll       $v0, $v0, 0x10
/* C02D8 80129BD8 04420001 */  bltzl     $v0, .L80129BE0
/* C02DC 80129BDC A7A0008E */   sh       $zero, 0x8e($sp)
.L80129BE0:
/* C02E0 80129BE0 3C038015 */  lui       $v1, %hi(gMessageDrawStatePtr)
/* C02E4 80129BE4 8C635D74 */  lw        $v1, %lo(gMessageDrawStatePtr)($v1)
/* C02E8 80129BE8 90620050 */  lbu       $v0, 0x50($v1)
/* C02EC 80129BEC 24420001 */  addiu     $v0, $v0, 1
/* C02F0 80129BF0 0804A9B1 */  j         L8012A6C4_C0DC4
/* C02F4 80129BF4 A0620050 */   sb       $v0, 0x50($v1)
glabel L80129BF8_C02F8
/* C02F8 80129BF8 24180001 */  addiu     $t8, $zero, 1
/* C02FC 80129BFC 0804AFDC */  j         L8012BF70_C2670
/* C0300 80129C00 A7B80080 */   sh       $t8, 0x80($sp)
glabel L80129C04_C0304
/* C0304 80129C04 3C038015 */  lui       $v1, %hi(gMessageDrawStatePtr)
/* C0308 80129C08 8C635D74 */  lw        $v1, %lo(gMessageDrawStatePtr)($v1)
/* C030C 80129C0C 8C620020 */  lw        $v0, 0x20($v1)
/* C0310 80129C10 8C64004C */  lw        $a0, 0x4c($v1)
/* C0314 80129C14 24420001 */  addiu     $v0, $v0, 1
/* C0318 80129C18 00822021 */  addu      $a0, $a0, $v0
/* C031C 80129C1C AC620020 */  sw        $v0, 0x20($v1)
/* C0320 80129C20 90830000 */  lbu       $v1, ($a0)
/* C0324 80129C24 2C62001F */  sltiu     $v0, $v1, 0x1f
/* C0328 80129C28 104008D1 */  beqz      $v0, L8012BF70_C2670
/* C032C 80129C2C 00031080 */   sll      $v0, $v1, 2
/* C0330 80129C30 3C018015 */  lui       $at, %hi(jtbl_801507E0)
/* C0334 80129C34 00220821 */  addu      $at, $at, $v0
/* C0338 80129C38 8C2207E0 */  lw        $v0, %lo(jtbl_801507E0)($at)
/* C033C 80129C3C 00400008 */  jr        $v0
/* C0340 80129C40 00000000 */   nop
glabel L80129C44_C0344
/* C0344 80129C44 3C048015 */  lui       $a0, %hi(gMessageDrawStatePtr)
/* C0348 80129C48 8C845D74 */  lw        $a0, %lo(gMessageDrawStatePtr)($a0)
/* C034C 80129C4C 8C820020 */  lw        $v0, 0x20($a0)
/* C0350 80129C50 8C83004C */  lw        $v1, 0x4c($a0)
/* C0354 80129C54 00431021 */  addu      $v0, $v0, $v1
/* C0358 80129C58 90450001 */  lbu       $a1, 1($v0)
/* C035C 80129C5C 8C820020 */  lw        $v0, 0x20($a0)
/* C0360 80129C60 94830034 */  lhu       $v1, 0x34($a0)
/* C0364 80129C64 24420002 */  addiu     $v0, $v0, 2
/* C0368 80129C68 34630010 */  ori       $v1, $v1, 0x10
/* C036C 80129C6C AC820020 */  sw        $v0, 0x20($a0)
/* C0370 80129C70 A4830034 */  sh        $v1, 0x34($a0)
/* C0374 80129C74 0804AFDC */  j         L8012BF70_C2670
/* C0378 80129C78 A485003C */   sh       $a1, 0x3c($a0)
glabel L80129C7C_C037C
/* C037C 80129C7C 3C048015 */  lui       $a0, %hi(gMessageDrawStatePtr)
/* C0380 80129C80 8C845D74 */  lw        $a0, %lo(gMessageDrawStatePtr)($a0)
/* C0384 80129C84 8C830020 */  lw        $v1, 0x20($a0)
/* C0388 80129C88 8C82004C */  lw        $v0, 0x4c($a0)
/* C038C 80129C8C 00621821 */  addu      $v1, $v1, $v0
/* C0390 80129C90 8C820020 */  lw        $v0, 0x20($a0)
/* C0394 80129C94 90630001 */  lbu       $v1, 1($v1)
/* C0398 80129C98 24420002 */  addiu     $v0, $v0, 2
/* C039C 80129C9C AC820020 */  sw        $v0, 0x20($a0)
/* C03A0 80129CA0 0804AFDC */  j         L8012BF70_C2670
/* C03A4 80129CA4 A483003E */   sh       $v1, 0x3e($a0)
glabel L80129CA8_C03A8
/* C03A8 80129CA8 3C048015 */  lui       $a0, %hi(gMessageDrawStatePtr)
/* C03AC 80129CAC 8C845D74 */  lw        $a0, %lo(gMessageDrawStatePtr)($a0)
/* C03B0 80129CB0 8C820020 */  lw        $v0, 0x20($a0)
/* C03B4 80129CB4 8C83004C */  lw        $v1, 0x4c($a0)
/* C03B8 80129CB8 00431021 */  addu      $v0, $v0, $v1
/* C03BC 80129CBC 90450001 */  lbu       $a1, 1($v0)
/* C03C0 80129CC0 94820034 */  lhu       $v0, 0x34($a0)
/* C03C4 80129CC4 8C830020 */  lw        $v1, 0x20($a0)
/* C03C8 80129CC8 34420010 */  ori       $v0, $v0, 0x10
/* C03CC 80129CCC 24630002 */  addiu     $v1, $v1, 2
/* C03D0 80129CD0 A4820034 */  sh        $v0, 0x34($a0)
/* C03D4 80129CD4 AC830020 */  sw        $v1, 0x20($a0)
/* C03D8 80129CD8 0804AFDC */  j         L8012BF70_C2670
/* C03DC 80129CDC A485004A */   sh       $a1, 0x4a($a0)
glabel L80129CE0_C03E0
/* C03E0 80129CE0 3C048015 */  lui       $a0, %hi(gMessageDrawStatePtr)
/* C03E4 80129CE4 8C845D74 */  lw        $a0, %lo(gMessageDrawStatePtr)($a0)
/* C03E8 80129CE8 8C820020 */  lw        $v0, 0x20($a0)
/* C03EC 80129CEC 8C83004C */  lw        $v1, 0x4c($a0)
/* C03F0 80129CF0 00431021 */  addu      $v0, $v0, $v1
/* C03F4 80129CF4 90420001 */  lbu       $v0, 1($v0)
/* C03F8 80129CF8 0804AAD1 */  j         L8012AB44_C1244
/* C03FC 80129CFC A0820040 */   sb       $v0, 0x40($a0)
glabel L80129D00_C0400
/* C0400 80129D00 3C048015 */  lui       $a0, %hi(gMessageDrawStatePtr)
/* C0404 80129D04 8C845D74 */  lw        $a0, %lo(gMessageDrawStatePtr)($a0)
/* C0408 80129D08 8C820020 */  lw        $v0, 0x20($a0)
/* C040C 80129D0C 8C83004C */  lw        $v1, 0x4c($a0)
/* C0410 80129D10 00431021 */  addu      $v0, $v0, $v1
/* C0414 80129D14 90420001 */  lbu       $v0, 1($v0)
/* C0418 80129D18 3C013D80 */  lui       $at, 0x3d80
/* C041C 80129D1C 44812000 */  mtc1      $at, $f4
/* C0420 80129D20 3043000F */  andi      $v1, $v0, 0xf
/* C0424 80129D24 44830000 */  mtc1      $v1, $f0
/* C0428 80129D28 00000000 */  nop
/* C042C 80129D2C 46800020 */  cvt.s.w   $f0, $f0
/* C0430 80129D30 46040002 */  mul.s     $f0, $f0, $f4
/* C0434 80129D34 00000000 */  nop
/* C0438 80129D38 00021102 */  srl       $v0, $v0, 4
/* C043C 80129D3C 44821000 */  mtc1      $v0, $f2
/* C0440 80129D40 00000000 */  nop
/* C0444 80129D44 468010A0 */  cvt.s.w   $f2, $f2
/* C0448 80129D48 8C820020 */  lw        $v0, 0x20($a0)
/* C044C 80129D4C 8C83004C */  lw        $v1, 0x4c($a0)
/* C0450 80129D50 46001080 */  add.s     $f2, $f2, $f0
/* C0454 80129D54 00431021 */  addu      $v0, $v0, $v1
/* C0458 80129D58 E4820010 */  swc1      $f2, 0x10($a0)
/* C045C 80129D5C 90420002 */  lbu       $v0, 2($v0)
/* C0460 80129D60 00021902 */  srl       $v1, $v0, 4
/* C0464 80129D64 3042000F */  andi      $v0, $v0, 0xf
/* C0468 80129D68 44820000 */  mtc1      $v0, $f0
/* C046C 80129D6C 00000000 */  nop
/* C0470 80129D70 46800020 */  cvt.s.w   $f0, $f0
/* C0474 80129D74 46040002 */  mul.s     $f0, $f0, $f4
/* C0478 80129D78 00000000 */  nop
/* C047C 80129D7C 3C013FF0 */  lui       $at, 0x3ff0
/* C0480 80129D80 44816800 */  mtc1      $at, $f13
/* C0484 80129D84 44806000 */  mtc1      $zero, $f12
/* C0488 80129D88 44831000 */  mtc1      $v1, $f2
/* C048C 80129D8C 00000000 */  nop
/* C0490 80129D90 468010A0 */  cvt.s.w   $f2, $f2
/* C0494 80129D94 8C820020 */  lw        $v0, 0x20($a0)
/* C0498 80129D98 C4840010 */  lwc1      $f4, 0x10($a0)
/* C049C 80129D9C 46001080 */  add.s     $f2, $f2, $f0
/* C04A0 80129DA0 24420003 */  addiu     $v0, $v0, 3
/* C04A4 80129DA4 46002121 */  cvt.d.s   $f4, $f4
/* C04A8 80129DA8 4624603C */  c.lt.d    $f12, $f4
/* C04AC 80129DAC AC820020 */  sw        $v0, 0x20($a0)
/* C04B0 80129DB0 45010007 */  bc1t      .L80129DD0
/* C04B4 80129DB4 E4820014 */   swc1     $f2, 0x14($a0)
/* C04B8 80129DB8 46001006 */  mov.s     $f0, $f2
/* C04BC 80129DBC 46000021 */  cvt.d.s   $f0, $f0
/* C04C0 80129DC0 4620603C */  c.lt.d    $f12, $f0
/* C04C4 80129DC4 00000000 */  nop
/* C04C8 80129DC8 4500000A */  bc1f      .L80129DF4
/* C04CC 80129DCC 00000000 */   nop
.L80129DD0:
/* C04D0 80129DD0 3C02E300 */  lui       $v0, 0xe300
/* C04D4 80129DD4 8EE30000 */  lw        $v1, ($s7)
/* C04D8 80129DD8 34421201 */  ori       $v0, $v0, 0x1201
/* C04DC 80129DDC 0060202D */  daddu     $a0, $v1, $zero
/* C04E0 80129DE0 24630008 */  addiu     $v1, $v1, 8
/* C04E4 80129DE4 AEE30000 */  sw        $v1, ($s7)
/* C04E8 80129DE8 AC820000 */  sw        $v0, ($a0)
/* C04EC 80129DEC 0804AFDC */  j         L8012BF70_C2670
/* C04F0 80129DF0 AC800004 */   sw       $zero, 4($a0)
.L80129DF4:
/* C04F4 80129DF4 462C203C */  c.lt.d    $f4, $f12
/* C04F8 80129DF8 00000000 */  nop
/* C04FC 80129DFC 45010005 */  bc1t      .L80129E14
/* C0500 80129E00 3C04E300 */   lui      $a0, 0xe300
/* C0504 80129E04 462C003C */  c.lt.d    $f0, $f12
/* C0508 80129E08 00000000 */  nop
/* C050C 80129E0C 45000858 */  bc1f      L8012BF70_C2670
/* C0510 80129E10 00000000 */   nop
.L80129E14:
/* C0514 80129E14 8EE20000 */  lw        $v0, ($s7)
/* C0518 80129E18 34841201 */  ori       $a0, $a0, 0x1201
/* C051C 80129E1C 0040182D */  daddu     $v1, $v0, $zero
/* C0520 80129E20 24420008 */  addiu     $v0, $v0, 8
/* C0524 80129E24 AEE20000 */  sw        $v0, ($s7)
/* C0528 80129E28 24023000 */  addiu     $v0, $zero, 0x3000
/* C052C 80129E2C AC640000 */  sw        $a0, ($v1)
/* C0530 80129E30 0804AFDC */  j         L8012BF70_C2670
/* C0534 80129E34 AC620004 */   sw       $v0, 4($v1)
glabel L80129E38_C0538
/* C0538 80129E38 3C06E300 */  lui       $a2, 0xe300
/* C053C 80129E3C 34C61201 */  ori       $a2, $a2, 0x1201
/* C0540 80129E40 8EE20000 */  lw        $v0, ($s7)
/* C0544 80129E44 3C048015 */  lui       $a0, %hi(gMessageDrawStatePtr)
/* C0548 80129E48 8C845D74 */  lw        $a0, %lo(gMessageDrawStatePtr)($a0)
/* C054C 80129E4C 0040282D */  daddu     $a1, $v0, $zero
/* C0550 80129E50 24420008 */  addiu     $v0, $v0, 8
/* C0554 80129E54 8C830020 */  lw        $v1, 0x20($a0)
/* C0558 80129E58 3C013F80 */  lui       $at, 0x3f80
/* C055C 80129E5C 44816000 */  mtc1      $at, $f12
/* C0560 80129E60 24630001 */  addiu     $v1, $v1, 1
/* C0564 80129E64 E48C0010 */  swc1      $f12, 0x10($a0)
/* C0568 80129E68 E48C0014 */  swc1      $f12, 0x14($a0)
/* C056C 80129E6C AEE20000 */  sw        $v0, ($s7)
/* C0570 80129E70 24023000 */  addiu     $v0, $zero, 0x3000
/* C0574 80129E74 AC830020 */  sw        $v1, 0x20($a0)
/* C0578 80129E78 ACA60000 */  sw        $a2, ($a1)
/* C057C 80129E7C 0804AFDC */  j         L8012BF70_C2670
/* C0580 80129E80 ACA20004 */   sw       $v0, 4($a1)
glabel L80129E84_C0584
/* C0584 80129E84 3C058015 */  lui       $a1, %hi(gMessageDrawStatePtr)
/* C0588 80129E88 8CA55D74 */  lw        $a1, %lo(gMessageDrawStatePtr)($a1)
/* C058C 80129E8C 8CA30020 */  lw        $v1, 0x20($a1)
/* C0590 80129E90 8CA2004C */  lw        $v0, 0x4c($a1)
/* C0594 80129E94 00621821 */  addu      $v1, $v1, $v0
/* C0598 80129E98 90640001 */  lbu       $a0, 1($v1)
/* C059C 80129E9C 8CA20020 */  lw        $v0, 0x20($a1)
/* C05A0 80129EA0 90630002 */  lbu       $v1, 2($v1)
/* C05A4 80129EA4 24420003 */  addiu     $v0, $v0, 3
/* C05A8 80129EA8 00042200 */  sll       $a0, $a0, 8
/* C05AC 80129EAC 00641821 */  addu      $v1, $v1, $a0
/* C05B0 80129EB0 ACA20020 */  sw        $v0, 0x20($a1)
/* C05B4 80129EB4 0804AFDC */  j         L8012BF70_C2670
/* C05B8 80129EB8 A4A30042 */   sh       $v1, 0x42($a1)
glabel L80129EBC_C05BC
/* C05BC 80129EBC 3C048015 */  lui       $a0, %hi(gMessageDrawStatePtr)
/* C05C0 80129EC0 8C845D74 */  lw        $a0, %lo(gMessageDrawStatePtr)($a0)
/* C05C4 80129EC4 8C830020 */  lw        $v1, 0x20($a0)
/* C05C8 80129EC8 8C82004C */  lw        $v0, 0x4c($a0)
/* C05CC 80129ECC 00621821 */  addu      $v1, $v1, $v0
/* C05D0 80129ED0 8C820020 */  lw        $v0, 0x20($a0)
/* C05D4 80129ED4 90630001 */  lbu       $v1, 1($v1)
/* C05D8 80129ED8 0804A7DA */  j         .L80129F68
/* C05DC 80129EDC 24420002 */   addiu    $v0, $v0, 2
glabel L80129EE0_C05E0
/* C05E0 80129EE0 3C048015 */  lui       $a0, %hi(gMessageDrawStatePtr)
/* C05E4 80129EE4 8C845D74 */  lw        $a0, %lo(gMessageDrawStatePtr)($a0)
/* C05E8 80129EE8 8C820020 */  lw        $v0, 0x20($a0)
/* C05EC 80129EEC 8C83004C */  lw        $v1, 0x4c($a0)
/* C05F0 80129EF0 00431021 */  addu      $v0, $v0, $v1
/* C05F4 80129EF4 90450001 */  lbu       $a1, 1($v0)
/* C05F8 80129EF8 8C820020 */  lw        $v0, 0x20($a0)
/* C05FC 80129EFC 94830042 */  lhu       $v1, 0x42($a0)
/* C0600 80129F00 24420002 */  addiu     $v0, $v0, 2
/* C0604 80129F04 00651821 */  addu      $v1, $v1, $a1
/* C0608 80129F08 AC820020 */  sw        $v0, 0x20($a0)
/* C060C 80129F0C 0804AFDC */  j         L8012BF70_C2670
/* C0610 80129F10 A4830042 */   sh       $v1, 0x42($a0)
glabel L80129F14_C0614
/* C0614 80129F14 3C048015 */  lui       $a0, %hi(gMessageDrawStatePtr)
/* C0618 80129F18 8C845D74 */  lw        $a0, %lo(gMessageDrawStatePtr)($a0)
/* C061C 80129F1C 8C820020 */  lw        $v0, 0x20($a0)
/* C0620 80129F20 8C83004C */  lw        $v1, 0x4c($a0)
/* C0624 80129F24 00431021 */  addu      $v0, $v0, $v1
/* C0628 80129F28 90450001 */  lbu       $a1, 1($v0)
/* C062C 80129F2C 8C820020 */  lw        $v0, 0x20($a0)
/* C0630 80129F30 94830044 */  lhu       $v1, 0x44($a0)
/* C0634 80129F34 24420002 */  addiu     $v0, $v0, 2
/* C0638 80129F38 0804A7DA */  j         .L80129F68
/* C063C 80129F3C 00651821 */   addu     $v1, $v1, $a1
glabel L80129F40_C0640
/* C0640 80129F40 3C048015 */  lui       $a0, %hi(gMessageDrawStatePtr)
/* C0644 80129F44 8C845D74 */  lw        $a0, %lo(gMessageDrawStatePtr)($a0)
/* C0648 80129F48 8C820020 */  lw        $v0, 0x20($a0)
/* C064C 80129F4C 8C83004C */  lw        $v1, 0x4c($a0)
/* C0650 80129F50 00431021 */  addu      $v0, $v0, $v1
/* C0654 80129F54 90450001 */  lbu       $a1, 1($v0)
/* C0658 80129F58 8C820020 */  lw        $v0, 0x20($a0)
/* C065C 80129F5C 94830044 */  lhu       $v1, 0x44($a0)
/* C0660 80129F60 24420002 */  addiu     $v0, $v0, 2
/* C0664 80129F64 00651823 */  subu      $v1, $v1, $a1
.L80129F68:
/* C0668 80129F68 AC820020 */  sw        $v0, 0x20($a0)
/* C066C 80129F6C 0804AFDC */  j         L8012BF70_C2670
/* C0670 80129F70 A4830044 */   sh       $v1, 0x44($a0)
glabel L80129F74_C0674
/* C0674 80129F74 3C0B8015 */  lui       $t3, %hi(gMessageDrawStatePtr)
/* C0678 80129F78 8D6B5D74 */  lw        $t3, %lo(gMessageDrawStatePtr)($t3)
/* C067C 80129F7C 8D620020 */  lw        $v0, 0x20($t3)
/* C0680 80129F80 8D63004C */  lw        $v1, 0x4c($t3)
/* C0684 80129F84 00431021 */  addu      $v0, $v0, $v1
/* C0688 80129F88 90430001 */  lbu       $v1, 1($v0)
/* C068C 80129F8C 97AD008E */  lhu       $t5, 0x8e($sp)
/* C0690 80129F90 00031080 */  sll       $v0, $v1, 2
/* C0694 80129F94 00431021 */  addu      $v0, $v0, $v1
/* C0698 80129F98 3C038015 */  lui       $v1, %hi(gMsgVarImages)
/* C069C 80129F9C 8C6312F4 */  lw        $v1, %lo(gMsgVarImages)($v1)
/* C06A0 80129FA0 00021080 */  sll       $v0, $v0, 2
/* C06A4 80129FA4 00626021 */  addu      $t4, $v1, $v0
/* C06A8 80129FA8 000D1400 */  sll       $v0, $t5, 0x10
/* C06AC 80129FAC 00021C03 */  sra       $v1, $v0, 0x10
/* C06B0 80129FB0 286200FF */  slti      $v0, $v1, 0xff
/* C06B4 80129FB4 1040000A */  beqz      $v0, .L80129FE0
/* C06B8 80129FB8 00000000 */   nop
/* C06BC 80129FBC 3C018015 */  lui       $at, %hi(D_80150860)
/* C06C0 80129FC0 D4220860 */  ldc1      $f2, %lo(D_80150860)($at)
/* C06C4 80129FC4 44830000 */  mtc1      $v1, $f0
/* C06C8 80129FC8 00000000 */  nop
/* C06CC 80129FCC 46800021 */  cvt.d.w   $f0, $f0
/* C06D0 80129FD0 46220002 */  mul.d     $f0, $f0, $f2
/* C06D4 80129FD4 00000000 */  nop
/* C06D8 80129FD8 4620030D */  trunc.w.d $f12, $f0
/* C06DC 80129FDC 440D6000 */  mfc1      $t5, $f12
.L80129FE0:
/* C06E0 80129FE0 8D8A0010 */  lw        $t2, 0x10($t4)
/* C06E4 80129FE4 97C4045A */  lhu       $a0, 0x45a($fp)
/* C06E8 80129FE8 95670046 */  lhu       $a3, 0x46($t3)
/* C06EC 80129FEC 95620042 */  lhu       $v0, 0x42($t3)
/* C06F0 80129FF0 97C8045C */  lhu       $t0, 0x45c($fp)
/* C06F4 80129FF4 95690048 */  lhu       $t1, 0x48($t3)
/* C06F8 80129FF8 95630044 */  lhu       $v1, 0x44($t3)
/* C06FC 80129FFC 95850008 */  lhu       $a1, 8($t4)
/* C0700 8012A000 9586000A */  lhu       $a2, 0xa($t4)
/* C0704 8012A004 97B90066 */  lhu       $t9, 0x66($sp)
/* C0708 8012A008 97B80076 */  lhu       $t8, 0x76($sp)
/* C070C 8012A00C 00992021 */  addu      $a0, $a0, $t9
/* C0710 8012A010 00E43821 */  addu      $a3, $a3, $a0
/* C0714 8012A014 00471021 */  addu      $v0, $v0, $a3
/* C0718 8012A018 00581023 */  subu      $v0, $v0, $t8
/* C071C 8012A01C 00021400 */  sll       $v0, $v0, 0x10
/* C0720 8012A020 AFAA0010 */  sw        $t2, 0x10($sp)
/* C0724 8012A024 8D840004 */  lw        $a0, 4($t4)
/* C0728 8012A028 97B9006E */  lhu       $t9, 0x6e($sp)
/* C072C 8012A02C 97B8007E */  lhu       $t8, 0x7e($sp)
/* C0730 8012A030 00021403 */  sra       $v0, $v0, 0x10
/* C0734 8012A034 AFA20018 */  sw        $v0, 0x18($sp)
/* C0738 8012A038 01194021 */  addu      $t0, $t0, $t9
/* C073C 8012A03C 01284821 */  addu      $t1, $t1, $t0
/* C0740 8012A040 00691821 */  addu      $v1, $v1, $t1
/* C0744 8012A044 00781823 */  subu      $v1, $v1, $t8
/* C0748 8012A048 00031C00 */  sll       $v1, $v1, 0x10
/* C074C 8012A04C 00031C03 */  sra       $v1, $v1, 0x10
/* C0750 8012A050 AFA3001C */  sw        $v1, 0x1c($sp)
/* C0754 8012A054 AFA40014 */  sw        $a0, 0x14($sp)
/* C0758 8012A058 95620002 */  lhu       $v0, 2($t3)
/* C075C 8012A05C AFA20020 */  sw        $v0, 0x20($sp)
/* C0760 8012A060 9562000A */  lhu       $v0, 0xa($t3)
/* C0764 8012A064 AFA20024 */  sw        $v0, 0x24($sp)
/* C0768 8012A068 95620006 */  lhu       $v0, 6($t3)
/* C076C 8012A06C 95630002 */  lhu       $v1, 2($t3)
/* C0770 8012A070 00431023 */  subu      $v0, $v0, $v1
/* C0774 8012A074 3042FFFF */  andi      $v0, $v0, 0xffff
/* C0778 8012A078 AFA20028 */  sw        $v0, 0x28($sp)
/* C077C 8012A07C 9563000E */  lhu       $v1, 0xe($t3)
/* C0780 8012A080 9564000A */  lhu       $a0, 0xa($t3)
/* C0784 8012A084 31A200FF */  andi      $v0, $t5, 0xff
/* C0788 8012A088 AFA20030 */  sw        $v0, 0x30($sp)
/* C078C 8012A08C 00641823 */  subu      $v1, $v1, $a0
/* C0790 8012A090 3063FFFF */  andi      $v1, $v1, 0xffff
/* C0794 8012A094 AFA3002C */  sw        $v1, 0x2c($sp)
/* C0798 8012A098 8D840000 */  lw        $a0, ($t4)
/* C079C 8012A09C 0C04BA68 */  jal       draw_ci_image_with_clipping
/* C07A0 8012A0A0 8D87000C */   lw       $a3, 0xc($t4)
/* C07A4 8012A0A4 3C048015 */  lui       $a0, %hi(gMessageDrawStatePtr)
/* C07A8 8012A0A8 8C845D74 */  lw        $a0, %lo(gMessageDrawStatePtr)($a0)
/* C07AC 8012A0AC 94820034 */  lhu       $v0, 0x34($a0)
/* C07B0 8012A0B0 8C830020 */  lw        $v1, 0x20($a0)
/* C07B4 8012A0B4 34420012 */  ori       $v0, $v0, 0x12
/* C07B8 8012A0B8 24630002 */  addiu     $v1, $v1, 2
/* C07BC 8012A0BC A4820034 */  sh        $v0, 0x34($a0)
/* C07C0 8012A0C0 0804AFDC */  j         L8012BF70_C2670
/* C07C4 8012A0C4 AC830020 */   sw       $v1, 0x20($a0)
glabel L8012A0C8_C07C8
/* C07C8 8012A0C8 97B0008E */  lhu       $s0, 0x8e($sp)
/* C07CC 8012A0CC 00101400 */  sll       $v0, $s0, 0x10
/* C07D0 8012A0D0 00021C03 */  sra       $v1, $v0, 0x10
/* C07D4 8012A0D4 286200FF */  slti      $v0, $v1, 0xff
/* C07D8 8012A0D8 1040000A */  beqz      $v0, .L8012A104
/* C07DC 8012A0DC 00000000 */   nop
/* C07E0 8012A0E0 3C018015 */  lui       $at, %hi(D_80150868)
/* C07E4 8012A0E4 D4220868 */  ldc1      $f2, %lo(D_80150868)($at)
/* C07E8 8012A0E8 44830000 */  mtc1      $v1, $f0
/* C07EC 8012A0EC 00000000 */  nop
/* C07F0 8012A0F0 46800021 */  cvt.d.w   $f0, $f0
/* C07F4 8012A0F4 46220002 */  mul.d     $f0, $f0, $f2
/* C07F8 8012A0F8 00000000 */  nop
/* C07FC 8012A0FC 4620030D */  trunc.w.d $f12, $f0
/* C0800 8012A100 44106000 */  mfc1      $s0, $f12
.L8012A104:
/* C0804 8012A104 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* C0808 8012A108 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* C080C 8012A10C 8C430020 */  lw        $v1, 0x20($v0)
/* C0810 8012A110 8C42004C */  lw        $v0, 0x4c($v0)
/* C0814 8012A114 27A40050 */  addiu     $a0, $sp, 0x50
/* C0818 8012A118 00621821 */  addu      $v1, $v1, $v0
/* C081C 8012A11C 90660003 */  lbu       $a2, 3($v1)
/* C0820 8012A120 90650001 */  lbu       $a1, 1($v1)
/* C0824 8012A124 90620002 */  lbu       $v0, 2($v1)
/* C0828 8012A128 00052A00 */  sll       $a1, $a1, 8
/* C082C 8012A12C 0C0B7A76 */  jal       spr_get_npc_raster_info
/* C0830 8012A130 00A22825 */   or       $a1, $a1, $v0
/* C0834 8012A134 104000FA */  beqz      $v0, .L8012A520
/* C0838 8012A138 00000000 */   nop
/* C083C 8012A13C 3C058015 */  lui       $a1, %hi(gMessageDrawStatePtr)
/* C0840 8012A140 8CA55D74 */  lw        $a1, %lo(gMessageDrawStatePtr)($a1)
/* C0844 8012A144 97C6045A */  lhu       $a2, 0x45a($fp)
/* C0848 8012A148 97C8045C */  lhu       $t0, 0x45c($fp)
/* C084C 8012A14C 97B90066 */  lhu       $t9, 0x66($sp)
/* C0850 8012A150 97B80076 */  lhu       $t8, 0x76($sp)
/* C0854 8012A154 94A70046 */  lhu       $a3, 0x46($a1)
/* C0858 8012A158 94A30042 */  lhu       $v1, 0x42($a1)
/* C085C 8012A15C 94A90048 */  lhu       $t1, 0x48($a1)
/* C0860 8012A160 94A40044 */  lhu       $a0, 0x44($a1)
/* C0864 8012A164 00D93021 */  addu      $a2, $a2, $t9
/* C0868 8012A168 AFA00010 */  sw        $zero, 0x10($sp)
/* C086C 8012A16C 8FA20054 */  lw        $v0, 0x54($sp)
/* C0870 8012A170 97B9006E */  lhu       $t9, 0x6e($sp)
/* C0874 8012A174 00E63821 */  addu      $a3, $a3, $a2
/* C0878 8012A178 00671821 */  addu      $v1, $v1, $a3
/* C087C 8012A17C 00781823 */  subu      $v1, $v1, $t8
/* C0880 8012A180 00031C00 */  sll       $v1, $v1, 0x10
/* C0884 8012A184 00031C03 */  sra       $v1, $v1, 0x10
/* C0888 8012A188 01194021 */  addu      $t0, $t0, $t9
/* C088C 8012A18C 01284821 */  addu      $t1, $t1, $t0
/* C0890 8012A190 97B8007E */  lhu       $t8, 0x7e($sp)
/* C0894 8012A194 00892021 */  addu      $a0, $a0, $t1
/* C0898 8012A198 AFA20014 */  sw        $v0, 0x14($sp)
/* C089C 8012A19C AFA30018 */  sw        $v1, 0x18($sp)
/* C08A0 8012A1A0 00982023 */  subu      $a0, $a0, $t8
/* C08A4 8012A1A4 00042400 */  sll       $a0, $a0, 0x10
/* C08A8 8012A1A8 00042403 */  sra       $a0, $a0, 0x10
/* C08AC 8012A1AC AFA4001C */  sw        $a0, 0x1c($sp)
/* C08B0 8012A1B0 94A20002 */  lhu       $v0, 2($a1)
/* C08B4 8012A1B4 AFA20020 */  sw        $v0, 0x20($sp)
/* C08B8 8012A1B8 94A2000A */  lhu       $v0, 0xa($a1)
/* C08BC 8012A1BC AFA20024 */  sw        $v0, 0x24($sp)
/* C08C0 8012A1C0 94A20006 */  lhu       $v0, 6($a1)
/* C08C4 8012A1C4 94A30002 */  lhu       $v1, 2($a1)
/* C08C8 8012A1C8 00431023 */  subu      $v0, $v0, $v1
/* C08CC 8012A1CC 3042FFFF */  andi      $v0, $v0, 0xffff
/* C08D0 8012A1D0 AFA20028 */  sw        $v0, 0x28($sp)
/* C08D4 8012A1D4 94A3000E */  lhu       $v1, 0xe($a1)
/* C08D8 8012A1D8 94A4000A */  lhu       $a0, 0xa($a1)
/* C08DC 8012A1DC 320200FF */  andi      $v0, $s0, 0xff
/* C08E0 8012A1E0 AFA20030 */  sw        $v0, 0x30($sp)
/* C08E4 8012A1E4 00641823 */  subu      $v1, $v1, $a0
/* C08E8 8012A1E8 3063FFFF */  andi      $v1, $v1, 0xffff
/* C08EC 8012A1EC AFA3002C */  sw        $v1, 0x2c($sp)
/* C08F0 8012A1F0 8FA40050 */  lw        $a0, 0x50($sp)
/* C08F4 8012A1F4 8FA50058 */  lw        $a1, 0x58($sp)
/* C08F8 8012A1F8 8FA6005C */  lw        $a2, 0x5c($sp)
/* C08FC 8012A1FC 0C04BA68 */  jal       draw_ci_image_with_clipping
/* C0900 8012A200 24070002 */   addiu    $a3, $zero, 2
/* C0904 8012A204 3C038015 */  lui       $v1, %hi(gMessageDrawStatePtr)
/* C0908 8012A208 8C635D74 */  lw        $v1, %lo(gMessageDrawStatePtr)($v1)
/* C090C 8012A20C 94620034 */  lhu       $v0, 0x34($v1)
/* C0910 8012A210 34420010 */  ori       $v0, $v0, 0x10
/* C0914 8012A214 0804A948 */  j         .L8012A520
/* C0918 8012A218 A4620034 */   sh       $v0, 0x34($v1)
glabel L8012A21C_C091C
/* C091C 8012A21C 3C028015 */  lui       $v0, %hi(D_8015131C)
/* C0920 8012A220 8C42131C */  lw        $v0, %lo(D_8015131C)($v0)
/* C0924 8012A224 10400127 */  beqz      $v0, L8012A6C4_C0DC4
/* C0928 8012A228 00000000 */   nop
/* C092C 8012A22C 97AB008E */  lhu       $t3, 0x8e($sp)
/* C0930 8012A230 000B1400 */  sll       $v0, $t3, 0x10
/* C0934 8012A234 00021C03 */  sra       $v1, $v0, 0x10
/* C0938 8012A238 286200FF */  slti      $v0, $v1, 0xff
/* C093C 8012A23C 1040000A */  beqz      $v0, .L8012A268
/* C0940 8012A240 00000000 */   nop
/* C0944 8012A244 3C018015 */  lui       $at, %hi(D_80150870)
/* C0948 8012A248 D4220870 */  ldc1      $f2, %lo(D_80150870)($at)
/* C094C 8012A24C 44830000 */  mtc1      $v1, $f0
/* C0950 8012A250 00000000 */  nop
/* C0954 8012A254 46800021 */  cvt.d.w   $f0, $f0
/* C0958 8012A258 46220002 */  mul.d     $f0, $f0, $f2
/* C095C 8012A25C 00000000 */  nop
/* C0960 8012A260 4620030D */  trunc.w.d $f12, $f0
/* C0964 8012A264 440B6000 */  mfc1      $t3, $f12
.L8012A268:
/* C0968 8012A268 3C048016 */  lui       $a0, %hi(D_80159B50)
/* C096C 8012A26C 24849B50 */  addiu     $a0, $a0, %lo(D_80159B50)
/* C0970 8012A270 3C088015 */  lui       $t0, %hi(gMessageDrawStatePtr)
/* C0974 8012A274 8D085D74 */  lw        $t0, %lo(gMessageDrawStatePtr)($t0)
/* C0978 8012A278 97C6045A */  lhu       $a2, 0x45a($fp)
/* C097C 8012A27C 97C9045C */  lhu       $t1, 0x45c($fp)
/* C0980 8012A280 97B90066 */  lhu       $t9, 0x66($sp)
/* C0984 8012A284 97B80076 */  lhu       $t8, 0x76($sp)
/* C0988 8012A288 00D93021 */  addu      $a2, $a2, $t9
/* C098C 8012A28C 95070046 */  lhu       $a3, 0x46($t0)
/* C0990 8012A290 95030042 */  lhu       $v1, 0x42($t0)
/* C0994 8012A294 950A0048 */  lhu       $t2, 0x48($t0)
/* C0998 8012A298 95050044 */  lhu       $a1, 0x44($t0)
/* C099C 8012A29C 97B9006E */  lhu       $t9, 0x6e($sp)
/* C09A0 8012A2A0 3C028016 */  lui       $v0, %hi(D_8015C7E0)
/* C09A4 8012A2A4 2442C7E0 */  addiu     $v0, $v0, %lo(D_8015C7E0)
/* C09A8 8012A2A8 AFA00010 */  sw        $zero, 0x10($sp)
/* C09AC 8012A2AC AFA20014 */  sw        $v0, 0x14($sp)
/* C09B0 8012A2B0 00E63821 */  addu      $a3, $a3, $a2
/* C09B4 8012A2B4 00671821 */  addu      $v1, $v1, $a3
/* C09B8 8012A2B8 00781823 */  subu      $v1, $v1, $t8
/* C09BC 8012A2BC 00031C00 */  sll       $v1, $v1, 0x10
/* C09C0 8012A2C0 00031C03 */  sra       $v1, $v1, 0x10
/* C09C4 8012A2C4 01394821 */  addu      $t1, $t1, $t9
/* C09C8 8012A2C8 01495021 */  addu      $t2, $t2, $t1
/* C09CC 8012A2CC 97B8007E */  lhu       $t8, 0x7e($sp)
/* C09D0 8012A2D0 00AA2821 */  addu      $a1, $a1, $t2
/* C09D4 8012A2D4 AFA30018 */  sw        $v1, 0x18($sp)
/* C09D8 8012A2D8 00B82823 */  subu      $a1, $a1, $t8
/* C09DC 8012A2DC 00052C00 */  sll       $a1, $a1, 0x10
/* C09E0 8012A2E0 00052C03 */  sra       $a1, $a1, 0x10
/* C09E4 8012A2E4 AFA5001C */  sw        $a1, 0x1c($sp)
/* C09E8 8012A2E8 95020002 */  lhu       $v0, 2($t0)
/* C09EC 8012A2EC 24070002 */  addiu     $a3, $zero, 2
/* C09F0 8012A2F0 AFA20020 */  sw        $v0, 0x20($sp)
/* C09F4 8012A2F4 9502000A */  lhu       $v0, 0xa($t0)
/* C09F8 8012A2F8 24050020 */  addiu     $a1, $zero, 0x20
/* C09FC 8012A2FC AFA20024 */  sw        $v0, 0x24($sp)
/* C0A00 8012A300 95020006 */  lhu       $v0, 6($t0)
/* C0A04 8012A304 95030002 */  lhu       $v1, 2($t0)
/* C0A08 8012A308 00A0302D */  daddu     $a2, $a1, $zero
/* C0A0C 8012A30C 00431023 */  subu      $v0, $v0, $v1
/* C0A10 8012A310 3042FFFF */  andi      $v0, $v0, 0xffff
/* C0A14 8012A314 AFA20028 */  sw        $v0, 0x28($sp)
/* C0A18 8012A318 9503000E */  lhu       $v1, 0xe($t0)
/* C0A1C 8012A31C 9508000A */  lhu       $t0, 0xa($t0)
/* C0A20 8012A320 316200FF */  andi      $v0, $t3, 0xff
/* C0A24 8012A324 AFA20030 */  sw        $v0, 0x30($sp)
/* C0A28 8012A328 00681823 */  subu      $v1, $v1, $t0
/* C0A2C 8012A32C 3063FFFF */  andi      $v1, $v1, 0xffff
/* C0A30 8012A330 0C04BA68 */  jal       draw_ci_image_with_clipping
/* C0A34 8012A334 AFA3002C */   sw       $v1, 0x2c($sp)
/* C0A38 8012A338 3C038015 */  lui       $v1, %hi(gMessageDrawStatePtr)
/* C0A3C 8012A33C 8C635D74 */  lw        $v1, %lo(gMessageDrawStatePtr)($v1)
/* C0A40 8012A340 94620034 */  lhu       $v0, 0x34($v1)
/* C0A44 8012A344 34420010 */  ori       $v0, $v0, 0x10
/* C0A48 8012A348 0804A9B1 */  j         L8012A6C4_C0DC4
/* C0A4C 8012A34C A4620034 */   sh       $v0, 0x34($v1)
glabel L8012A350_C0A50
/* C0A50 8012A350 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* C0A54 8012A354 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* C0A58 8012A358 8C430020 */  lw        $v1, 0x20($v0)
/* C0A5C 8012A35C 8C42004C */  lw        $v0, 0x4c($v0)
/* C0A60 8012A360 00622821 */  addu      $a1, $v1, $v0
/* C0A64 8012A364 90A70001 */  lbu       $a3, 1($a1)
/* C0A68 8012A368 00071040 */  sll       $v0, $a3, 1
/* C0A6C 8012A36C 03C22021 */  addu      $a0, $fp, $v0
/* C0A70 8012A370 84830474 */  lh        $v1, 0x474($a0)
/* C0A74 8012A374 2402FFFF */  addiu     $v0, $zero, -1
/* C0A78 8012A378 14620003 */  bne       $v1, $v0, .L8012A388
/* C0A7C 8012A37C 00000000 */   nop
/* C0A80 8012A380 90A20003 */  lbu       $v0, 3($a1)
/* C0A84 8012A384 A4820474 */  sh        $v0, 0x474($a0)
.L8012A388:
/* C0A88 8012A388 84820474 */  lh        $v0, 0x474($a0)
/* C0A8C 8012A38C 14400005 */  bnez      $v0, .L8012A3A4
/* C0A90 8012A390 240A0011 */   addiu    $t2, $zero, 0x11
/* C0A94 8012A394 03C71821 */  addu      $v1, $fp, $a3
/* C0A98 8012A398 90620470 */  lbu       $v0, 0x470($v1)
/* C0A9C 8012A39C 24420001 */  addiu     $v0, $v0, 1
/* C0AA0 8012A3A0 A0620470 */  sb        $v0, 0x470($v1)
.L8012A3A4:
/* C0AA4 8012A3A4 03C72821 */  addu      $a1, $fp, $a3
/* C0AA8 8012A3A8 24090012 */  addiu     $t1, $zero, 0x12
/* C0AAC 8012A3AC 0080302D */  daddu     $a2, $a0, $zero
/* C0AB0 8012A3B0 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* C0AB4 8012A3B4 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* C0AB8 8012A3B8 24080013 */  addiu     $t0, $zero, 0x13
.L8012A3BC:
/* C0ABC 8012A3BC 8C440020 */  lw        $a0, 0x20($v0)
.L8012A3C0:
/* C0AC0 8012A3C0 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* C0AC4 8012A3C4 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* C0AC8 8012A3C8 8C42004C */  lw        $v0, 0x4c($v0)
/* C0ACC 8012A3CC 00821821 */  addu      $v1, $a0, $v0
/* C0AD0 8012A3D0 9062FFFF */  lbu       $v0, -1($v1)
/* C0AD4 8012A3D4 241900FF */  addiu     $t9, $zero, 0xff
/* C0AD8 8012A3D8 1459000D */  bne       $v0, $t9, .L8012A410
/* C0ADC 8012A3DC 00000000 */   nop
/* C0AE0 8012A3E0 90620000 */  lbu       $v0, ($v1)
/* C0AE4 8012A3E4 144A000A */  bne       $v0, $t2, .L8012A410
/* C0AE8 8012A3E8 00000000 */   nop
/* C0AEC 8012A3EC 90620001 */  lbu       $v0, 1($v1)
/* C0AF0 8012A3F0 14470007 */  bne       $v0, $a3, .L8012A410
/* C0AF4 8012A3F4 00000000 */   nop
/* C0AF8 8012A3F8 90630002 */  lbu       $v1, 2($v1)
/* C0AFC 8012A3FC 90A20470 */  lbu       $v0, 0x470($a1)
/* C0B00 8012A400 1062002A */  beq       $v1, $v0, .L8012A4AC
/* C0B04 8012A404 00000000 */   nop
/* C0B08 8012A408 0804A929 */  j         .L8012A4A4
/* C0B0C 8012A40C 24840004 */   addiu    $a0, $a0, 4
.L8012A410:
/* C0B10 8012A410 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* C0B14 8012A414 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* C0B18 8012A418 8C42004C */  lw        $v0, 0x4c($v0)
/* C0B1C 8012A41C 00441821 */  addu      $v1, $v0, $a0
/* C0B20 8012A420 90620000 */  lbu       $v0, ($v1)
/* C0B24 8012A424 241800FF */  addiu     $t8, $zero, 0xff
/* C0B28 8012A428 5458FFE5 */  bnel      $v0, $t8, .L8012A3C0
/* C0B2C 8012A42C 24840001 */   addiu    $a0, $a0, 1
/* C0B30 8012A430 90620001 */  lbu       $v0, 1($v1)
/* C0B34 8012A434 1449000D */  bne       $v0, $t1, .L8012A46C
/* C0B38 8012A438 00000000 */   nop
/* C0B3C 8012A43C 90620002 */  lbu       $v0, 2($v1)
/* C0B40 8012A440 1447000A */  bne       $v0, $a3, .L8012A46C
/* C0B44 8012A444 00000000 */   nop
/* C0B48 8012A448 84C20474 */  lh        $v0, 0x474($a2)
/* C0B4C 8012A44C 14400017 */  bnez      $v0, .L8012A4AC
/* C0B50 8012A450 24840001 */   addiu    $a0, $a0, 1
/* C0B54 8012A454 90620003 */  lbu       $v0, 3($v1)
/* C0B58 8012A458 A0A20470 */  sb        $v0, 0x470($a1)
/* C0B5C 8012A45C 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* C0B60 8012A460 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* C0B64 8012A464 0804A8EF */  j         .L8012A3BC
/* C0B68 8012A468 00000000 */   nop
.L8012A46C:
/* C0B6C 8012A46C 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* C0B70 8012A470 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* C0B74 8012A474 8C42004C */  lw        $v0, 0x4c($v0)
/* C0B78 8012A478 00441821 */  addu      $v1, $v0, $a0
/* C0B7C 8012A47C 90620000 */  lbu       $v0, ($v1)
/* C0B80 8012A480 241900FF */  addiu     $t9, $zero, 0xff
/* C0B84 8012A484 5459FFCE */  bnel      $v0, $t9, .L8012A3C0
/* C0B88 8012A488 24840001 */   addiu    $a0, $a0, 1
/* C0B8C 8012A48C 90620001 */  lbu       $v0, 1($v1)
/* C0B90 8012A490 5448FFCB */  bnel      $v0, $t0, .L8012A3C0
/* C0B94 8012A494 24840001 */   addiu    $a0, $a0, 1
/* C0B98 8012A498 90620002 */  lbu       $v0, 2($v1)
/* C0B9C 8012A49C 50470003 */  beql      $v0, $a3, .L8012A4AC
/* C0BA0 8012A4A0 24840001 */   addiu    $a0, $a0, 1
.L8012A4A4:
/* C0BA4 8012A4A4 0804A8F0 */  j         .L8012A3C0
/* C0BA8 8012A4A8 24840001 */   addiu    $a0, $a0, 1
.L8012A4AC:
/* C0BAC 8012A4AC 3C058015 */  lui       $a1, %hi(gMessageDrawStatePtr)
/* C0BB0 8012A4B0 8CA55D74 */  lw        $a1, %lo(gMessageDrawStatePtr)($a1)
/* C0BB4 8012A4B4 8CA2004C */  lw        $v0, 0x4c($a1)
/* C0BB8 8012A4B8 ACA40020 */  sw        $a0, 0x20($a1)
/* C0BBC 8012A4BC 00443021 */  addu      $a2, $v0, $a0
/* C0BC0 8012A4C0 90C30000 */  lbu       $v1, ($a2)
/* C0BC4 8012A4C4 24020012 */  addiu     $v0, $zero, 0x12
/* C0BC8 8012A4C8 1062001B */  beq       $v1, $v0, .L8012A538
/* C0BCC 8012A4CC 28620013 */   slti     $v0, $v1, 0x13
/* C0BD0 8012A4D0 10400005 */  beqz      $v0, .L8012A4E8
/* C0BD4 8012A4D4 24020011 */   addiu    $v0, $zero, 0x11
/* C0BD8 8012A4D8 10620008 */  beq       $v1, $v0, .L8012A4FC
/* C0BDC 8012A4DC 00071040 */   sll      $v0, $a3, 1
/* C0BE0 8012A4E0 0804AFDC */  j         L8012BF70_C2670
/* C0BE4 8012A4E4 00000000 */   nop
.L8012A4E8:
/* C0BE8 8012A4E8 24020013 */  addiu     $v0, $zero, 0x13
/* C0BEC 8012A4EC 10620015 */  beq       $v1, $v0, .L8012A544
/* C0BF0 8012A4F0 24820002 */   addiu    $v0, $a0, 2
/* C0BF4 8012A4F4 0804AFDC */  j         L8012BF70_C2670
/* C0BF8 8012A4F8 00000000 */   nop
.L8012A4FC:
/* C0BFC 8012A4FC 03C21821 */  addu      $v1, $fp, $v0
/* C0C00 8012A500 84620474 */  lh        $v0, 0x474($v1)
/* C0C04 8012A504 14400006 */  bnez      $v0, .L8012A520
/* C0C08 8012A508 00000000 */   nop
/* C0C0C 8012A50C 90C20003 */  lbu       $v0, 3($a2)
/* C0C10 8012A510 10400002 */  beqz      $v0, .L8012A51C
/* C0C14 8012A514 2402FFFE */   addiu    $v0, $zero, -2
/* C0C18 8012A518 90C20003 */  lbu       $v0, 3($a2)
.L8012A51C:
/* C0C1C 8012A51C A4620474 */  sh        $v0, 0x474($v1)
.L8012A520:
/* C0C20 8012A520 3C038015 */  lui       $v1, %hi(gMessageDrawStatePtr)
/* C0C24 8012A524 8C635D74 */  lw        $v1, %lo(gMessageDrawStatePtr)($v1)
/* C0C28 8012A528 8C620020 */  lw        $v0, 0x20($v1)
/* C0C2C 8012A52C 24420004 */  addiu     $v0, $v0, 4
/* C0C30 8012A530 0804AFDC */  j         L8012BF70_C2670
/* C0C34 8012A534 AC620020 */   sw       $v0, 0x20($v1)
.L8012A538:
/* C0C38 8012A538 24820003 */  addiu     $v0, $a0, 3
/* C0C3C 8012A53C 0804AFDC */  j         L8012BF70_C2670
/* C0C40 8012A540 ACA20020 */   sw       $v0, 0x20($a1)
.L8012A544:
/* C0C44 8012A544 0804AFDC */  j         L8012BF70_C2670
/* C0C48 8012A548 ACA20020 */   sw       $v0, 0x20($a1)
glabel L8012A54C_C0C4C
/* C0C4C 8012A54C 3C038015 */  lui       $v1, %hi(gMessageDrawStatePtr)
/* C0C50 8012A550 8C635D74 */  lw        $v1, %lo(gMessageDrawStatePtr)($v1)
/* C0C54 8012A554 8C620020 */  lw        $v0, 0x20($v1)
/* C0C58 8012A558 24420003 */  addiu     $v0, $v0, 3
/* C0C5C 8012A55C 0804AFDC */  j         L8012BF70_C2670
/* C0C60 8012A560 AC620020 */   sw       $v0, 0x20($v1)
glabel L8012A564_C0C64
/* C0C64 8012A564 3C058015 */  lui       $a1, %hi(gMessageDrawStatePtr)
/* C0C68 8012A568 8CA55D74 */  lw        $a1, %lo(gMessageDrawStatePtr)($a1)
/* C0C6C 8012A56C 97B80076 */  lhu       $t8, 0x76($sp)
/* C0C70 8012A570 8CA20020 */  lw        $v0, 0x20($a1)
/* C0C74 8012A574 8CA3004C */  lw        $v1, 0x4c($a1)
/* C0C78 8012A578 94A40042 */  lhu       $a0, 0x42($a1)
/* C0C7C 8012A57C 00431021 */  addu      $v0, $v0, $v1
/* C0C80 8012A580 90430001 */  lbu       $v1, 1($v0)
/* C0C84 8012A584 94A20046 */  lhu       $v0, 0x46($a1)
/* C0C88 8012A588 00031840 */  sll       $v1, $v1, 1
/* C0C8C 8012A58C 03C31821 */  addu      $v1, $fp, $v1
/* C0C90 8012A590 00441021 */  addu      $v0, $v0, $a0
/* C0C94 8012A594 00581023 */  subu      $v0, $v0, $t8
/* C0C98 8012A598 2442FFFA */  addiu     $v0, $v0, -6
/* C0C9C 8012A59C A46204D0 */  sh        $v0, 0x4d0($v1)
/* C0CA0 8012A5A0 8CA20020 */  lw        $v0, 0x20($a1)
/* C0CA4 8012A5A4 8CA3004C */  lw        $v1, 0x4c($a1)
/* C0CA8 8012A5A8 94A40044 */  lhu       $a0, 0x44($a1)
/* C0CAC 8012A5AC 97B9007E */  lhu       $t9, 0x7e($sp)
/* C0CB0 8012A5B0 00431021 */  addu      $v0, $v0, $v1
/* C0CB4 8012A5B4 90430001 */  lbu       $v1, 1($v0)
/* C0CB8 8012A5B8 94A20048 */  lhu       $v0, 0x48($a1)
/* C0CBC 8012A5BC 00031840 */  sll       $v1, $v1, 1
/* C0CC0 8012A5C0 03C31821 */  addu      $v1, $fp, $v1
/* C0CC4 8012A5C4 00441021 */  addu      $v0, $v0, $a0
/* C0CC8 8012A5C8 00591023 */  subu      $v0, $v0, $t9
/* C0CCC 8012A5CC 2442FFFF */  addiu     $v0, $v0, -1
/* C0CD0 8012A5D0 A46204DC */  sh        $v0, 0x4dc($v1)
/* C0CD4 8012A5D4 8CA20020 */  lw        $v0, 0x20($a1)
/* C0CD8 8012A5D8 0804A9E9 */  j         .L8012A7A4
/* C0CDC 8012A5DC 24420002 */   addiu    $v0, $v0, 2
glabel L8012A5E0_C0CE0
/* C0CE0 8012A5E0 3C048015 */  lui       $a0, %hi(gMessageDrawStatePtr)
/* C0CE4 8012A5E4 8C845D74 */  lw        $a0, %lo(gMessageDrawStatePtr)($a0)
/* C0CE8 8012A5E8 8C820020 */  lw        $v0, 0x20($a0)
/* C0CEC 8012A5EC 8C83004C */  lw        $v1, 0x4c($a0)
/* C0CF0 8012A5F0 00431021 */  addu      $v0, $v0, $v1
/* C0CF4 8012A5F4 90420001 */  lbu       $v0, 1($v0)
/* C0CF8 8012A5F8 241800FF */  addiu     $t8, $zero, 0xff
/* C0CFC 8012A5FC 54580004 */  bnel      $v0, $t8, .L8012A610
/* C0D00 8012A600 A082002D */   sb       $v0, 0x2d($a0)
/* C0D04 8012A604 94820034 */  lhu       $v0, 0x34($a0)
/* C0D08 8012A608 0804AAD0 */  j         .L8012AB40
/* C0D0C 8012A60C 3042FFDF */   andi     $v0, $v0, 0xffdf
.L8012A610:
/* C0D10 8012A610 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* C0D14 8012A614 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* C0D18 8012A618 94430034 */  lhu       $v1, 0x34($v0)
/* C0D1C 8012A61C 94440042 */  lhu       $a0, 0x42($v0)
/* C0D20 8012A620 34630020 */  ori       $v1, $v1, 0x20
/* C0D24 8012A624 2484000E */  addiu     $a0, $a0, 0xe
/* C0D28 8012A628 A4430034 */  sh        $v1, 0x34($v0)
/* C0D2C 8012A62C 0804AAD1 */  j         L8012AB44_C1244
/* C0D30 8012A630 A4440042 */   sh       $a0, 0x42($v0)
glabel L8012A634_C0D34
/* C0D34 8012A634 3C048015 */  lui       $a0, %hi(gMessageDrawStatePtr)
/* C0D38 8012A638 8C845D74 */  lw        $a0, %lo(gMessageDrawStatePtr)($a0)
/* C0D3C 8012A63C 8C820020 */  lw        $v0, 0x20($a0)
/* C0D40 8012A640 8C83004C */  lw        $v1, 0x4c($a0)
/* C0D44 8012A644 00431021 */  addu      $v0, $v0, $v1
/* C0D48 8012A648 90420001 */  lbu       $v0, 1($v0)
/* C0D4C 8012A64C 0804AAD1 */  j         L8012AB44_C1244
/* C0D50 8012A650 A082002B */   sb       $v0, 0x2b($a0)
glabel L8012A654_C0D54
/* C0D54 8012A654 0C04B0B8 */  jal       msg_reset_gfx_state
/* C0D58 8012A658 00000000 */   nop
/* C0D5C 8012A65C 0804A9B1 */  j         L8012A6C4_C0DC4
/* C0D60 8012A660 00000000 */   nop
glabel L8012A664_C0D64
/* C0D64 8012A664 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* C0D68 8012A668 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* C0D6C 8012A66C 94440042 */  lhu       $a0, 0x42($v0)
/* C0D70 8012A670 8C430020 */  lw        $v1, 0x20($v0)
/* C0D74 8012A674 94450044 */  lhu       $a1, 0x44($v0)
/* C0D78 8012A678 24630001 */  addiu     $v1, $v1, 1
/* C0D7C 8012A67C A4440024 */  sh        $a0, 0x24($v0)
/* C0D80 8012A680 A4450026 */  sh        $a1, 0x26($v0)
/* C0D84 8012A684 0804AFDC */  j         L8012BF70_C2670
/* C0D88 8012A688 AC430020 */   sw       $v1, 0x20($v0)
glabel L8012A68C_C0D8C
/* C0D8C 8012A68C 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* C0D90 8012A690 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* C0D94 8012A694 94440024 */  lhu       $a0, 0x24($v0)
/* C0D98 8012A698 8C430020 */  lw        $v1, 0x20($v0)
/* C0D9C 8012A69C 94450026 */  lhu       $a1, 0x26($v0)
/* C0DA0 8012A6A0 24630001 */  addiu     $v1, $v1, 1
/* C0DA4 8012A6A4 A4440042 */  sh        $a0, 0x42($v0)
/* C0DA8 8012A6A8 A4450044 */  sh        $a1, 0x44($v0)
/* C0DAC 8012A6AC 0804AFDC */  j         L8012BF70_C2670
/* C0DB0 8012A6B0 AC430020 */   sw       $v1, 0x20($v0)
glabel L8012A6B4_C0DB4
/* C0DB4 8012A6B4 3C038015 */  lui       $v1, %hi(gMessageDrawStatePtr)
/* C0DB8 8012A6B8 8C635D74 */  lw        $v1, %lo(gMessageDrawStatePtr)($v1)
/* C0DBC 8012A6BC 9062004B */  lbu       $v0, 0x4b($v1)
/* C0DC0 8012A6C0 A0620028 */  sb        $v0, 0x28($v1)
glabel L8012A6C4_C0DC4
/* C0DC4 8012A6C4 3C038015 */  lui       $v1, %hi(gMessageDrawStatePtr)
/* C0DC8 8012A6C8 8C635D74 */  lw        $v1, %lo(gMessageDrawStatePtr)($v1)
/* C0DCC 8012A6CC 8C620020 */  lw        $v0, 0x20($v1)
/* C0DD0 8012A6D0 24420001 */  addiu     $v0, $v0, 1
/* C0DD4 8012A6D4 0804AFDC */  j         L8012BF70_C2670
/* C0DD8 8012A6D8 AC620020 */   sw       $v0, 0x20($v1)
glabel L8012A6DC_C0DDC
/* C0DDC 8012A6DC 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* C0DE0 8012A6E0 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* C0DE4 8012A6E4 8C430020 */  lw        $v1, 0x20($v0)
/* C0DE8 8012A6E8 90440028 */  lbu       $a0, 0x28($v0)
/* C0DEC 8012A6EC 24630001 */  addiu     $v1, $v1, 1
/* C0DF0 8012A6F0 A444004A */  sh        $a0, 0x4a($v0)
/* C0DF4 8012A6F4 0804AFDC */  j         L8012BF70_C2670
/* C0DF8 8012A6F8 AC430020 */   sw       $v1, 0x20($v0)
glabel L8012A6FC_C0DFC
/* C0DFC 8012A6FC 3C038015 */  lui       $v1, %hi(gMessageDrawStatePtr)
/* C0E00 8012A700 8C635D74 */  lw        $v1, %lo(gMessageDrawStatePtr)($v1)
/* C0E04 8012A704 8C620020 */  lw        $v0, 0x20($v1)
/* C0E08 8012A708 8C63004C */  lw        $v1, 0x4c($v1)
/* C0E0C 8012A70C 00431021 */  addu      $v0, $v0, $v1
/* C0E10 8012A710 90430001 */  lbu       $v1, 1($v0)
/* C0E14 8012A714 2C62000F */  sltiu     $v0, $v1, 0xf
/* C0E18 8012A718 10400615 */  beqz      $v0, L8012BF70_C2670
/* C0E1C 8012A71C 00031080 */   sll      $v0, $v1, 2
/* C0E20 8012A720 3C018015 */  lui       $at, %hi(jtbl_80150878)
/* C0E24 8012A724 00220821 */  addu      $at, $at, $v0
/* C0E28 8012A728 8C220878 */  lw        $v0, %lo(jtbl_80150878)($at)
/* C0E2C 8012A72C 00400008 */  jr        $v0
/* C0E30 8012A730 00000000 */   nop
glabel L8012A734_C0E34
/* C0E34 8012A734 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* C0E38 8012A738 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* C0E3C 8012A73C 8C430038 */  lw        $v1, 0x38($v0)
/* C0E40 8012A740 8C440020 */  lw        $a0, 0x20($v0)
/* C0E44 8012A744 0804AA54 */  j         .L8012A950
/* C0E48 8012A748 34630001 */   ori      $v1, $v1, 1
glabel L8012A74C_C0E4C
/* C0E4C 8012A74C 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* C0E50 8012A750 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* C0E54 8012A754 8C430038 */  lw        $v1, 0x38($v0)
/* C0E58 8012A758 8C440020 */  lw        $a0, 0x20($v0)
/* C0E5C 8012A75C 0804AA54 */  j         .L8012A950
/* C0E60 8012A760 34630002 */   ori      $v1, $v1, 2
glabel L8012A764_C0E64
/* C0E64 8012A764 3C06FC70 */  lui       $a2, 0xfc70
/* C0E68 8012A768 34C6FEE1 */  ori       $a2, $a2, 0xfee1
/* C0E6C 8012A76C 3C058015 */  lui       $a1, %hi(gMessageDrawStatePtr)
/* C0E70 8012A770 8CA55D74 */  lw        $a1, %lo(gMessageDrawStatePtr)($a1)
/* C0E74 8012A774 8EE40000 */  lw        $a0, ($s7)
/* C0E78 8012A778 8CA20038 */  lw        $v0, 0x38($a1)
/* C0E7C 8012A77C 0080182D */  daddu     $v1, $a0, $zero
/* C0E80 8012A780 34420004 */  ori       $v0, $v0, 4
/* C0E84 8012A784 ACA20038 */  sw        $v0, 0x38($a1)
/* C0E88 8012A788 2402F3F9 */  addiu     $v0, $zero, -0xc07
/* C0E8C 8012A78C AC660000 */  sw        $a2, ($v1)
/* C0E90 8012A790 AC620004 */  sw        $v0, 4($v1)
/* C0E94 8012A794 8CA20020 */  lw        $v0, 0x20($a1)
/* C0E98 8012A798 24840008 */  addiu     $a0, $a0, 8
/* C0E9C 8012A79C AEE40000 */  sw        $a0, ($s7)
/* C0EA0 8012A7A0 24420002 */  addiu     $v0, $v0, 2
.L8012A7A4:
/* C0EA4 8012A7A4 0804AFDC */  j         L8012BF70_C2670
/* C0EA8 8012A7A8 ACA20020 */   sw       $v0, 0x20($a1)
glabel L8012A7AC_C0EAC
/* C0EAC 8012A7AC 3C09FC72 */  lui       $t1, 0xfc72
/* C0EB0 8012A7B0 3529FEE5 */  ori       $t1, $t1, 0xfee5
/* C0EB4 8012A7B4 3C0811FC */  lui       $t0, 0x11fc
/* C0EB8 8012A7B8 3C030001 */  lui       $v1, 1
/* C0EBC 8012A7BC 3C068015 */  lui       $a2, %hi(gMessageDrawStatePtr)
/* C0EC0 8012A7C0 8CC65D74 */  lw        $a2, %lo(gMessageDrawStatePtr)($a2)
/* C0EC4 8012A7C4 8EE50000 */  lw        $a1, ($s7)
/* C0EC8 8012A7C8 8CC20038 */  lw        $v0, 0x38($a2)
/* C0ECC 8012A7CC 00A0382D */  daddu     $a3, $a1, $zero
/* C0ED0 8012A7D0 00431025 */  or        $v0, $v0, $v1
/* C0ED4 8012A7D4 ACC20038 */  sw        $v0, 0x38($a2)
/* C0ED8 8012A7D8 3C02FB00 */  lui       $v0, 0xfb00
/* C0EDC 8012A7DC ACE20000 */  sw        $v0, ($a3)
/* C0EE0 8012A7E0 8CC20020 */  lw        $v0, 0x20($a2)
/* C0EE4 8012A7E4 8CC3004C */  lw        $v1, 0x4c($a2)
/* C0EE8 8012A7E8 24A50008 */  addiu     $a1, $a1, 8
/* C0EEC 8012A7EC AEE50000 */  sw        $a1, ($s7)
/* C0EF0 8012A7F0 00431021 */  addu      $v0, $v0, $v1
/* C0EF4 8012A7F4 90440002 */  lbu       $a0, 2($v0)
/* C0EF8 8012A7F8 3508F279 */  ori       $t0, $t0, 0xf279
/* C0EFC 8012A7FC 00041E00 */  sll       $v1, $a0, 0x18
/* C0F00 8012A800 00041400 */  sll       $v0, $a0, 0x10
/* C0F04 8012A804 00621825 */  or        $v1, $v1, $v0
/* C0F08 8012A808 00042200 */  sll       $a0, $a0, 8
/* C0F0C 8012A80C 00641825 */  or        $v1, $v1, $a0
/* C0F10 8012A810 ACE30004 */  sw        $v1, 4($a3)
/* C0F14 8012A814 ACA90000 */  sw        $t1, ($a1)
/* C0F18 8012A818 ACA80004 */  sw        $t0, 4($a1)
/* C0F1C 8012A81C 8CC20020 */  lw        $v0, 0x20($a2)
/* C0F20 8012A820 24A50008 */  addiu     $a1, $a1, 8
/* C0F24 8012A824 AEE50000 */  sw        $a1, ($s7)
/* C0F28 8012A828 24420003 */  addiu     $v0, $v0, 3
/* C0F2C 8012A82C 0804AFDC */  j         L8012BF70_C2670
/* C0F30 8012A830 ACC20020 */   sw       $v0, 0x20($a2)
glabel L8012A834_C0F34
/* C0F34 8012A834 3C058015 */  lui       $a1, %hi(gMessageDrawStatePtr)
/* C0F38 8012A838 8CA55D74 */  lw        $a1, %lo(gMessageDrawStatePtr)($a1)
/* C0F3C 8012A83C 8CA20038 */  lw        $v0, 0x38($a1)
/* C0F40 8012A840 8CA40020 */  lw        $a0, 0x20($a1)
/* C0F44 8012A844 8CA3004C */  lw        $v1, 0x4c($a1)
/* C0F48 8012A848 34420020 */  ori       $v0, $v0, 0x20
/* C0F4C 8012A84C 00831821 */  addu      $v1, $a0, $v1
/* C0F50 8012A850 ACA20038 */  sw        $v0, 0x38($a1)
/* C0F54 8012A854 90630002 */  lbu       $v1, 2($v1)
/* C0F58 8012A858 24840003 */  addiu     $a0, $a0, 3
/* C0F5C 8012A85C 0804AFDB */  j         .L8012BF6C
/* C0F60 8012A860 A3A300B8 */   sb       $v1, 0xb8($sp)
glabel L8012A864_C0F64
/* C0F64 8012A864 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* C0F68 8012A868 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* C0F6C 8012A86C 8C430038 */  lw        $v1, 0x38($v0)
/* C0F70 8012A870 8C440020 */  lw        $a0, 0x20($v0)
/* C0F74 8012A874 0804AA54 */  j         .L8012A950
/* C0F78 8012A878 34630040 */   ori      $v1, $v1, 0x40
glabel L8012A87C_C0F7C
/* C0F7C 8012A87C 3C058015 */  lui       $a1, %hi(gMessageDrawStatePtr)
/* C0F80 8012A880 8CA55D74 */  lw        $a1, %lo(gMessageDrawStatePtr)($a1)
/* C0F84 8012A884 8CA20038 */  lw        $v0, 0x38($a1)
/* C0F88 8012A888 8CA40020 */  lw        $a0, 0x20($a1)
/* C0F8C 8012A88C 8CA3004C */  lw        $v1, 0x4c($a1)
/* C0F90 8012A890 34420080 */  ori       $v0, $v0, 0x80
/* C0F94 8012A894 00831821 */  addu      $v1, $a0, $v1
/* C0F98 8012A898 ACA20038 */  sw        $v0, 0x38($a1)
/* C0F9C 8012A89C 90630002 */  lbu       $v1, 2($v1)
/* C0FA0 8012A8A0 24840003 */  addiu     $a0, $a0, 3
/* C0FA4 8012A8A4 0804AFDB */  j         .L8012BF6C
/* C0FA8 8012A8A8 A7A300B6 */   sh       $v1, 0xb6($sp)
glabel L8012A8AC_C0FAC
/* C0FAC 8012A8AC 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* C0FB0 8012A8B0 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* C0FB4 8012A8B4 8C430038 */  lw        $v1, 0x38($v0)
/* C0FB8 8012A8B8 8C440020 */  lw        $a0, 0x20($v0)
/* C0FBC 8012A8BC 0804AA54 */  j         .L8012A950
/* C0FC0 8012A8C0 34630200 */   ori      $v1, $v1, 0x200
glabel L8012A8C4_C0FC4
/* C0FC4 8012A8C4 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* C0FC8 8012A8C8 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* C0FCC 8012A8CC 8C430038 */  lw        $v1, 0x38($v0)
/* C0FD0 8012A8D0 8C440020 */  lw        $a0, 0x20($v0)
/* C0FD4 8012A8D4 0804AA54 */  j         .L8012A950
/* C0FD8 8012A8D8 34630400 */   ori      $v1, $v1, 0x400
glabel L8012A8DC_C0FDC
/* C0FDC 8012A8DC 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* C0FE0 8012A8E0 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* C0FE4 8012A8E4 8C430038 */  lw        $v1, 0x38($v0)
/* C0FE8 8012A8E8 8C440020 */  lw        $a0, 0x20($v0)
/* C0FEC 8012A8EC 0804AA54 */  j         .L8012A950
/* C0FF0 8012A8F0 34630800 */   ori      $v1, $v1, 0x800
glabel L8012A8F4_C0FF4
/* C0FF4 8012A8F4 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* C0FF8 8012A8F8 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* C0FFC 8012A8FC 8C430038 */  lw        $v1, 0x38($v0)
/* C1000 8012A900 8C440020 */  lw        $a0, 0x20($v0)
/* C1004 8012A904 0804AA54 */  j         .L8012A950
/* C1008 8012A908 34631000 */   ori      $v1, $v1, 0x1000
glabel L8012A90C_C100C
/* C100C 8012A90C 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* C1010 8012A910 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* C1014 8012A914 8C430038 */  lw        $v1, 0x38($v0)
/* C1018 8012A918 8C440020 */  lw        $a0, 0x20($v0)
/* C101C 8012A91C 0804AA54 */  j         .L8012A950
/* C1020 8012A920 34632000 */   ori      $v1, $v1, 0x2000
glabel L8012A924_C1024
/* C1024 8012A924 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* C1028 8012A928 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* C102C 8012A92C 8C430038 */  lw        $v1, 0x38($v0)
/* C1030 8012A930 8C440020 */  lw        $a0, 0x20($v0)
/* C1034 8012A934 0804AA54 */  j         .L8012A950
/* C1038 8012A938 34634000 */   ori      $v1, $v1, 0x4000
glabel L8012A93C_C103C
/* C103C 8012A93C 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* C1040 8012A940 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* C1044 8012A944 8C430038 */  lw        $v1, 0x38($v0)
/* C1048 8012A948 8C440020 */  lw        $a0, 0x20($v0)
/* C104C 8012A94C 34638000 */  ori       $v1, $v1, 0x8000
.L8012A950:
/* C1050 8012A950 24840002 */  addiu     $a0, $a0, 2
/* C1054 8012A954 AC430038 */  sw        $v1, 0x38($v0)
/* C1058 8012A958 0804AFDC */  j         L8012BF70_C2670
/* C105C 8012A95C AC440020 */   sw       $a0, 0x20($v0)
glabel L8012A960_C1060
/* C1060 8012A960 3C038015 */  lui       $v1, %hi(gMessageDrawStatePtr)
/* C1064 8012A964 8C635D74 */  lw        $v1, %lo(gMessageDrawStatePtr)($v1)
/* C1068 8012A968 8C620020 */  lw        $v0, 0x20($v1)
/* C106C 8012A96C 8C63004C */  lw        $v1, 0x4c($v1)
/* C1070 8012A970 00431021 */  addu      $v0, $v0, $v1
/* C1074 8012A974 90430001 */  lbu       $v1, 1($v0)
/* C1078 8012A978 2C62000F */  sltiu     $v0, $v1, 0xf
/* C107C 8012A97C 10400071 */  beqz      $v0, L8012AB44_C1244
/* C1080 8012A980 00031080 */   sll      $v0, $v1, 2
/* C1084 8012A984 3C018015 */  lui       $at, %hi(jtbl_801508B8)
/* C1088 8012A988 00220821 */  addu      $at, $at, $v0
/* C108C 8012A98C 8C2208B8 */  lw        $v0, %lo(jtbl_801508B8)($at)
/* C1090 8012A990 00400008 */  jr        $v0
/* C1094 8012A994 00000000 */   nop
glabel L8012A998_C1098
/* C1098 8012A998 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* C109C 8012A99C 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* C10A0 8012A9A0 8C430038 */  lw        $v1, 0x38($v0)
/* C10A4 8012A9A4 0804AAAB */  j         .L8012AAAC
/* C10A8 8012A9A8 2404FFFE */   addiu    $a0, $zero, -2
glabel L8012A9AC_C10AC
/* C10AC 8012A9AC 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* C10B0 8012A9B0 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* C10B4 8012A9B4 8C430038 */  lw        $v1, 0x38($v0)
/* C10B8 8012A9B8 0804AAAB */  j         .L8012AAAC
/* C10BC 8012A9BC 2404FFFD */   addiu    $a0, $zero, -3
glabel L8012A9C0_C10C0
/* C10C0 8012A9C0 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* C10C4 8012A9C4 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* C10C8 8012A9C8 8C430038 */  lw        $v1, 0x38($v0)
/* C10CC 8012A9CC 0804AAAB */  j         .L8012AAAC
/* C10D0 8012A9D0 2404FFFB */   addiu    $a0, $zero, -5
glabel L8012A9D4_C10D4
/* C10D4 8012A9D4 3C048015 */  lui       $a0, %hi(gMessageDrawStatePtr)
/* C10D8 8012A9D8 8C845D74 */  lw        $a0, %lo(gMessageDrawStatePtr)($a0)
/* C10DC 8012A9DC 3C03FFFE */  lui       $v1, 0xfffe
/* C10E0 8012A9E0 8C820038 */  lw        $v0, 0x38($a0)
/* C10E4 8012A9E4 0804AAB3 */  j         .L8012AACC
/* C10E8 8012A9E8 3463FFFF */   ori      $v1, $v1, 0xffff
glabel L8012A9EC_C10EC
/* C10EC 8012A9EC 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* C10F0 8012A9F0 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* C10F4 8012A9F4 8C430038 */  lw        $v1, 0x38($v0)
/* C10F8 8012A9F8 0804AAAB */  j         .L8012AAAC
/* C10FC 8012A9FC 2404FFDF */   addiu    $a0, $zero, -0x21
glabel L8012AA00_C1100
/* C1100 8012AA00 3C048015 */  lui       $a0, %hi(gMessageDrawStatePtr)
/* C1104 8012AA04 8C845D74 */  lw        $a0, %lo(gMessageDrawStatePtr)($a0)
/* C1108 8012AA08 0804AA91 */  j         .L8012AA44
/* C110C 8012AA0C 2405FFBF */   addiu    $a1, $zero, -0x41
glabel L8012AA10_C1110
/* C1110 8012AA10 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* C1114 8012AA14 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* C1118 8012AA18 8C430038 */  lw        $v1, 0x38($v0)
/* C111C 8012AA1C 0804AAAB */  j         .L8012AAAC
/* C1120 8012AA20 2404FF7F */   addiu    $a0, $zero, -0x81
glabel L8012AA24_C1124
/* C1124 8012AA24 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* C1128 8012AA28 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* C112C 8012AA2C 8C430038 */  lw        $v1, 0x38($v0)
/* C1130 8012AA30 0804AAAB */  j         .L8012AAAC
/* C1134 8012AA34 2404FDFF */   addiu    $a0, $zero, -0x201
glabel L8012AA38_C1138
/* C1138 8012AA38 3C048015 */  lui       $a0, %hi(gMessageDrawStatePtr)
/* C113C 8012AA3C 8C845D74 */  lw        $a0, %lo(gMessageDrawStatePtr)($a0)
/* C1140 8012AA40 2405FBFF */  addiu     $a1, $zero, -0x401
.L8012AA44:
/* C1144 8012AA44 8C820038 */  lw        $v0, 0x38($a0)
/* C1148 8012AA48 94830034 */  lhu       $v1, 0x34($a0)
/* C114C 8012AA4C 00451024 */  and       $v0, $v0, $a1
/* C1150 8012AA50 34630010 */  ori       $v1, $v1, 0x10
/* C1154 8012AA54 AC820038 */  sw        $v0, 0x38($a0)
/* C1158 8012AA58 0804AAD1 */  j         L8012AB44_C1244
/* C115C 8012AA5C A4830034 */   sh       $v1, 0x34($a0)
glabel L8012AA60_C1160
/* C1160 8012AA60 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* C1164 8012AA64 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* C1168 8012AA68 8C430038 */  lw        $v1, 0x38($v0)
/* C116C 8012AA6C 0804AAAB */  j         .L8012AAAC
/* C1170 8012AA70 2404F7FF */   addiu    $a0, $zero, -0x801
glabel L8012AA74_C1174
/* C1174 8012AA74 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* C1178 8012AA78 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* C117C 8012AA7C 8C430038 */  lw        $v1, 0x38($v0)
/* C1180 8012AA80 0804AAAB */  j         .L8012AAAC
/* C1184 8012AA84 2404EFFF */   addiu    $a0, $zero, -0x1001
glabel L8012AA88_C1188
/* C1188 8012AA88 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* C118C 8012AA8C 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* C1190 8012AA90 8C430038 */  lw        $v1, 0x38($v0)
/* C1194 8012AA94 0804AAAB */  j         .L8012AAAC
/* C1198 8012AA98 2404DFFF */   addiu    $a0, $zero, -0x2001
glabel L8012AA9C_C119C
/* C119C 8012AA9C 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* C11A0 8012AAA0 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* C11A4 8012AAA4 8C430038 */  lw        $v1, 0x38($v0)
/* C11A8 8012AAA8 2404BFFF */  addiu     $a0, $zero, -0x4001
.L8012AAAC:
/* C11AC 8012AAAC 00641824 */  and       $v1, $v1, $a0
/* C11B0 8012AAB0 0804AAD1 */  j         L8012AB44_C1244
/* C11B4 8012AAB4 AC430038 */   sw       $v1, 0x38($v0)
glabel L8012AAB8_C11B8
/* C11B8 8012AAB8 3C048015 */  lui       $a0, %hi(gMessageDrawStatePtr)
/* C11BC 8012AABC 8C845D74 */  lw        $a0, %lo(gMessageDrawStatePtr)($a0)
/* C11C0 8012AAC0 3C03FFFF */  lui       $v1, 0xffff
/* C11C4 8012AAC4 8C820038 */  lw        $v0, 0x38($a0)
/* C11C8 8012AAC8 34637FFF */  ori       $v1, $v1, 0x7fff
.L8012AACC:
/* C11CC 8012AACC 00431024 */  and       $v0, $v0, $v1
/* C11D0 8012AAD0 0804AAD1 */  j         L8012AB44_C1244
/* C11D4 8012AAD4 AC820038 */   sw       $v0, 0x38($a0)
glabel L8012AAD8_C11D8
/* C11D8 8012AAD8 3C048015 */  lui       $a0, %hi(gMessageDrawStatePtr)
/* C11DC 8012AADC 8C845D74 */  lw        $a0, %lo(gMessageDrawStatePtr)($a0)
/* C11E0 8012AAE0 8C820020 */  lw        $v0, 0x20($a0)
/* C11E4 8012AAE4 8C83004C */  lw        $v1, 0x4c($a0)
/* C11E8 8012AAE8 00431021 */  addu      $v0, $v0, $v1
/* C11EC 8012AAEC 90420001 */  lbu       $v0, 1($v0)
/* C11F0 8012AAF0 10400010 */  beqz      $v0, .L8012AB34
/* C11F4 8012AAF4 241900FF */   addiu    $t9, $zero, 0xff
/* C11F8 8012AAF8 A082002E */  sb        $v0, 0x2e($a0)
/* C11FC 8012AAFC 3C038015 */  lui       $v1, %hi(gMessageDrawStatePtr)
/* C1200 8012AB00 8C635D74 */  lw        $v1, %lo(gMessageDrawStatePtr)($v1)
/* C1204 8012AB04 9062002E */  lbu       $v0, 0x2e($v1)
/* C1208 8012AB08 14590006 */  bne       $v0, $t9, .L8012AB24
/* C120C 8012AB0C 00000000 */   nop
/* C1210 8012AB10 97C20514 */  lhu       $v0, 0x514($fp)
/* C1214 8012AB14 00021042 */  srl       $v0, $v0, 1
/* C1218 8012AB18 A062002E */  sb        $v0, 0x2e($v1)
/* C121C 8012AB1C 3C038015 */  lui       $v1, %hi(gMessageDrawStatePtr)
/* C1220 8012AB20 8C635D74 */  lw        $v1, %lo(gMessageDrawStatePtr)($v1)
.L8012AB24:
/* C1224 8012AB24 94620034 */  lhu       $v0, 0x34($v1)
/* C1228 8012AB28 344200C0 */  ori       $v0, $v0, 0xc0
/* C122C 8012AB2C 0804AAD1 */  j         L8012AB44_C1244
/* C1230 8012AB30 A4620034 */   sh       $v0, 0x34($v1)
.L8012AB34:
/* C1234 8012AB34 94820034 */  lhu       $v0, 0x34($a0)
/* C1238 8012AB38 A4800042 */  sh        $zero, 0x42($a0)
/* C123C 8012AB3C 3042FF3F */  andi      $v0, $v0, 0xff3f
.L8012AB40:
/* C1240 8012AB40 A4820034 */  sh        $v0, 0x34($a0)
glabel L8012AB44_C1244
/* C1244 8012AB44 3C038015 */  lui       $v1, %hi(gMessageDrawStatePtr)
/* C1248 8012AB48 8C635D74 */  lw        $v1, %lo(gMessageDrawStatePtr)($v1)
/* C124C 8012AB4C 8C620020 */  lw        $v0, 0x20($v1)
.L8012AB50:
/* C1250 8012AB50 24420002 */  addiu     $v0, $v0, 2
/* C1254 8012AB54 0804AFDC */  j         L8012BF70_C2670
/* C1258 8012AB58 AC620020 */   sw       $v0, 0x20($v1)
glabel L8012AB5C_C125C
/* C125C 8012AB5C 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* C1260 8012AB60 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* C1264 8012AB64 94420034 */  lhu       $v0, 0x34($v0)
/* C1268 8012AB68 30420002 */  andi      $v0, $v0, 2
/* C126C 8012AB6C 10400010 */  beqz      $v0, .L8012ABB0
/* C1270 8012AB70 241800FF */   addiu    $t8, $zero, 0xff
/* C1274 8012AB74 8EE30000 */  lw        $v1, ($s7)
/* C1278 8012AB78 A7B80096 */  sh        $t8, 0x96($sp)
/* C127C 8012AB7C 0060102D */  daddu     $v0, $v1, $zero
/* C1280 8012AB80 24630008 */  addiu     $v1, $v1, 8
/* C1284 8012AB84 3C19E700 */  lui       $t9, 0xe700
/* C1288 8012AB88 AEE30000 */  sw        $v1, ($s7)
/* C128C 8012AB8C AC590000 */  sw        $t9, ($v0)
/* C1290 8012AB90 AC400004 */  sw        $zero, 4($v0)
/* C1294 8012AB94 24620008 */  addiu     $v0, $v1, 8
/* C1298 8012AB98 AEE20000 */  sw        $v0, ($s7)
/* C129C 8012AB9C 3C02DE00 */  lui       $v0, 0xde00
/* C12A0 8012ABA0 AC620000 */  sw        $v0, ($v1)
/* C12A4 8012ABA4 3C028015 */  lui       $v0, %hi(D_8014C500)
/* C12A8 8012ABA8 2442C500 */  addiu     $v0, $v0, %lo(D_8014C500)
/* C12AC 8012ABAC AC620004 */  sw        $v0, 4($v1)
.L8012ABB0:
/* C12B0 8012ABB0 3C058015 */  lui       $a1, %hi(gMessageDrawStatePtr)
/* C12B4 8012ABB4 8CA55D74 */  lw        $a1, %lo(gMessageDrawStatePtr)($a1)
/* C12B8 8012ABB8 C4A00010 */  lwc1      $f0, 0x10($a1)
/* C12BC 8012ABBC 94A20034 */  lhu       $v0, 0x34($a1)
/* C12C0 8012ABC0 C4A20014 */  lwc1      $f2, 0x14($a1)
/* C12C4 8012ABC4 30420080 */  andi      $v0, $v0, 0x80
/* C12C8 8012ABC8 E4A00018 */  swc1      $f0, 0x18($a1)
/* C12CC 8012ABCC 1040000B */  beqz      $v0, .L8012ABFC
/* C12D0 8012ABD0 E4A2001C */   swc1     $f2, 0x1c($a1)
/* C12D4 8012ABD4 97C20538 */  lhu       $v0, 0x538($fp)
/* C12D8 8012ABD8 90A4002E */  lbu       $a0, 0x2e($a1)
/* C12DC 8012ABDC 94A30034 */  lhu       $v1, 0x34($a1)
/* C12E0 8012ABE0 00021042 */  srl       $v0, $v0, 1
/* C12E4 8012ABE4 00822023 */  subu      $a0, $a0, $v0
/* C12E8 8012ABE8 94A20042 */  lhu       $v0, 0x42($a1)
/* C12EC 8012ABEC 3063FF7F */  andi      $v1, $v1, 0xff7f
/* C12F0 8012ABF0 A4A30034 */  sh        $v1, 0x34($a1)
/* C12F4 8012ABF4 00441021 */  addu      $v0, $v0, $a0
/* C12F8 8012ABF8 A4A20042 */  sh        $v0, 0x42($a1)
.L8012ABFC:
/* C12FC 8012ABFC 3C048015 */  lui       $a0, %hi(gMessageDrawStatePtr)
/* C1300 8012AC00 8C845D74 */  lw        $a0, %lo(gMessageDrawStatePtr)($a0)
/* C1304 8012AC04 94820034 */  lhu       $v0, 0x34($a0)
/* C1308 8012AC08 30420040 */  andi      $v0, $v0, 0x40
/* C130C 8012AC0C 10400007 */  beqz      $v0, .L8012AC2C
/* C1310 8012AC10 00000000 */   nop
/* C1314 8012AC14 97C2045A */  lhu       $v0, 0x45a($fp)
/* C1318 8012AC18 97B80066 */  lhu       $t8, 0x66($sp)
/* C131C 8012AC1C 94830042 */  lhu       $v1, 0x42($a0)
/* C1320 8012AC20 00581021 */  addu      $v0, $v0, $t8
/* C1324 8012AC24 0804AB12 */  j         .L8012AC48
/* C1328 8012AC28 00628821 */   addu     $s1, $v1, $v0
.L8012AC2C:
/* C132C 8012AC2C 97C2045A */  lhu       $v0, 0x45a($fp)
/* C1330 8012AC30 97B90066 */  lhu       $t9, 0x66($sp)
/* C1334 8012AC34 94830046 */  lhu       $v1, 0x46($a0)
/* C1338 8012AC38 94840042 */  lhu       $a0, 0x42($a0)
/* C133C 8012AC3C 00591021 */  addu      $v0, $v0, $t9
/* C1340 8012AC40 00621821 */  addu      $v1, $v1, $v0
/* C1344 8012AC44 00838821 */  addu      $s1, $a0, $v1
.L8012AC48:
/* C1348 8012AC48 3C068015 */  lui       $a2, %hi(gMessageDrawStatePtr)
/* C134C 8012AC4C 8CC65D74 */  lw        $a2, %lo(gMessageDrawStatePtr)($a2)
/* C1350 8012AC50 97B8006E */  lhu       $t8, 0x6e($sp)
/* C1354 8012AC54 97B9007E */  lhu       $t9, 0x7e($sp)
/* C1358 8012AC58 94C3003C */  lhu       $v1, 0x3c($a2)
/* C135C 8012AC5C 94C4003E */  lhu       $a0, 0x3e($a2)
/* C1360 8012AC60 00031880 */  sll       $v1, $v1, 2
/* C1364 8012AC64 00041040 */  sll       $v0, $a0, 1
/* C1368 8012AC68 00441021 */  addu      $v0, $v0, $a0
/* C136C 8012AC6C 00021080 */  sll       $v0, $v0, 2
/* C1370 8012AC70 97C4045C */  lhu       $a0, 0x45c($fp)
/* C1374 8012AC74 3C08802F */  lui       $t0, %hi(gMsgCharsets)
/* C1378 8012AC78 01034021 */  addu      $t0, $t0, $v1
/* C137C 8012AC7C 8D08B5A8 */  lw        $t0, %lo(gMsgCharsets)($t0)
/* C1380 8012AC80 00982021 */  addu      $a0, $a0, $t8
/* C1384 8012AC84 8D030008 */  lw        $v1, 8($t0)
/* C1388 8012AC88 97B8008E */  lhu       $t8, 0x8e($sp)
/* C138C 8012AC8C 00433821 */  addu      $a3, $v0, $v1
/* C1390 8012AC90 90E50009 */  lbu       $a1, 9($a3)
/* C1394 8012AC94 94C30048 */  lhu       $v1, 0x48($a2)
/* C1398 8012AC98 94C20044 */  lhu       $v0, 0x44($a2)
/* C139C 8012AC9C 00052E00 */  sll       $a1, $a1, 0x18
/* C13A0 8012ACA0 00052E03 */  sra       $a1, $a1, 0x18
/* C13A4 8012ACA4 00641821 */  addu      $v1, $v1, $a0
/* C13A8 8012ACA8 00431021 */  addu      $v0, $v0, $v1
/* C13AC 8012ACAC 00591023 */  subu      $v0, $v0, $t9
/* C13B0 8012ACB0 00A22821 */  addu      $a1, $a1, $v0
/* C13B4 8012ACB4 00181400 */  sll       $v0, $t8, 0x10
/* C13B8 8012ACB8 00024C03 */  sra       $t1, $v0, 0x10
/* C13BC 8012ACBC 1120048B */  beqz      $t1, .L8012BEEC
/* C13C0 8012ACC0 00A0982D */   daddu    $s3, $a1, $zero
/* C13C4 8012ACC4 00111C00 */  sll       $v1, $s1, 0x10
/* C13C8 8012ACC8 8CC20004 */  lw        $v0, 4($a2)
/* C13CC 8012ACCC 00032403 */  sra       $a0, $v1, 0x10
/* C13D0 8012ACD0 0082102A */  slt       $v0, $a0, $v0
/* C13D4 8012ACD4 10400485 */  beqz      $v0, .L8012BEEC
/* C13D8 8012ACD8 00051C00 */   sll      $v1, $a1, 0x10
/* C13DC 8012ACDC 8CC2000C */  lw        $v0, 0xc($a2)
/* C13E0 8012ACE0 00032C03 */  sra       $a1, $v1, 0x10
/* C13E4 8012ACE4 00A2102A */  slt       $v0, $a1, $v0
/* C13E8 8012ACE8 10400480 */  beqz      $v0, .L8012BEEC
/* C13EC 8012ACEC 00000000 */   nop
/* C13F0 8012ACF0 90E20008 */  lbu       $v0, 8($a3)
/* C13F4 8012ACF4 C4C00010 */  lwc1      $f0, 0x10($a2)
/* C13F8 8012ACF8 44821000 */  mtc1      $v0, $f2
/* C13FC 8012ACFC 00000000 */  nop
/* C1400 8012AD00 468010A0 */  cvt.s.w   $f2, $f2
/* C1404 8012AD04 46020002 */  mul.s     $f0, $f0, $f2
/* C1408 8012AD08 00000000 */  nop
/* C140C 8012AD0C 8CC30000 */  lw        $v1, ($a2)
/* C1410 8012AD10 4600030D */  trunc.w.s $f12, $f0
/* C1414 8012AD14 44026000 */  mfc1      $v0, $f12
/* C1418 8012AD18 00000000 */  nop
/* C141C 8012AD1C 00821021 */  addu      $v0, $a0, $v0
/* C1420 8012AD20 0062182A */  slt       $v1, $v1, $v0
/* C1424 8012AD24 10600471 */  beqz      $v1, .L8012BEEC
/* C1428 8012AD28 00000000 */   nop
/* C142C 8012AD2C 91020003 */  lbu       $v0, 3($t0)
/* C1430 8012AD30 C4C20014 */  lwc1      $f2, 0x14($a2)
/* C1434 8012AD34 44820000 */  mtc1      $v0, $f0
/* C1438 8012AD38 00000000 */  nop
/* C143C 8012AD3C 46800020 */  cvt.s.w   $f0, $f0
/* C1440 8012AD40 93C20508 */  lbu       $v0, 0x508($fp)
/* C1444 8012AD44 46001082 */  mul.s     $f2, $f2, $f0
/* C1448 8012AD48 00000000 */  nop
/* C144C 8012AD4C 00021040 */  sll       $v0, $v0, 1
/* C1450 8012AD50 3C01802F */  lui       $at, %hi(D_802EB644)
/* C1454 8012AD54 00220821 */  addu      $at, $at, $v0
/* C1458 8012AD58 8422B644 */  lh        $v0, %lo(D_802EB644)($at)
/* C145C 8012AD5C 44820000 */  mtc1      $v0, $f0
/* C1460 8012AD60 00000000 */  nop
/* C1464 8012AD64 46800020 */  cvt.s.w   $f0, $f0
/* C1468 8012AD68 46001080 */  add.s     $f2, $f2, $f0
/* C146C 8012AD6C 8CC30008 */  lw        $v1, 8($a2)
/* C1470 8012AD70 4600130D */  trunc.w.s $f12, $f2
/* C1474 8012AD74 44026000 */  mfc1      $v0, $f12
/* C1478 8012AD78 00000000 */  nop
/* C147C 8012AD7C 00A21021 */  addu      $v0, $a1, $v0
/* C1480 8012AD80 0062182A */  slt       $v1, $v1, $v0
/* C1484 8012AD84 10600459 */  beqz      $v1, .L8012BEEC
/* C1488 8012AD88 00000000 */   nop
/* C148C 8012AD8C 97B2008E */  lhu       $s2, 0x8e($sp)
/* C1490 8012AD90 8CC50038 */  lw        $a1, 0x38($a2)
/* C1494 8012AD94 94D9004A */  lhu       $t9, 0x4a($a2)
/* C1498 8012AD98 30A20020 */  andi      $v0, $a1, 0x20
/* C149C 8012AD9C 1040000B */  beqz      $v0, .L8012ADCC
/* C14A0 8012ADA0 A7B900A6 */   sh       $t9, 0xa6($sp)
/* C14A4 8012ADA4 44890000 */  mtc1      $t1, $f0
/* C14A8 8012ADA8 00000000 */  nop
/* C14AC 8012ADAC 46800020 */  cvt.s.w   $f0, $f0
/* C14B0 8012ADB0 3C018015 */  lui       $at, %hi(D_801508F8)
/* C14B4 8012ADB4 D42208F8 */  ldc1      $f2, %lo(D_801508F8)($at)
/* C14B8 8012ADB8 46000021 */  cvt.d.s   $f0, $f0
/* C14BC 8012ADBC 46220002 */  mul.d     $f0, $f0, $f2
/* C14C0 8012ADC0 00000000 */  nop
/* C14C4 8012ADC4 4620030D */  trunc.w.d $f12, $f0
/* C14C8 8012ADC8 44126000 */  mfc1      $s2, $f12
.L8012ADCC:
/* C14CC 8012ADCC 93C204F8 */  lbu       $v0, 0x4f8($fp)
/* C14D0 8012ADD0 24190007 */  addiu     $t9, $zero, 7
/* C14D4 8012ADD4 14590018 */  bne       $v0, $t9, .L8012AE38
/* C14D8 8012ADD8 00000000 */   nop
/* C14DC 8012ADDC 94C20034 */  lhu       $v0, 0x34($a2)
/* C14E0 8012ADE0 30420020 */  andi      $v0, $v0, 0x20
/* C14E4 8012ADE4 10400014 */  beqz      $v0, .L8012AE38
/* C14E8 8012ADE8 00000000 */   nop
/* C14EC 8012ADEC 90C3002D */  lbu       $v1, 0x2d($a2)
/* C14F0 8012ADF0 93C204E8 */  lbu       $v0, 0x4e8($fp)
/* C14F4 8012ADF4 14620004 */  bne       $v1, $v0, .L8012AE08
/* C14F8 8012ADF8 3C04FFFF */   lui      $a0, 0xffff
/* C14FC 8012ADFC 34A28600 */  ori       $v0, $a1, 0x8600
/* C1500 8012AE00 0804AB8E */  j         .L8012AE38
/* C1504 8012AE04 ACC20038 */   sw       $v0, 0x38($a2)
.L8012AE08:
/* C1508 8012AE08 34847FFF */  ori       $a0, $a0, 0x7fff
/* C150C 8012AE0C 2402FBFF */  addiu     $v0, $zero, -0x401
/* C1510 8012AE10 00A21024 */  and       $v0, $a1, $v0
/* C1514 8012AE14 2403FDFF */  addiu     $v1, $zero, -0x201
/* C1518 8012AE18 94D8004A */  lhu       $t8, 0x4a($a2)
/* C151C 8012AE1C 00431024 */  and       $v0, $v0, $v1
/* C1520 8012AE20 A7B800A6 */  sh        $t8, 0xa6($sp)
/* C1524 8012AE24 94C30034 */  lhu       $v1, 0x34($a2)
/* C1528 8012AE28 00441024 */  and       $v0, $v0, $a0
/* C152C 8012AE2C ACC20038 */  sw        $v0, 0x38($a2)
/* C1530 8012AE30 34630010 */  ori       $v1, $v1, 0x10
/* C1534 8012AE34 A4C30034 */  sh        $v1, 0x34($a2)
.L8012AE38:
/* C1538 8012AE38 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* C153C 8012AE3C 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* C1540 8012AE40 8C420038 */  lw        $v0, 0x38($v0)
/* C1544 8012AE44 30420001 */  andi      $v0, $v0, 1
/* C1548 8012AE48 10400011 */  beqz      $v0, .L8012AE90
/* C154C 8012AE4C 00000000 */   nop
/* C1550 8012AE50 0C00A67F */  jal       rand_int
/* C1554 8012AE54 24042710 */   addiu    $a0, $zero, 0x2710
/* C1558 8012AE58 00021FC2 */  srl       $v1, $v0, 0x1f
/* C155C 8012AE5C 00431821 */  addu      $v1, $v0, $v1
/* C1560 8012AE60 00031843 */  sra       $v1, $v1, 1
/* C1564 8012AE64 00031840 */  sll       $v1, $v1, 1
/* C1568 8012AE68 00431023 */  subu      $v0, $v0, $v1
/* C156C 8012AE6C 02228821 */  addu      $s1, $s1, $v0
/* C1570 8012AE70 0C00A67F */  jal       rand_int
/* C1574 8012AE74 24042710 */   addiu    $a0, $zero, 0x2710
/* C1578 8012AE78 00021FC2 */  srl       $v1, $v0, 0x1f
/* C157C 8012AE7C 00431821 */  addu      $v1, $v0, $v1
/* C1580 8012AE80 00031843 */  sra       $v1, $v1, 1
/* C1584 8012AE84 00031840 */  sll       $v1, $v1, 1
/* C1588 8012AE88 00431023 */  subu      $v0, $v0, $v1
/* C158C 8012AE8C 02629821 */  addu      $s3, $s3, $v0
.L8012AE90:
/* C1590 8012AE90 3C048015 */  lui       $a0, %hi(gMessageDrawStatePtr)
/* C1594 8012AE94 8C845D74 */  lw        $a0, %lo(gMessageDrawStatePtr)($a0)
/* C1598 8012AE98 8C820038 */  lw        $v0, 0x38($a0)
/* C159C 8012AE9C 30420002 */  andi      $v0, $v0, 2
/* C15A0 8012AEA0 10400063 */  beqz      $v0, .L8012B030
/* C15A4 8012AEA4 00000000 */   nop
/* C15A8 8012AEA8 C4820010 */  lwc1      $f2, 0x10($a0)
/* C15AC 8012AEAC 3C013FF0 */  lui       $at, 0x3ff0
/* C15B0 8012AEB0 44816800 */  mtc1      $at, $f13
/* C15B4 8012AEB4 44806000 */  mtc1      $zero, $f12
/* C15B8 8012AEB8 460010A1 */  cvt.d.s   $f2, $f2
/* C15BC 8012AEBC 462C1081 */  sub.d     $f2, $f2, $f12
/* C15C0 8012AEC0 3C014014 */  lui       $at, 0x4014
/* C15C4 8012AEC4 44812800 */  mtc1      $at, $f5
/* C15C8 8012AEC8 44802000 */  mtc1      $zero, $f4
/* C15CC 8012AECC 00000000 */  nop
/* C15D0 8012AED0 46241102 */  mul.d     $f4, $f2, $f4
/* C15D4 8012AED4 00000000 */  nop
/* C15D8 8012AED8 3C01402E */  lui       $at, 0x402e
/* C15DC 8012AEDC 44810800 */  mtc1      $at, $f1
/* C15E0 8012AEE0 44800000 */  mtc1      $zero, $f0
/* C15E4 8012AEE4 00000000 */  nop
/* C15E8 8012AEE8 46201082 */  mul.d     $f2, $f2, $f0
/* C15EC 8012AEEC 00000000 */  nop
/* C15F0 8012AEF0 3C014034 */  lui       $at, 0x4034
/* C15F4 8012AEF4 44810800 */  mtc1      $at, $f1
/* C15F8 8012AEF8 44800000 */  mtc1      $zero, $f0
/* C15FC 8012AEFC 00000000 */  nop
/* C1600 8012AF00 46240001 */  sub.d     $f0, $f0, $f4
/* C1604 8012AF04 97C30452 */  lhu       $v1, 0x452($fp)
/* C1608 8012AF08 4620030D */  trunc.w.d $f12, $f0
/* C160C 8012AF0C 44026000 */  mfc1      $v0, $f12
/* C1610 8012AF10 00000000 */  nop
/* C1614 8012AF14 00620018 */  mult      $v1, $v0
/* C1618 8012AF18 3C018015 */  lui       $at, %hi(D_80150900)
/* C161C 8012AF1C D4200900 */  ldc1      $f0, %lo(D_80150900)($at)
/* C1620 8012AF20 46220001 */  sub.d     $f0, $f0, $f2
/* C1624 8012AF24 00002812 */  mflo      $a1
/* C1628 8012AF28 8C830030 */  lw        $v1, 0x30($a0)
/* C162C 8012AF2C 4620030D */  trunc.w.d $f12, $f0
/* C1630 8012AF30 44026000 */  mfc1      $v0, $f12
/* C1634 8012AF34 00000000 */  nop
/* C1638 8012AF38 00620018 */  mult      $v1, $v0
/* C163C 8012AF3C 00001812 */  mflo      $v1
/* C1640 8012AF40 00A38023 */  subu      $s0, $a1, $v1
/* C1644 8012AF44 00102400 */  sll       $a0, $s0, 0x10
/* C1648 8012AF48 0C00A4F5 */  jal       cosine
/* C164C 8012AF4C 00042403 */   sra      $a0, $a0, 0x10
/* C1650 8012AF50 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* C1654 8012AF54 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* C1658 8012AF58 C4420010 */  lwc1      $f2, 0x10($v0)
/* C165C 8012AF5C 3C013FF0 */  lui       $at, 0x3ff0
/* C1660 8012AF60 44816800 */  mtc1      $at, $f13
/* C1664 8012AF64 44806000 */  mtc1      $zero, $f12
/* C1668 8012AF68 460010A1 */  cvt.d.s   $f2, $f2
/* C166C 8012AF6C 462C1081 */  sub.d     $f2, $f2, $f12
/* C1670 8012AF70 3C018015 */  lui       $at, %hi(D_80150908)
/* C1674 8012AF74 D4340908 */  ldc1      $f20, %lo(D_80150908)($at)
/* C1678 8012AF78 46341080 */  add.d     $f2, $f2, $f20
/* C167C 8012AF7C 46000021 */  cvt.d.s   $f0, $f0
/* C1680 8012AF80 46220002 */  mul.d     $f0, $f0, $f2
/* C1684 8012AF84 00000000 */  nop
/* C1688 8012AF88 3C018015 */  lui       $at, %hi(D_80150910)
/* C168C 8012AF8C D4240910 */  ldc1      $f4, %lo(D_80150910)($at)
/* C1690 8012AF90 44901000 */  mtc1      $s0, $f2
/* C1694 8012AF94 00000000 */  nop
/* C1698 8012AF98 468010A1 */  cvt.d.w   $f2, $f2
/* C169C 8012AF9C 46241080 */  add.d     $f2, $f2, $f4
/* C16A0 8012AFA0 3C018015 */  lui       $at, %hi(D_80150918)
/* C16A4 8012AFA4 D4240918 */  ldc1      $f4, %lo(D_80150918)($at)
/* C16A8 8012AFA8 00111400 */  sll       $v0, $s1, 0x10
/* C16AC 8012AFAC 46241080 */  add.d     $f2, $f2, $f4
/* C16B0 8012AFB0 00021403 */  sra       $v0, $v0, 0x10
/* C16B4 8012AFB4 44822000 */  mtc1      $v0, $f4
/* C16B8 8012AFB8 00000000 */  nop
/* C16BC 8012AFBC 46802121 */  cvt.d.w   $f4, $f4
/* C16C0 8012AFC0 4620130D */  trunc.w.d $f12, $f2
/* C16C4 8012AFC4 44046000 */  mfc1      $a0, $f12
/* C16C8 8012AFC8 46202100 */  add.d     $f4, $f4, $f0
/* C16CC 8012AFCC 00042400 */  sll       $a0, $a0, 0x10
/* C16D0 8012AFD0 4620230D */  trunc.w.d $f12, $f4
/* C16D4 8012AFD4 44116000 */  mfc1      $s1, $f12
/* C16D8 8012AFD8 0C00A4F5 */  jal       cosine
/* C16DC 8012AFDC 00042403 */   sra      $a0, $a0, 0x10
/* C16E0 8012AFE0 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* C16E4 8012AFE4 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* C16E8 8012AFE8 C4420014 */  lwc1      $f2, 0x14($v0)
/* C16EC 8012AFEC 3C013FF0 */  lui       $at, 0x3ff0
/* C16F0 8012AFF0 44816800 */  mtc1      $at, $f13
/* C16F4 8012AFF4 44806000 */  mtc1      $zero, $f12
/* C16F8 8012AFF8 460010A1 */  cvt.d.s   $f2, $f2
/* C16FC 8012AFFC 462C1081 */  sub.d     $f2, $f2, $f12
/* C1700 8012B000 46341080 */  add.d     $f2, $f2, $f20
/* C1704 8012B004 46000021 */  cvt.d.s   $f0, $f0
/* C1708 8012B008 46220002 */  mul.d     $f0, $f0, $f2
/* C170C 8012B00C 00000000 */  nop
/* C1710 8012B010 00131400 */  sll       $v0, $s3, 0x10
/* C1714 8012B014 00021403 */  sra       $v0, $v0, 0x10
/* C1718 8012B018 44821000 */  mtc1      $v0, $f2
/* C171C 8012B01C 00000000 */  nop
/* C1720 8012B020 468010A1 */  cvt.d.w   $f2, $f2
/* C1724 8012B024 46201080 */  add.d     $f2, $f2, $f0
/* C1728 8012B028 4620130D */  trunc.w.d $f12, $f2
/* C172C 8012B02C 44136000 */  mfc1      $s3, $f12
.L8012B030:
/* C1730 8012B030 3C038015 */  lui       $v1, %hi(gMessageDrawStatePtr)
/* C1734 8012B034 8C635D74 */  lw        $v1, %lo(gMessageDrawStatePtr)($v1)
/* C1738 8012B038 8C620038 */  lw        $v0, 0x38($v1)
/* C173C 8012B03C 30420200 */  andi      $v0, $v0, 0x200
/* C1740 8012B040 1040005A */  beqz      $v0, .L8012B1AC
/* C1744 8012B044 00000000 */   nop
/* C1748 8012B048 C4620010 */  lwc1      $f2, 0x10($v1)
/* C174C 8012B04C 3C013FF0 */  lui       $at, 0x3ff0
/* C1750 8012B050 44816800 */  mtc1      $at, $f13
/* C1754 8012B054 44806000 */  mtc1      $zero, $f12
/* C1758 8012B058 460010A1 */  cvt.d.s   $f2, $f2
/* C175C 8012B05C 462C1081 */  sub.d     $f2, $f2, $f12
/* C1760 8012B060 3C014014 */  lui       $at, 0x4014
/* C1764 8012B064 44810800 */  mtc1      $at, $f1
/* C1768 8012B068 44800000 */  mtc1      $zero, $f0
/* C176C 8012B06C 00000000 */  nop
/* C1770 8012B070 46201082 */  mul.d     $f2, $f2, $f0
/* C1774 8012B074 00000000 */  nop
/* C1778 8012B078 3C014034 */  lui       $at, 0x4034
/* C177C 8012B07C 44810800 */  mtc1      $at, $f1
/* C1780 8012B080 44800000 */  mtc1      $zero, $f0
/* C1784 8012B084 00000000 */  nop
/* C1788 8012B088 46220001 */  sub.d     $f0, $f0, $f2
/* C178C 8012B08C 3C028015 */  lui       $v0, %hi(gMsgGlobalWaveCounter)
/* C1790 8012B090 944212E4 */  lhu       $v0, %lo(gMsgGlobalWaveCounter)($v0)
/* C1794 8012B094 8C630030 */  lw        $v1, 0x30($v1)
/* C1798 8012B098 4620030D */  trunc.w.d $f12, $f0
/* C179C 8012B09C 44046000 */  mfc1      $a0, $f12
/* C17A0 8012B0A0 00000000 */  nop
/* C17A4 8012B0A4 00440018 */  mult      $v0, $a0
/* C17A8 8012B0A8 00031040 */  sll       $v0, $v1, 1
/* C17AC 8012B0AC 00431021 */  addu      $v0, $v0, $v1
/* C17B0 8012B0B0 00028100 */  sll       $s0, $v0, 4
/* C17B4 8012B0B4 02028023 */  subu      $s0, $s0, $v0
/* C17B8 8012B0B8 0000C012 */  mflo      $t8
/* C17BC 8012B0BC 03108023 */  subu      $s0, $t8, $s0
/* C17C0 8012B0C0 00102400 */  sll       $a0, $s0, 0x10
/* C17C4 8012B0C4 0C00A4F5 */  jal       cosine
/* C17C8 8012B0C8 00042403 */   sra      $a0, $a0, 0x10
/* C17CC 8012B0CC 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* C17D0 8012B0D0 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* C17D4 8012B0D4 C4420010 */  lwc1      $f2, 0x10($v0)
/* C17D8 8012B0D8 3C013FF0 */  lui       $at, 0x3ff0
/* C17DC 8012B0DC 44816800 */  mtc1      $at, $f13
/* C17E0 8012B0E0 44806000 */  mtc1      $zero, $f12
/* C17E4 8012B0E4 460010A1 */  cvt.d.s   $f2, $f2
/* C17E8 8012B0E8 462C1081 */  sub.d     $f2, $f2, $f12
/* C17EC 8012B0EC 3C018015 */  lui       $at, %hi(D_80150920)
/* C17F0 8012B0F0 D4340920 */  ldc1      $f20, %lo(D_80150920)($at)
/* C17F4 8012B0F4 46341080 */  add.d     $f2, $f2, $f20
/* C17F8 8012B0F8 46000021 */  cvt.d.s   $f0, $f0
/* C17FC 8012B0FC 46220002 */  mul.d     $f0, $f0, $f2
/* C1800 8012B100 00000000 */  nop
/* C1804 8012B104 3C018015 */  lui       $at, %hi(D_80150928)
/* C1808 8012B108 D4240928 */  ldc1      $f4, %lo(D_80150928)($at)
/* C180C 8012B10C 44901000 */  mtc1      $s0, $f2
/* C1810 8012B110 00000000 */  nop
/* C1814 8012B114 468010A1 */  cvt.d.w   $f2, $f2
/* C1818 8012B118 46241080 */  add.d     $f2, $f2, $f4
/* C181C 8012B11C 3C018015 */  lui       $at, %hi(D_80150930)
/* C1820 8012B120 D4240930 */  ldc1      $f4, %lo(D_80150930)($at)
/* C1824 8012B124 00111400 */  sll       $v0, $s1, 0x10
/* C1828 8012B128 46241080 */  add.d     $f2, $f2, $f4
/* C182C 8012B12C 00021403 */  sra       $v0, $v0, 0x10
/* C1830 8012B130 44822000 */  mtc1      $v0, $f4
/* C1834 8012B134 00000000 */  nop
/* C1838 8012B138 46802121 */  cvt.d.w   $f4, $f4
/* C183C 8012B13C 4620130D */  trunc.w.d $f12, $f2
/* C1840 8012B140 44046000 */  mfc1      $a0, $f12
/* C1844 8012B144 46202100 */  add.d     $f4, $f4, $f0
/* C1848 8012B148 00042400 */  sll       $a0, $a0, 0x10
/* C184C 8012B14C 4620230D */  trunc.w.d $f12, $f4
/* C1850 8012B150 44116000 */  mfc1      $s1, $f12
/* C1854 8012B154 0C00A4F5 */  jal       cosine
/* C1858 8012B158 00042403 */   sra      $a0, $a0, 0x10
/* C185C 8012B15C 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* C1860 8012B160 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* C1864 8012B164 C4420014 */  lwc1      $f2, 0x14($v0)
/* C1868 8012B168 3C013FF0 */  lui       $at, 0x3ff0
/* C186C 8012B16C 44816800 */  mtc1      $at, $f13
/* C1870 8012B170 44806000 */  mtc1      $zero, $f12
/* C1874 8012B174 460010A1 */  cvt.d.s   $f2, $f2
/* C1878 8012B178 462C1081 */  sub.d     $f2, $f2, $f12
/* C187C 8012B17C 46341080 */  add.d     $f2, $f2, $f20
/* C1880 8012B180 46000021 */  cvt.d.s   $f0, $f0
/* C1884 8012B184 46220002 */  mul.d     $f0, $f0, $f2
/* C1888 8012B188 00000000 */  nop
/* C188C 8012B18C 00131400 */  sll       $v0, $s3, 0x10
/* C1890 8012B190 00021403 */  sra       $v0, $v0, 0x10
/* C1894 8012B194 44821000 */  mtc1      $v0, $f2
/* C1898 8012B198 00000000 */  nop
/* C189C 8012B19C 468010A1 */  cvt.d.w   $f2, $f2
/* C18A0 8012B1A0 46201080 */  add.d     $f2, $f2, $f0
/* C18A4 8012B1A4 4620130D */  trunc.w.d $f12, $f2
/* C18A8 8012B1A8 44136000 */  mfc1      $s3, $f12
.L8012B1AC:
/* C18AC 8012B1AC 3C058015 */  lui       $a1, %hi(gMessageDrawStatePtr)
/* C18B0 8012B1B0 8CA55D74 */  lw        $a1, %lo(gMessageDrawStatePtr)($a1)
/* C18B4 8012B1B4 8CA60038 */  lw        $a2, 0x38($a1)
/* C18B8 8012B1B8 30C20040 */  andi      $v0, $a2, 0x40
/* C18BC 8012B1BC 10400019 */  beqz      $v0, .L8012B224
/* C18C0 8012B1C0 30C20400 */   andi     $v0, $a2, 0x400
/* C18C4 8012B1C4 97C30452 */  lhu       $v1, 0x452($fp)
/* C18C8 8012B1C8 3C02AAAA */  lui       $v0, 0xaaaa
/* C18CC 8012B1CC 3442AAAB */  ori       $v0, $v0, 0xaaab
/* C18D0 8012B1D0 00620019 */  multu     $v1, $v0
/* C18D4 8012B1D4 8CA40030 */  lw        $a0, 0x30($a1)
/* C18D8 8012B1D8 3C036666 */  lui       $v1, 0x6666
/* C18DC 8012B1DC 34636667 */  ori       $v1, $v1, 0x6667
/* C18E0 8012B1E0 0000C010 */  mfhi      $t8
/* C18E4 8012B1E4 00181042 */  srl       $v0, $t8, 1
/* C18E8 8012B1E8 3042FFFF */  andi      $v0, $v0, 0xffff
/* C18EC 8012B1EC 00822023 */  subu      $a0, $a0, $v0
/* C18F0 8012B1F0 04820001 */  bltzl     $a0, .L8012B1F8
/* C18F4 8012B1F4 00042023 */   negu     $a0, $a0
.L8012B1F8:
/* C18F8 8012B1F8 00830018 */  mult      $a0, $v1
/* C18FC 8012B1FC 000417C3 */  sra       $v0, $a0, 0x1f
/* C1900 8012B200 0000C010 */  mfhi      $t8
/* C1904 8012B204 00181883 */  sra       $v1, $t8, 2
/* C1908 8012B208 00621823 */  subu      $v1, $v1, $v0
/* C190C 8012B20C 00031080 */  sll       $v0, $v1, 2
/* C1910 8012B210 00431021 */  addu      $v0, $v0, $v1
/* C1914 8012B214 00021040 */  sll       $v0, $v0, 1
/* C1918 8012B218 00822023 */  subu      $a0, $a0, $v0
/* C191C 8012B21C A7A400A6 */  sh        $a0, 0xa6($sp)
/* C1920 8012B220 30C20400 */  andi      $v0, $a2, 0x400
.L8012B224:
/* C1924 8012B224 1040001B */  beqz      $v0, .L8012B294
/* C1928 8012B228 30C20080 */   andi     $v0, $a2, 0x80
/* C192C 8012B22C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* C1930 8012B230 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* C1934 8012B234 94430134 */  lhu       $v1, 0x134($v0)
/* C1938 8012B238 3C02AAAA */  lui       $v0, 0xaaaa
/* C193C 8012B23C 3442AAAB */  ori       $v0, $v0, 0xaaab
/* C1940 8012B240 00620019 */  multu     $v1, $v0
/* C1944 8012B244 8CA40030 */  lw        $a0, 0x30($a1)
/* C1948 8012B248 3C036666 */  lui       $v1, 0x6666
/* C194C 8012B24C 34636667 */  ori       $v1, $v1, 0x6667
/* C1950 8012B250 0000C010 */  mfhi      $t8
/* C1954 8012B254 00181042 */  srl       $v0, $t8, 1
/* C1958 8012B258 3042FFFF */  andi      $v0, $v0, 0xffff
/* C195C 8012B25C 00822023 */  subu      $a0, $a0, $v0
/* C1960 8012B260 04820001 */  bltzl     $a0, .L8012B268
/* C1964 8012B264 00042023 */   negu     $a0, $a0
.L8012B268:
/* C1968 8012B268 00830018 */  mult      $a0, $v1
/* C196C 8012B26C 000417C3 */  sra       $v0, $a0, 0x1f
/* C1970 8012B270 0000C010 */  mfhi      $t8
/* C1974 8012B274 00181883 */  sra       $v1, $t8, 2
/* C1978 8012B278 00621823 */  subu      $v1, $v1, $v0
/* C197C 8012B27C 00031080 */  sll       $v0, $v1, 2
/* C1980 8012B280 00431021 */  addu      $v0, $v0, $v1
/* C1984 8012B284 00021040 */  sll       $v0, $v0, 1
/* C1988 8012B288 00822023 */  subu      $a0, $a0, $v0
/* C198C 8012B28C A7A400A6 */  sh        $a0, 0xa6($sp)
/* C1990 8012B290 30C20080 */  andi      $v0, $a2, 0x80
.L8012B294:
/* C1994 8012B294 10400020 */  beqz      $v0, .L8012B318
/* C1998 8012B298 3C05E300 */   lui      $a1, 0xe300
/* C199C 8012B29C 34A51A01 */  ori       $a1, $a1, 0x1a01
/* C19A0 8012B2A0 3C06E200 */  lui       $a2, 0xe200
/* C19A4 8012B2A4 34C61E01 */  ori       $a2, $a2, 0x1e01
/* C19A8 8012B2A8 00121400 */  sll       $v0, $s2, 0x10
/* C19AC 8012B2AC 00021403 */  sra       $v0, $v0, 0x10
/* C19B0 8012B2B0 44820000 */  mtc1      $v0, $f0
/* C19B4 8012B2B4 00000000 */  nop
/* C19B8 8012B2B8 46800021 */  cvt.d.w   $f0, $f0
/* C19BC 8012B2BC 24020020 */  addiu     $v0, $zero, 0x20
/* C19C0 8012B2C0 8EE30000 */  lw        $v1, ($s7)
/* C19C4 8012B2C4 3C018015 */  lui       $at, %hi(D_80150938)
/* C19C8 8012B2C8 D4220938 */  ldc1      $f2, %lo(D_80150938)($at)
/* C19CC 8012B2CC 0060202D */  daddu     $a0, $v1, $zero
/* C19D0 8012B2D0 24630008 */  addiu     $v1, $v1, 8
/* C19D4 8012B2D4 AEE30000 */  sw        $v1, ($s7)
/* C19D8 8012B2D8 97B900B6 */  lhu       $t9, 0xb6($sp)
/* C19DC 8012B2DC 46220003 */  div.d     $f0, $f0, $f2
/* C19E0 8012B2E0 44992000 */  mtc1      $t9, $f4
/* C19E4 8012B2E4 00000000 */  nop
/* C19E8 8012B2E8 46802121 */  cvt.d.w   $f4, $f4
/* C19EC 8012B2EC 46202102 */  mul.d     $f4, $f4, $f0
/* C19F0 8012B2F0 00000000 */  nop
/* C19F4 8012B2F4 AC820004 */  sw        $v0, 4($a0)
/* C19F8 8012B2F8 24620008 */  addiu     $v0, $v1, 8
/* C19FC 8012B2FC AC850000 */  sw        $a1, ($a0)
/* C1A00 8012B300 24180003 */  addiu     $t8, $zero, 3
/* C1A04 8012B304 AEE20000 */  sw        $v0, ($s7)
/* C1A08 8012B308 AC660000 */  sw        $a2, ($v1)
/* C1A0C 8012B30C AC780004 */  sw        $t8, 4($v1)
/* C1A10 8012B310 4620230D */  trunc.w.d $f12, $f4
/* C1A14 8012B314 44126000 */  mfc1      $s2, $f12
.L8012B318:
/* C1A18 8012B318 3C028015 */  lui       $v0, %hi(gMessageDrawStatePtr)
/* C1A1C 8012B31C 8C425D74 */  lw        $v0, %lo(gMessageDrawStatePtr)($v0)
/* C1A20 8012B320 94420034 */  lhu       $v0, 0x34($v0)
/* C1A24 8012B324 30420002 */  andi      $v0, $v0, 2
/* C1A28 8012B328 14400005 */  bnez      $v0, .L8012B340
/* C1A2C 8012B32C 00121C00 */   sll      $v1, $s2, 0x10
/* C1A30 8012B330 97B90096 */  lhu       $t9, 0x96($sp)
/* C1A34 8012B334 00191400 */  sll       $v0, $t9, 0x10
/* C1A38 8012B338 10620063 */  beq       $v1, $v0, .L8012B4C8
/* C1A3C 8012B33C 00121400 */   sll      $v0, $s2, 0x10
.L8012B340:
/* C1A40 8012B340 97B80096 */  lhu       $t8, 0x96($sp)
/* C1A44 8012B344 00181400 */  sll       $v0, $t8, 0x10
/* C1A48 8012B348 00021403 */  sra       $v0, $v0, 0x10
/* C1A4C 8012B34C 284200FF */  slti      $v0, $v0, 0xff
/* C1A50 8012B350 10400009 */  beqz      $v0, .L8012B378
/* C1A54 8012B354 00121400 */   sll      $v0, $s2, 0x10
/* C1A58 8012B358 00021403 */  sra       $v0, $v0, 0x10
/* C1A5C 8012B35C 284200FF */  slti      $v0, $v0, 0xff
/* C1A60 8012B360 10400005 */  beqz      $v0, .L8012B378
/* C1A64 8012B364 00000000 */   nop
/* C1A68 8012B368 8EE20000 */  lw        $v0, ($s7)
/* C1A6C 8012B36C 0040182D */  daddu     $v1, $v0, $zero
/* C1A70 8012B370 0804AD09 */  j         .L8012B424
/* C1A74 8012B374 24420008 */   addiu    $v0, $v0, 8
.L8012B378:
/* C1A78 8012B378 97B90096 */  lhu       $t9, 0x96($sp)
/* C1A7C 8012B37C 241800FF */  addiu     $t8, $zero, 0xff
/* C1A80 8012B380 00191400 */  sll       $v0, $t9, 0x10
/* C1A84 8012B384 00021403 */  sra       $v0, $v0, 0x10
/* C1A88 8012B388 1458002C */  bne       $v0, $t8, .L8012B43C
/* C1A8C 8012B38C 00121400 */   sll      $v0, $s2, 0x10
/* C1A90 8012B390 00021403 */  sra       $v0, $v0, 0x10
/* C1A94 8012B394 0058102A */  slt       $v0, $v0, $t8
/* C1A98 8012B398 10400028 */  beqz      $v0, .L8012B43C
/* C1A9C 8012B39C 3C19E700 */   lui      $t9, 0xe700
/* C1AA0 8012B3A0 8EE50000 */  lw        $a1, ($s7)
/* C1AA4 8012B3A4 00A0102D */  daddu     $v0, $a1, $zero
/* C1AA8 8012B3A8 AC590000 */  sw        $t9, ($v0)
/* C1AAC 8012B3AC AC400004 */  sw        $zero, 4($v0)
/* C1AB0 8012B3B0 8FC204FC */  lw        $v0, 0x4fc($fp)
/* C1AB4 8012B3B4 24A50008 */  addiu     $a1, $a1, 8
/* C1AB8 8012B3B8 30424000 */  andi      $v0, $v0, 0x4000
/* C1ABC 8012B3BC 10400006 */  beqz      $v0, .L8012B3D8
/* C1AC0 8012B3C0 AEE50000 */   sw       $a1, ($s7)
/* C1AC4 8012B3C4 3C04E200 */  lui       $a0, 0xe200
/* C1AC8 8012B3C8 3484001C */  ori       $a0, $a0, 0x1c
/* C1ACC 8012B3CC 3C030050 */  lui       $v1, 0x50
/* C1AD0 8012B3D0 0804ACFA */  j         .L8012B3E8
/* C1AD4 8012B3D4 34634840 */   ori      $v1, $v1, 0x4840
.L8012B3D8:
/* C1AD8 8012B3D8 3C04E200 */  lui       $a0, 0xe200
/* C1ADC 8012B3DC 3484001C */  ori       $a0, $a0, 0x1c
/* C1AE0 8012B3E0 3C030050 */  lui       $v1, 0x50
/* C1AE4 8012B3E4 34634B40 */  ori       $v1, $v1, 0x4b40
.L8012B3E8:
/* C1AE8 8012B3E8 24A20008 */  addiu     $v0, $a1, 8
/* C1AEC 8012B3EC AEE20000 */  sw        $v0, ($s7)
/* C1AF0 8012B3F0 ACA40000 */  sw        $a0, ($a1)
/* C1AF4 8012B3F4 ACA30004 */  sw        $v1, 4($a1)
/* C1AF8 8012B3F8 3C05FCFF */  lui       $a1, 0xfcff
/* C1AFC 8012B3FC 34A597FF */  ori       $a1, $a1, 0x97ff
/* C1B00 8012B400 3C04FF2C */  lui       $a0, 0xff2c
/* C1B04 8012B404 8EE30000 */  lw        $v1, ($s7)
/* C1B08 8012B408 3484FE7F */  ori       $a0, $a0, 0xfe7f
/* C1B0C 8012B40C 0060102D */  daddu     $v0, $v1, $zero
/* C1B10 8012B410 24630008 */  addiu     $v1, $v1, 8
/* C1B14 8012B414 AEE30000 */  sw        $v1, ($s7)
/* C1B18 8012B418 AC450000 */  sw        $a1, ($v0)
/* C1B1C 8012B41C AC440004 */  sw        $a0, 4($v0)
/* C1B20 8012B420 24620008 */  addiu     $v0, $v1, 8
.L8012B424:
/* C1B24 8012B424 AEE20000 */  sw        $v0, ($s7)
/* C1B28 8012B428 3C02FA00 */  lui       $v0, 0xfa00
/* C1B2C 8012B42C AC620000 */  sw        $v0, ($v1)
/* C1B30 8012B430 324200FF */  andi      $v0, $s2, 0xff
/* C1B34 8012B434 0804AD30 */  j         .L8012B4C0
/* C1B38 8012B438 AC620004 */   sw       $v0, 4($v1)
.L8012B43C:
/* C1B3C 8012B43C 97B80096 */  lhu       $t8, 0x96($sp)
/* C1B40 8012B440 00181400 */  sll       $v0, $t8, 0x10
/* C1B44 8012B444 00021403 */  sra       $v0, $v0, 0x10
/* C1B48 8012B448 284200FF */  slti      $v0, $v0, 0xff
/* C1B4C 8012B44C 1040001C */  beqz      $v0, .L8012B4C0
/* C1B50 8012B450 00121400 */   sll      $v0, $s2, 0x10
/* C1B54 8012B454 00021403 */  sra       $v0, $v0, 0x10
/* C1B58 8012B458 241900FF */  addiu     $t9, $zero, 0xff
/* C1B5C 8012B45C 54590019 */  bnel      $v0, $t9, .L8012B4C4
/* C1B60 8012B460 A7B20096 */   sh       $s2, 0x96($sp)
/* C1B64 8012B464 3C06E200 */  lui       $a2, 0xe200
/* C1B68 8012B468 34C6001C */  ori       $a2, $a2, 0x1c
/* C1B6C 8012B46C 3C040F0A */  lui       $a0, 0xf0a
/* C1B70 8012B470 34847008 */  ori       $a0, $a0, 0x7008
/* C1B74 8012B474 3C07FCFF */  lui       $a3, 0xfcff
/* C1B78 8012B478 34E7FFFF */  ori       $a3, $a3, 0xffff
/* C1B7C 8012B47C 3C05FFFC */  lui       $a1, 0xfffc
/* C1B80 8012B480 8EE30000 */  lw        $v1, ($s7)
/* C1B84 8012B484 34A5F279 */  ori       $a1, $a1, 0xf279
/* C1B88 8012B488 0060102D */  daddu     $v0, $v1, $zero
/* C1B8C 8012B48C 24630008 */  addiu     $v1, $v1, 8
/* C1B90 8012B490 3C18E700 */  lui       $t8, 0xe700
/* C1B94 8012B494 AEE30000 */  sw        $v1, ($s7)
/* C1B98 8012B498 AC580000 */  sw        $t8, ($v0)
/* C1B9C 8012B49C AC400004 */  sw        $zero, 4($v0)
/* C1BA0 8012B4A0 24620008 */  addiu     $v0, $v1, 8
/* C1BA4 8012B4A4 AEE20000 */  sw        $v0, ($s7)
/* C1BA8 8012B4A8 24620010 */  addiu     $v0, $v1, 0x10
/* C1BAC 8012B4AC AC660000 */  sw        $a2, ($v1)
/* C1BB0 8012B4B0 AC640004 */  sw        $a0, 4($v1)
/* C1BB4 8012B4B4 AEE20000 */  sw        $v0, ($s7)
/* C1BB8 8012B4B8 AC670008 */  sw        $a3, 8($v1)
/* C1BBC 8012B4BC AC65000C */  sw        $a1, 0xc($v1)
.L8012B4C0:
/* C1BC0 8012B4C0 A7B20096 */  sh        $s2, 0x96($sp)
.L8012B4C4:
/* C1BC4 8012B4C4 00121400 */  sll       $v0, $s2, 0x10
.L8012B4C8:
/* C1BC8 8012B4C8 18400288 */  blez      $v0, .L8012BEEC
/* C1BCC 8012B4CC 00000000 */   nop
/* C1BD0 8012B4D0 3C068015 */  lui       $a2, %hi(gMessageDrawStatePtr)
/* C1BD4 8012B4D4 8CC65D74 */  lw        $a2, %lo(gMessageDrawStatePtr)($a2)
/* C1BD8 8012B4D8 8CC30038 */  lw        $v1, 0x38($a2)
/* C1BDC 8012B4DC 30620800 */  andi      $v0, $v1, 0x800
/* C1BE0 8012B4E0 10400092 */  beqz      $v0, .L8012B72C
/* C1BE4 8012B4E4 240400F0 */   addiu    $a0, $zero, 0xf0
/* C1BE8 8012B4E8 8CC30020 */  lw        $v1, 0x20($a2)
/* C1BEC 8012B4EC 8CC2004C */  lw        $v0, 0x4c($a2)
/* C1BF0 8012B4F0 00621821 */  addu      $v1, $v1, $v0
/* C1BF4 8012B4F4 90650001 */  lbu       $a1, 1($v1)
/* C1BF8 8012B4F8 10A401B8 */  beq       $a1, $a0, .L8012BBDC
/* C1BFC 8012B4FC 00000000 */   nop
/* C1C00 8012B500 90620002 */  lbu       $v0, 2($v1)
/* C1C04 8012B504 104401B5 */  beq       $v0, $a0, .L8012BBDC
/* C1C08 8012B508 00000000 */   nop
/* C1C0C 8012B50C 90620003 */  lbu       $v0, 3($v1)
/* C1C10 8012B510 104401B2 */  beq       $v0, $a0, .L8012BBDC
/* C1C14 8012B514 00000000 */   nop
/* C1C18 8012B518 90620004 */  lbu       $v0, 4($v1)
/* C1C1C 8012B51C 104401AF */  beq       $v0, $a0, .L8012BBDC
/* C1C20 8012B520 240200FB */   addiu    $v0, $zero, 0xfb
/* C1C24 8012B524 14A20026 */  bne       $a1, $v0, .L8012B5C0
/* C1C28 8012B528 24020004 */   addiu    $v0, $zero, 4
/* C1C2C 8012B52C 93C304F8 */  lbu       $v1, 0x4f8($fp)
/* C1C30 8012B530 14620023 */  bne       $v1, $v0, .L8012B5C0
/* C1C34 8012B534 00111400 */   sll      $v0, $s1, 0x10
/* C1C38 8012B538 C4C60014 */  lwc1      $f6, 0x14($a2)
/* C1C3C 8012B53C 3C018015 */  lui       $at, %hi(D_80150940)
/* C1C40 8012B540 D4280940 */  ldc1      $f8, %lo(D_80150940)($at)
/* C1C44 8012B544 460031A1 */  cvt.d.s   $f6, $f6
/* C1C48 8012B548 46283182 */  mul.d     $f6, $f6, $f8
/* C1C4C 8012B54C 00000000 */  nop
/* C1C50 8012B550 C4C00010 */  lwc1      $f0, 0x10($a2)
/* C1C54 8012B554 46000021 */  cvt.d.s   $f0, $f0
/* C1C58 8012B558 46280002 */  mul.d     $f0, $f0, $f8
/* C1C5C 8012B55C 00000000 */  nop
/* C1C60 8012B560 3C014018 */  lui       $at, 0x4018
/* C1C64 8012B564 44812800 */  mtc1      $at, $f5
/* C1C68 8012B568 44802000 */  mtc1      $zero, $f4
/* C1C6C 8012B56C 462031A0 */  cvt.s.d   $f6, $f6
/* C1C70 8012B570 460030A1 */  cvt.d.s   $f2, $f6
/* C1C74 8012B574 46281083 */  div.d     $f2, $f2, $f8
/* C1C78 8012B578 46241082 */  mul.d     $f2, $f2, $f4
/* C1C7C 8012B57C 00000000 */  nop
/* C1C80 8012B580 00021403 */  sra       $v0, $v0, 0x10
/* C1C84 8012B584 46200020 */  cvt.s.d   $f0, $f0
/* C1C88 8012B588 E4C00018 */  swc1      $f0, 0x18($a2)
/* C1C8C 8012B58C 46201220 */  cvt.s.d   $f8, $f2
/* C1C90 8012B590 44821000 */  mtc1      $v0, $f2
/* C1C94 8012B594 00000000 */  nop
/* C1C98 8012B598 468010A0 */  cvt.s.w   $f2, $f2
/* C1C9C 8012B59C 00131400 */  sll       $v0, $s3, 0x10
/* C1CA0 8012B5A0 46081081 */  sub.s     $f2, $f2, $f8
/* C1CA4 8012B5A4 00021403 */  sra       $v0, $v0, 0x10
/* C1CA8 8012B5A8 44820000 */  mtc1      $v0, $f0
/* C1CAC 8012B5AC 00000000 */  nop
/* C1CB0 8012B5B0 46800020 */  cvt.s.w   $f0, $f0
/* C1CB4 8012B5B4 46080001 */  sub.s     $f0, $f0, $f8
/* C1CB8 8012B5B8 0804ADC5 */  j         .L8012B714
/* C1CBC 8012B5BC E4C6001C */   swc1     $f6, 0x1c($a2)
.L8012B5C0:
/* C1CC0 8012B5C0 3C048015 */  lui       $a0, %hi(gMessageDrawStatePtr)
/* C1CC4 8012B5C4 8C845D74 */  lw        $a0, %lo(gMessageDrawStatePtr)($a0)
/* C1CC8 8012B5C8 8C820020 */  lw        $v0, 0x20($a0)
/* C1CCC 8012B5CC 8C83004C */  lw        $v1, 0x4c($a0)
/* C1CD0 8012B5D0 00431021 */  addu      $v0, $v0, $v1
/* C1CD4 8012B5D4 90430002 */  lbu       $v1, 2($v0)
/* C1CD8 8012B5D8 240200FB */  addiu     $v0, $zero, 0xfb
/* C1CDC 8012B5DC 14620026 */  bne       $v1, $v0, .L8012B678
/* C1CE0 8012B5E0 24020004 */   addiu    $v0, $zero, 4
/* C1CE4 8012B5E4 93C304F8 */  lbu       $v1, 0x4f8($fp)
/* C1CE8 8012B5E8 14620023 */  bne       $v1, $v0, .L8012B678
/* C1CEC 8012B5EC 00111400 */   sll      $v0, $s1, 0x10
/* C1CF0 8012B5F0 C4860014 */  lwc1      $f6, 0x14($a0)
/* C1CF4 8012B5F4 3C018015 */  lui       $at, %hi(D_80150948)
/* C1CF8 8012B5F8 D4280948 */  ldc1      $f8, %lo(D_80150948)($at)
/* C1CFC 8012B5FC 460031A1 */  cvt.d.s   $f6, $f6
/* C1D00 8012B600 46283182 */  mul.d     $f6, $f6, $f8
/* C1D04 8012B604 00000000 */  nop
/* C1D08 8012B608 C4800010 */  lwc1      $f0, 0x10($a0)
/* C1D0C 8012B60C 46000021 */  cvt.d.s   $f0, $f0
/* C1D10 8012B610 46280002 */  mul.d     $f0, $f0, $f8
/* C1D14 8012B614 00000000 */  nop
/* C1D18 8012B618 3C014008 */  lui       $at, 0x4008
/* C1D1C 8012B61C 44812800 */  mtc1      $at, $f5
/* C1D20 8012B620 44802000 */  mtc1      $zero, $f4
/* C1D24 8012B624 462031A0 */  cvt.s.d   $f6, $f6
/* C1D28 8012B628 460030A1 */  cvt.d.s   $f2, $f6
/* C1D2C 8012B62C 46281083 */  div.d     $f2, $f2, $f8
/* C1D30 8012B630 46241082 */  mul.d     $f2, $f2, $f4
/* C1D34 8012B634 00000000 */  nop
/* C1D38 8012B638 00021403 */  sra       $v0, $v0, 0x10
/* C1D3C 8012B63C 46200020 */  cvt.s.d   $f0, $f0
/* C1D40 8012B640 E4800018 */  swc1      $f0, 0x18($a0)
/* C1D44 8012B644 46201220 */  cvt.s.d   $f8, $f2
/* C1D48 8012B648 44821000 */  mtc1      $v0, $f2
/* C1D4C 8012B64C 00000000 */  nop
/* C1D50 8012B650 468010A0 */  cvt.s.w   $f2, $f2
/* C1D54 8012B654 00131400 */  sll       $v0, $s3, 0x10
/* C1D58 8012B658 46081081 */  sub.s     $f2, $f2, $f8
/* C1D5C 8012B65C 00021403 */  sra       $v0, $v0, 0x10
/* C1D60 8012B660 44820000 */  mtc1      $v0, $f0
/* C1D64 8012B664 00000000 */  nop
/* C1D68 8012B668 46800020 */  cvt.s.w   $f0, $f0
/* C1D6C 8012B66C 46080001 */  sub.s     $f0, $f0, $f8
/* C1D70 8012B670 0804ADC5 */  j         .L8012B714
/* C1D74 8012B674 E486001C */   swc1     $f6, 0x1c($a0)
.L8012B678:
/* C1D78 8012B678 8C820020 */  lw        $v0, 0x20($a0)
/* C1D7C 8012B67C 8C83004C */  lw        $v1, 0x4c($a0)
/* C1D80 8012B680 00431021 */  addu      $v0, $v0, $v1
/* C1D84 8012B684 90430003 */  lbu       $v1, 3($v0)
/* C1D88 8012B688 240200FB */  addiu     $v0, $zero, 0xfb
/* C1D8C 8012B68C 14620153 */  bne       $v1, $v0, .L8012BBDC
/* C1D90 8012B690 24020004 */   addiu    $v0, $zero, 4
/* C1D94 8012B694 93C304F8 */  lbu       $v1, 0x4f8($fp)
/* C1D98 8012B698 14620150 */  bne       $v1, $v0, .L8012BBDC
/* C1D9C 8012B69C 00111400 */   sll      $v0, $s1, 0x10
/* C1DA0 8012B6A0 C4840014 */  lwc1      $f4, 0x14($a0)
/* C1DA4 8012B6A4 3C018015 */  lui       $at, %hi(D_80150950)
/* C1DA8 8012B6A8 D4260950 */  ldc1      $f6, %lo(D_80150950)($at)
/* C1DAC 8012B6AC 46002121 */  cvt.d.s   $f4, $f4
/* C1DB0 8012B6B0 46262102 */  mul.d     $f4, $f4, $f6
/* C1DB4 8012B6B4 00000000 */  nop
/* C1DB8 8012B6B8 C4820010 */  lwc1      $f2, 0x10($a0)
/* C1DBC 8012B6BC 460010A1 */  cvt.d.s   $f2, $f2
/* C1DC0 8012B6C0 46261082 */  mul.d     $f2, $f2, $f6
/* C1DC4 8012B6C4 00000000 */  nop
/* C1DC8 8012B6C8 00021403 */  sra       $v0, $v0, 0x10
/* C1DCC 8012B6CC 46202120 */  cvt.s.d   $f4, $f4
/* C1DD0 8012B6D0 46002021 */  cvt.d.s   $f0, $f4
/* C1DD4 8012B6D4 46260003 */  div.d     $f0, $f0, $f6
/* C1DD8 8012B6D8 462010A0 */  cvt.s.d   $f2, $f2
/* C1DDC 8012B6DC E4820018 */  swc1      $f2, 0x18($a0)
/* C1DE0 8012B6E0 46200000 */  add.d     $f0, $f0, $f0
/* C1DE4 8012B6E4 44821000 */  mtc1      $v0, $f2
/* C1DE8 8012B6E8 00000000 */  nop
/* C1DEC 8012B6EC 468010A0 */  cvt.s.w   $f2, $f2
/* C1DF0 8012B6F0 00131400 */  sll       $v0, $s3, 0x10
/* C1DF4 8012B6F4 46200220 */  cvt.s.d   $f8, $f0
/* C1DF8 8012B6F8 46081081 */  sub.s     $f2, $f2, $f8
/* C1DFC 8012B6FC 00021403 */  sra       $v0, $v0, 0x10
/* C1E00 8012B700 44820000 */  mtc1      $v0, $f0
/* C1E04 8012B704 00000000 */  nop
/* C1E08 8012B708 46800020 */  cvt.s.w   $f0, $f0
/* C1E0C 8012B70C 46080001 */  sub.s     $f0, $f0, $f8
/* C1E10 8012B710 E484001C */  swc1      $f4, 0x1c($a0)
.L8012B714:
/* C1E14 8012B714 4600130D */  trunc.w.s $f12, $f2
/* C1E18 8012B718 44116000 */  mfc1      $s1, $f12
/* C1E1C 8012B71C 4600030D */  trunc.w.s $f12, $f0
/* C1E20 8012B720 44136000 */  mfc1      $s3, $f12
/* C1E24 8012B724 0804AEF7 */  j         .L8012BBDC
/* C1E28 8012B728 00000000 */   nop
.L8012B72C:
/* C1E2C 8012B72C 30621000 */  andi      $v0, $v1, 0x1000
/* C1E30 8012B730 10400060 */  beqz      $v0, .L8012B8B4
/* C1E34 8012B734 30622000 */   andi     $v0, $v1, 0x2000
/* C1E38 8012B738 8CC30020 */  lw        $v1, 0x20($a2)
/* C1E3C 8012B73C 8CC2004C */  lw        $v0, 0x4c($a2)
/* C1E40 8012B740 00621821 */  addu      $v1, $v1, $v0
/* C1E44 8012B744 90650001 */  lbu       $a1, 1($v1)
/* C1E48 8012B748 10A40124 */  beq       $a1, $a0, .L8012BBDC
/* C1E4C 8012B74C 00000000 */   nop
/* C1E50 8012B750 90620002 */  lbu       $v0, 2($v1)
/* C1E54 8012B754 10440121 */  beq       $v0, $a0, .L8012BBDC
/* C1E58 8012B758 00000000 */   nop
/* C1E5C 8012B75C 90620003 */  lbu       $v0, 3($v1)
/* C1E60 8012B760 1044011E */  beq       $v0, $a0, .L8012BBDC
/* C1E64 8012B764 00000000 */   nop
/* C1E68 8012B768 90620004 */  lbu       $v0, 4($v1)
/* C1E6C 8012B76C 1044011B */  beq       $v0, $a0, .L8012BBDC
/* C1E70 8012B770 240200FB */   addiu    $v0, $zero, 0xfb
/* C1E74 8012B774 14A20015 */  bne       $a1, $v0, .L8012B7CC
/* C1E78 8012B778 24020004 */   addiu    $v0, $zero, 4
/* C1E7C 8012B77C 93C304F8 */  lbu       $v1, 0x4f8($fp)
/* C1E80 8012B780 14620012 */  bne       $v1, $v0, .L8012B7CC
/* C1E84 8012B784 00000000 */   nop
/* C1E88 8012B788 C4C00010 */  lwc1      $f0, 0x10($a2)
/* C1E8C 8012B78C 3C018015 */  lui       $at, %hi(D_80150958)
/* C1E90 8012B790 D4240958 */  ldc1      $f4, %lo(D_80150958)($at)
/* C1E94 8012B794 46000021 */  cvt.d.s   $f0, $f0
/* C1E98 8012B798 46240002 */  mul.d     $f0, $f0, $f4
/* C1E9C 8012B79C 00000000 */  nop
/* C1EA0 8012B7A0 C4C20014 */  lwc1      $f2, 0x14($a2)
/* C1EA4 8012B7A4 460010A1 */  cvt.d.s   $f2, $f2
/* C1EA8 8012B7A8 46241082 */  mul.d     $f2, $f2, $f4
/* C1EAC 8012B7AC 00000000 */  nop
/* C1EB0 8012B7B0 26310005 */  addiu     $s1, $s1, 5
/* C1EB4 8012B7B4 26730005 */  addiu     $s3, $s3, 5
/* C1EB8 8012B7B8 46200020 */  cvt.s.d   $f0, $f0
/* C1EBC 8012B7BC 462010A0 */  cvt.s.d   $f2, $f2
/* C1EC0 8012B7C0 E4C00018 */  swc1      $f0, 0x18($a2)
/* C1EC4 8012B7C4 0804AEF7 */  j         .L8012BBDC
/* C1EC8 8012B7C8 E4C2001C */   swc1     $f2, 0x1c($a2)
.L8012B7CC:
/* C1ECC 8012B7CC 3C048015 */  lui       $a0, %hi(gMessageDrawStatePtr)
/* C1ED0 8012B7D0 8C845D74 */  lw        $a0, %lo(gMessageDrawStatePtr)($a0)
/* C1ED4 8012B7D4 8C820020 */  lw        $v0, 0x20($a0)
/* C1ED8 8012B7D8 8C83004C */  lw        $v1, 0x4c($a0)
/* C1EDC 8012B7DC 00431021 */  addu      $v0, $v0, $v1
/* C1EE0 8012B7E0 90430002 */  lbu       $v1, 2($v0)
/* C1EE4 8012B7E4 240200FB */  addiu     $v0, $zero, 0xfb
/* C1EE8 8012B7E8 14620016 */  bne       $v1, $v0, .L8012B844
/* C1EEC 8012B7EC 24020004 */   addiu    $v0, $zero, 4
/* C1EF0 8012B7F0 93C304F8 */  lbu       $v1, 0x4f8($fp)
/* C1EF4 8012B7F4 14620013 */  bne       $v1, $v0, .L8012B844
/* C1EF8 8012B7F8 00000000 */   nop
/* C1EFC 8012B7FC C4820010 */  lwc1      $f2, 0x10($a0)
/* C1F00 8012B800 3C013FE0 */  lui       $at, 0x3fe0
/* C1F04 8012B804 44816800 */  mtc1      $at, $f13
/* C1F08 8012B808 44806000 */  mtc1      $zero, $f12
/* C1F0C 8012B80C 460010A1 */  cvt.d.s   $f2, $f2
/* C1F10 8012B810 462C1082 */  mul.d     $f2, $f2, $f12
/* C1F14 8012B814 00000000 */  nop
/* C1F18 8012B818 C4800014 */  lwc1      $f0, 0x14($a0)
/* C1F1C 8012B81C 46000021 */  cvt.d.s   $f0, $f0
/* C1F20 8012B820 462C0002 */  mul.d     $f0, $f0, $f12
/* C1F24 8012B824 00000000 */  nop
/* C1F28 8012B828 26310003 */  addiu     $s1, $s1, 3
/* C1F2C 8012B82C 26730003 */  addiu     $s3, $s3, 3
/* C1F30 8012B830 462010A0 */  cvt.s.d   $f2, $f2
/* C1F34 8012B834 46200020 */  cvt.s.d   $f0, $f0
/* C1F38 8012B838 E4820018 */  swc1      $f2, 0x18($a0)
/* C1F3C 8012B83C 0804AEF7 */  j         .L8012BBDC
/* C1F40 8012B840 E480001C */   swc1     $f0, 0x1c($a0)
.L8012B844:
/* C1F44 8012B844 8C820020 */  lw        $v0, 0x20($a0)
/* C1F48 8012B848 8C83004C */  lw        $v1, 0x4c($a0)
/* C1F4C 8012B84C 00431021 */  addu      $v0, $v0, $v1
/* C1F50 8012B850 90430003 */  lbu       $v1, 3($v0)
/* C1F54 8012B854 240200FB */  addiu     $v0, $zero, 0xfb
/* C1F58 8012B858 146200E0 */  bne       $v1, $v0, .L8012BBDC
/* C1F5C 8012B85C 24020004 */   addiu    $v0, $zero, 4
/* C1F60 8012B860 93C304F8 */  lbu       $v1, 0x4f8($fp)
/* C1F64 8012B864 146200DD */  bne       $v1, $v0, .L8012BBDC
/* C1F68 8012B868 00000000 */   nop
/* C1F6C 8012B86C C4800010 */  lwc1      $f0, 0x10($a0)
/* C1F70 8012B870 3C013FE8 */  lui       $at, 0x3fe8
/* C1F74 8012B874 44812800 */  mtc1      $at, $f5
/* C1F78 8012B878 44802000 */  mtc1      $zero, $f4
/* C1F7C 8012B87C 46000021 */  cvt.d.s   $f0, $f0
/* C1F80 8012B880 46240002 */  mul.d     $f0, $f0, $f4
/* C1F84 8012B884 00000000 */  nop
/* C1F88 8012B888 C4820014 */  lwc1      $f2, 0x14($a0)
/* C1F8C 8012B88C 460010A1 */  cvt.d.s   $f2, $f2
/* C1F90 8012B890 46241082 */  mul.d     $f2, $f2, $f4
/* C1F94 8012B894 00000000 */  nop
/* C1F98 8012B898 26310002 */  addiu     $s1, $s1, 2
/* C1F9C 8012B89C 26730002 */  addiu     $s3, $s3, 2
/* C1FA0 8012B8A0 46200020 */  cvt.s.d   $f0, $f0
/* C1FA4 8012B8A4 462010A0 */  cvt.s.d   $f2, $f2
/* C1FA8 8012B8A8 E4800018 */  swc1      $f0, 0x18($a0)
/* C1FAC 8012B8AC 0804AEF7 */  j         .L8012BBDC
/* C1FB0 8012B8B0 E482001C */   swc1     $f2, 0x1c($a0)
.L8012B8B4:
/* C1FB4 8012B8B4 10400052 */  beqz      $v0, .L8012BA00
/* C1FB8 8012B8B8 30624000 */   andi     $v0, $v1, 0x4000
/* C1FBC 8012B8BC 0C00A67F */  jal       rand_int
/* C1FC0 8012B8C0 24042710 */   addiu    $a0, $zero, 0x2710
/* C1FC4 8012B8C4 3C03288D */  lui       $v1, 0x288d
/* C1FC8 8012B8C8 3463F0CB */  ori       $v1, $v1, 0xf0cb
/* C1FCC 8012B8CC 00430018 */  mult      $v0, $v1
/* C1FD0 8012B8D0 00021FC3 */  sra       $v1, $v0, 0x1f
/* C1FD4 8012B8D4 3C014059 */  lui       $at, 0x4059
/* C1FD8 8012B8D8 44811800 */  mtc1      $at, $f3
/* C1FDC 8012B8DC 44801000 */  mtc1      $zero, $f2
/* C1FE0 8012B8E0 3C013FE0 */  lui       $at, 0x3fe0
/* C1FE4 8012B8E4 44816800 */  mtc1      $at, $f13
/* C1FE8 8012B8E8 44806000 */  mtc1      $zero, $f12
/* C1FEC 8012B8EC 0000C010 */  mfhi      $t8
/* C1FF0 8012B8F0 00182103 */  sra       $a0, $t8, 4
/* C1FF4 8012B8F4 00832023 */  subu      $a0, $a0, $v1
/* C1FF8 8012B8F8 00041840 */  sll       $v1, $a0, 1
/* C1FFC 8012B8FC 00641821 */  addu      $v1, $v1, $a0
/* C2000 8012B900 000318C0 */  sll       $v1, $v1, 3
/* C2004 8012B904 00641821 */  addu      $v1, $v1, $a0
/* C2008 8012B908 00031880 */  sll       $v1, $v1, 2
/* C200C 8012B90C 00641821 */  addu      $v1, $v1, $a0
/* C2010 8012B910 00431023 */  subu      $v0, $v0, $v1
/* C2014 8012B914 44824000 */  mtc1      $v0, $f8
/* C2018 8012B918 00000000 */  nop
/* C201C 8012B91C 46804220 */  cvt.s.w   $f8, $f8
/* C2020 8012B920 46004021 */  cvt.d.s   $f0, $f8
/* C2024 8012B924 46220003 */  div.d     $f0, $f0, $f2
/* C2028 8012B928 46200220 */  cvt.s.d   $f8, $f0
/* C202C 8012B92C 46004021 */  cvt.d.s   $f0, $f8
/* C2030 8012B930 462C0002 */  mul.d     $f0, $f0, $f12
/* C2034 8012B934 00000000 */  nop
/* C2038 8012B938 3C013FF0 */  lui       $at, 0x3ff0
/* C203C 8012B93C 44816800 */  mtc1      $at, $f13
/* C2040 8012B940 44806000 */  mtc1      $zero, $f12
/* C2044 8012B944 00000000 */  nop
/* C2048 8012B948 462C0000 */  add.d     $f0, $f0, $f12
/* C204C 8012B94C 3C013FD0 */  lui       $at, 0x3fd0
/* C2050 8012B950 44811800 */  mtc1      $at, $f3
/* C2054 8012B954 44801000 */  mtc1      $zero, $f2
/* C2058 8012B958 00000000 */  nop
/* C205C 8012B95C 46220001 */  sub.d     $f0, $f0, $f2
/* C2060 8012B960 46200220 */  cvt.s.d   $f8, $f0
/* C2064 8012B964 460040A1 */  cvt.d.s   $f2, $f8
/* C2068 8012B968 4622603C */  c.lt.d    $f12, $f2
/* C206C 8012B96C 00000000 */  nop
/* C2070 8012B970 4500006D */  bc1f      .L8012BB28
/* C2074 8012B974 00111400 */   sll      $v0, $s1, 0x10
/* C2078 8012B978 3C014020 */  lui       $at, 0x4020
/* C207C 8012B97C 44812800 */  mtc1      $at, $f5
/* C2080 8012B980 44802000 */  mtc1      $zero, $f4
/* C2084 8012B984 00000000 */  nop
/* C2088 8012B988 46241102 */  mul.d     $f4, $f2, $f4
/* C208C 8012B98C 00000000 */  nop
/* C2090 8012B990 3C038015 */  lui       $v1, %hi(gMessageDrawStatePtr)
/* C2094 8012B994 8C635D74 */  lw        $v1, %lo(gMessageDrawStatePtr)($v1)
/* C2098 8012B998 C4600010 */  lwc1      $f0, 0x10($v1)
/* C209C 8012B99C 46080002 */  mul.s     $f0, $f0, $f8
/* C20A0 8012B9A0 00000000 */  nop
/* C20A4 8012B9A4 C4660014 */  lwc1      $f6, 0x14($v1)
/* C20A8 8012B9A8 46083182 */  mul.s     $f6, $f6, $f8
/* C20AC 8012B9AC 00000000 */  nop
/* C20B0 8012B9B0 E4600018 */  swc1      $f0, 0x18($v1)
/* C20B4 8012B9B4 3C014021 */  lui       $at, 0x4021
/* C20B8 8012B9B8 44810800 */  mtc1      $at, $f1
/* C20BC 8012B9BC 44800000 */  mtc1      $zero, $f0
/* C20C0 8012B9C0 00021403 */  sra       $v0, $v0, 0x10
/* C20C4 8012B9C4 46202101 */  sub.d     $f4, $f4, $f0
/* C20C8 8012B9C8 44821000 */  mtc1      $v0, $f2
/* C20CC 8012B9CC 00000000 */  nop
/* C20D0 8012B9D0 468010A1 */  cvt.d.w   $f2, $f2
/* C20D4 8012B9D4 00131400 */  sll       $v0, $s3, 0x10
/* C20D8 8012B9D8 46241081 */  sub.d     $f2, $f2, $f4
/* C20DC 8012B9DC 00021403 */  sra       $v0, $v0, 0x10
/* C20E0 8012B9E0 44820000 */  mtc1      $v0, $f0
/* C20E4 8012B9E4 00000000 */  nop
/* C20E8 8012B9E8 46800021 */  cvt.d.w   $f0, $f0
/* C20EC 8012B9EC 46240001 */  sub.d     $f0, $f0, $f4
/* C20F0 8012B9F0 4620130D */  trunc.w.d $f12, $f2
/* C20F4 8012B9F4 44116000 */  mfc1      $s1, $f12
/* C20F8 8012B9F8 0804AEF5 */  j         .L8012BBD4
/* C20FC 8012B9FC E466001C */   swc1     $f6, 0x1c($v1)
.L8012BA00:
/* C2100 8012BA00 10400076 */  beqz      $v0, .L8012BBDC
/* C2104 8012BA04 3C0516C1 */   lui      $a1, 0x16c1
/* C2108 8012BA08 34A56C17 */  ori       $a1, $a1, 0x6c17
/* C210C 8012BA0C 97C20452 */  lhu       $v0, 0x452($fp)
/* C2110 8012BA10 8CC30030 */  lw        $v1, 0x30($a2)
/* C2114 8012BA14 00022100 */  sll       $a0, $v0, 4
/* C2118 8012BA18 00822023 */  subu      $a0, $a0, $v0
/* C211C 8012BA1C 00031100 */  sll       $v0, $v1, 4
/* C2120 8012BA20 00431023 */  subu      $v0, $v0, $v1
/* C2124 8012BA24 00822023 */  subu      $a0, $a0, $v0
/* C2128 8012BA28 000410C2 */  srl       $v0, $a0, 3
/* C212C 8012BA2C 00450019 */  multu     $v0, $a1
/* C2130 8012BA30 0000C010 */  mfhi      $t8
/* C2134 8012BA34 00181082 */  srl       $v0, $t8, 2
/* C2138 8012BA38 00021840 */  sll       $v1, $v0, 1
/* C213C 8012BA3C 00621821 */  addu      $v1, $v1, $v0
/* C2140 8012BA40 00031100 */  sll       $v0, $v1, 4
/* C2144 8012BA44 00431023 */  subu      $v0, $v0, $v1
/* C2148 8012BA48 000210C0 */  sll       $v0, $v0, 3
/* C214C 8012BA4C 00821023 */  subu      $v0, $a0, $v0
/* C2150 8012BA50 00022400 */  sll       $a0, $v0, 0x10
/* C2154 8012BA54 0C00A4F5 */  jal       cosine
/* C2158 8012BA58 00042403 */   sra      $a0, $a0, 0x10
/* C215C 8012BA5C 3C013FD0 */  lui       $at, 0x3fd0
/* C2160 8012BA60 44811800 */  mtc1      $at, $f3
/* C2164 8012BA64 44801000 */  mtc1      $zero, $f2
/* C2168 8012BA68 46000021 */  cvt.d.s   $f0, $f0
/* C216C 8012BA6C 46220002 */  mul.d     $f0, $f0, $f2
/* C2170 8012BA70 00000000 */  nop
/* C2174 8012BA74 3C013FF0 */  lui       $at, 0x3ff0
/* C2178 8012BA78 44816800 */  mtc1      $at, $f13
/* C217C 8012BA7C 44806000 */  mtc1      $zero, $f12
/* C2180 8012BA80 00000000 */  nop
/* C2184 8012BA84 462C0000 */  add.d     $f0, $f0, $f12
/* C2188 8012BA88 46200220 */  cvt.s.d   $f8, $f0
/* C218C 8012BA8C 460040A1 */  cvt.d.s   $f2, $f8
/* C2190 8012BA90 4622603C */  c.lt.d    $f12, $f2
/* C2194 8012BA94 00000000 */  nop
/* C2198 8012BA98 45000023 */  bc1f      .L8012BB28
/* C219C 8012BA9C 00111400 */   sll      $v0, $s1, 0x10
/* C21A0 8012BAA0 3C014020 */  lui       $at, 0x4020
/* C21A4 8012BAA4 44812800 */  mtc1      $at, $f5
/* C21A8 8012BAA8 44802000 */  mtc1      $zero, $f4
/* C21AC 8012BAAC 00000000 */  nop
/* C21B0 8012BAB0 46241102 */  mul.d     $f4, $f2, $f4
/* C21B4 8012BAB4 00000000 */  nop
/* C21B8 8012BAB8 3C038015 */  lui       $v1, %hi(gMessageDrawStatePtr)
/* C21BC 8012BABC 8C635D74 */  lw        $v1, %lo(gMessageDrawStatePtr)($v1)
/* C21C0 8012BAC0 C4600010 */  lwc1      $f0, 0x10($v1)
/* C21C4 8012BAC4 46080002 */  mul.s     $f0, $f0, $f8
/* C21C8 8012BAC8 00000000 */  nop
/* C21CC 8012BACC C4660014 */  lwc1      $f6, 0x14($v1)
/* C21D0 8012BAD0 46083182 */  mul.s     $f6, $f6, $f8
/* C21D4 8012BAD4 00000000 */  nop
/* C21D8 8012BAD8 E4600018 */  swc1      $f0, 0x18($v1)
/* C21DC 8012BADC 3C014021 */  lui       $at, 0x4021
/* C21E0 8012BAE0 44810800 */  mtc1      $at, $f1
/* C21E4 8012BAE4 44800000 */  mtc1      $zero, $f0
/* C21E8 8012BAE8 00021403 */  sra       $v0, $v0, 0x10
/* C21EC 8012BAEC 46202101 */  sub.d     $f4, $f4, $f0
/* C21F0 8012BAF0 44821000 */  mtc1      $v0, $f2
/* C21F4 8012BAF4 00000000 */  nop
/* C21F8 8012BAF8 468010A1 */  cvt.d.w   $f2, $f2
/* C21FC 8012BAFC 00131400 */  sll       $v0, $s3, 0x10
/* C2200 8012BB00 46241081 */  sub.d     $f2, $f2, $f4
/* C2204 8012BB04 00021403 */  sra       $v0, $v0, 0x10
/* C2208 8012BB08 44820000 */  mtc1      $v0, $f0
/* C220C 8012BB0C 00000000 */  nop
/* C2210 8012BB10 46800021 */  cvt.d.w   $f0, $f0
/* C2214 8012BB14 46240001 */  sub.d     $f0, $f0, $f4
/* C2218 8012BB18 4620130D */  trunc.w.d $f12, $f2
/* C221C 8012BB1C 44116000 */  mfc1      $s1, $f12
/* C2220 8012BB20 0804AEF5 */  j         .L8012BBD4
/* C2224 8012BB24 E466001C */   swc1     $f6, 0x1c($v1)
.L8012BB28:
/* C2228 8012BB28 462C103C */  c.lt.d    $f2, $f12
/* C222C 8012BB2C 00000000 */  nop
/* C2230 8012BB30 4500002A */  bc1f      .L8012BBDC
/* C2234 8012BB34 00111400 */   sll      $v0, $s1, 0x10
/* C2238 8012BB38 3C014030 */  lui       $at, 0x4030
/* C223C 8012BB3C 44810800 */  mtc1      $at, $f1
/* C2240 8012BB40 44800000 */  mtc1      $zero, $f0
/* C2244 8012BB44 00000000 */  nop
/* C2248 8012BB48 46201002 */  mul.d     $f0, $f2, $f0
/* C224C 8012BB4C 00000000 */  nop
/* C2250 8012BB50 3C013FE0 */  lui       $at, 0x3fe0
/* C2254 8012BB54 44816800 */  mtc1      $at, $f13
/* C2258 8012BB58 44806000 */  mtc1      $zero, $f12
/* C225C 8012BB5C 00000000 */  nop
/* C2260 8012BB60 462C0002 */  mul.d     $f0, $f0, $f12
/* C2264 8012BB64 00000000 */  nop
/* C2268 8012BB68 3C038015 */  lui       $v1, %hi(gMessageDrawStatePtr)
/* C226C 8012BB6C 8C635D74 */  lw        $v1, %lo(gMessageDrawStatePtr)($v1)
/* C2270 8012BB70 C4620010 */  lwc1      $f2, 0x10($v1)
/* C2274 8012BB74 46081082 */  mul.s     $f2, $f2, $f8
/* C2278 8012BB78 00000000 */  nop
/* C227C 8012BB7C C4660014 */  lwc1      $f6, 0x14($v1)
/* C2280 8012BB80 46083182 */  mul.s     $f6, $f6, $f8
/* C2284 8012BB84 00000000 */  nop
/* C2288 8012BB88 E4620018 */  swc1      $f2, 0x18($v1)
/* C228C 8012BB8C 3C014020 */  lui       $at, 0x4020
/* C2290 8012BB90 44811800 */  mtc1      $at, $f3
/* C2294 8012BB94 44801000 */  mtc1      $zero, $f2
/* C2298 8012BB98 00021403 */  sra       $v0, $v0, 0x10
/* C229C 8012BB9C 46201081 */  sub.d     $f2, $f2, $f0
/* C22A0 8012BBA0 44822000 */  mtc1      $v0, $f4
/* C22A4 8012BBA4 00000000 */  nop
/* C22A8 8012BBA8 46802121 */  cvt.d.w   $f4, $f4
/* C22AC 8012BBAC 00131400 */  sll       $v0, $s3, 0x10
/* C22B0 8012BBB0 46222100 */  add.d     $f4, $f4, $f2
/* C22B4 8012BBB4 00021403 */  sra       $v0, $v0, 0x10
/* C22B8 8012BBB8 44820000 */  mtc1      $v0, $f0
/* C22BC 8012BBBC 00000000 */  nop
/* C22C0 8012BBC0 46800021 */  cvt.d.w   $f0, $f0
/* C22C4 8012BBC4 46220000 */  add.d     $f0, $f0, $f2
/* C22C8 8012BBC8 E466001C */  swc1      $f6, 0x1c($v1)
/* C22CC 8012BBCC 4620230D */  trunc.w.d $f12, $f4
/* C22D0 8012BBD0 44116000 */  mfc1      $s1, $f12
.L8012BBD4:
/* C22D4 8012BBD4 4620030D */  trunc.w.d $f12, $f0
/* C22D8 8012BBD8 44136000 */  mfc1      $s3, $f12
.L8012BBDC:
/* C22DC 8012BBDC 93C204F8 */  lbu       $v0, 0x4f8($fp)
/* C22E0 8012BBE0 2442FFF5 */  addiu     $v0, $v0, -0xb
/* C22E4 8012BBE4 2C420002 */  sltiu     $v0, $v0, 2
/* C22E8 8012BBE8 10400020 */  beqz      $v0, L8012BC6C_C236C
/* C22EC 8012BBEC 00000000 */   nop
/* C22F0 8012BBF0 93C20508 */  lbu       $v0, 0x508($fp)
/* C22F4 8012BBF4 2442FFFF */  addiu     $v0, $v0, -1
/* C22F8 8012BBF8 2C420004 */  sltiu     $v0, $v0, 4
/* C22FC 8012BBFC 1040001B */  beqz      $v0, L8012BC6C_C236C
/* C2300 8012BC00 00000000 */   nop
/* C2304 8012BC04 97B900A6 */  lhu       $t9, 0xa6($sp)
/* C2308 8012BC08 00191400 */  sll       $v0, $t9, 0x10
/* C230C 8012BC0C 00021C03 */  sra       $v1, $v0, 0x10
/* C2310 8012BC10 2C620026 */  sltiu     $v0, $v1, 0x26
/* C2314 8012BC14 10400013 */  beqz      $v0, L8012BC64_C2364
/* C2318 8012BC18 00031080 */   sll      $v0, $v1, 2
/* C231C 8012BC1C 3C018015 */  lui       $at, %hi(jtbl_80150960)
/* C2320 8012BC20 00220821 */  addu      $at, $at, $v0
/* C2324 8012BC24 8C220960 */  lw        $v0, %lo(jtbl_80150960)($at)
/* C2328 8012BC28 00400008 */  jr        $v0
/* C232C 8012BC2C 00000000 */   nop
glabel L8012BC30_C2330
/* C2330 8012BC30 24180040 */  addiu     $t8, $zero, 0x40
/* C2334 8012BC34 0804AF1B */  j         L8012BC6C_C236C
/* C2338 8012BC38 A7B800A6 */   sh       $t8, 0xa6($sp)
glabel L8012BC3C_C233C
/* C233C 8012BC3C 0804AF1A */  j         .L8012BC68
/* C2340 8012BC40 24190041 */   addiu    $t9, $zero, 0x41
glabel L8012BC44_C2344
/* C2344 8012BC44 24180042 */  addiu     $t8, $zero, 0x42
/* C2348 8012BC48 0804AF1B */  j         L8012BC6C_C236C
/* C234C 8012BC4C A7B800A6 */   sh       $t8, 0xa6($sp)
glabel L8012BC50_C2350
/* C2350 8012BC50 0804AF1A */  j         .L8012BC68
/* C2354 8012BC54 24190043 */   addiu    $t9, $zero, 0x43
glabel L8012BC58_C2358
/* C2358 8012BC58 24180044 */  addiu     $t8, $zero, 0x44
/* C235C 8012BC5C 0804AF1B */  j         L8012BC6C_C236C
/* C2360 8012BC60 A7B800A6 */   sh       $t8, 0xa6($sp)
glabel L8012BC64_C2364
/* C2364 8012BC64 24190040 */  addiu     $t9, $zero, 0x40
.L8012BC68:
/* C2368 8012BC68 A7B900A6 */  sh        $t9, 0xa6($sp)
glabel L8012BC6C_C236C
/* C236C 8012BC6C 97B800A6 */  lhu       $t8, 0xa6($sp)
/* C2370 8012BC70 97B9009E */  lhu       $t9, 0x9e($sp)
/* C2374 8012BC74 00181C00 */  sll       $v1, $t8, 0x10
/* C2378 8012BC78 00191400 */  sll       $v0, $t9, 0x10
/* C237C 8012BC7C 10620007 */  beq       $v1, $v0, .L8012BC9C
/* C2380 8012BC80 00033C03 */   sra      $a3, $v1, 0x10
/* C2384 8012BC84 3C038015 */  lui       $v1, %hi(gMessageDrawStatePtr)
/* C2388 8012BC88 8C635D74 */  lw        $v1, %lo(gMessageDrawStatePtr)($v1)
/* C238C 8012BC8C 94620034 */  lhu       $v0, 0x34($v1)
/* C2390 8012BC90 A7B8009E */  sh        $t8, 0x9e($sp)
/* C2394 8012BC94 34420010 */  ori       $v0, $v0, 0x10
/* C2398 8012BC98 A4620034 */  sh        $v0, 0x34($v1)
.L8012BC9C:
/* C239C 8012BC9C 3C058015 */  lui       $a1, %hi(gMessageDrawStatePtr)
/* C23A0 8012BCA0 8CA55D74 */  lw        $a1, %lo(gMessageDrawStatePtr)($a1)
/* C23A4 8012BCA4 8CA20038 */  lw        $v0, 0x38($a1)
/* C23A8 8012BCA8 30428000 */  andi      $v0, $v0, 0x8000
/* C23AC 8012BCAC 10400047 */  beqz      $v0, .L8012BDCC
/* C23B0 8012BCB0 00121400 */   sll      $v0, $s2, 0x10
/* C23B4 8012BCB4 00021403 */  sra       $v0, $v0, 0x10
/* C23B8 8012BCB8 241900FF */  addiu     $t9, $zero, 0xff
/* C23BC 8012BCBC 14590043 */  bne       $v0, $t9, .L8012BDCC
/* C23C0 8012BCC0 3C10E200 */   lui      $s0, 0xe200
/* C23C4 8012BCC4 3610001C */  ori       $s0, $s0, 0x1c
/* C23C8 8012BCC8 3C060050 */  lui       $a2, 0x50
/* C23CC 8012BCCC 34C64240 */  ori       $a2, $a2, 0x4240
/* C23D0 8012BCD0 3C09FCFF */  lui       $t1, 0xfcff
/* C23D4 8012BCD4 352997FF */  ori       $t1, $t1, 0x97ff
/* C23D8 8012BCD8 3C08FF2D */  lui       $t0, 0xff2d
/* C23DC 8012BCDC 3508FEFF */  ori       $t0, $t0, 0xfeff
/* C23E0 8012BCE0 3C0A2828 */  lui       $t2, 0x2828
/* C23E4 8012BCE4 354A2848 */  ori       $t2, $t2, 0x2848
/* C23E8 8012BCE8 8EE30000 */  lw        $v1, ($s7)
/* C23EC 8012BCEC 03C0202D */  daddu     $a0, $fp, $zero
/* C23F0 8012BCF0 0060102D */  daddu     $v0, $v1, $zero
/* C23F4 8012BCF4 24630008 */  addiu     $v1, $v1, 8
/* C23F8 8012BCF8 3C18E700 */  lui       $t8, 0xe700
/* C23FC 8012BCFC AEE30000 */  sw        $v1, ($s7)
/* C2400 8012BD00 AC580000 */  sw        $t8, ($v0)
/* C2404 8012BD04 AC400004 */  sw        $zero, 4($v0)
/* C2408 8012BD08 24620008 */  addiu     $v0, $v1, 8
/* C240C 8012BD0C AEE20000 */  sw        $v0, ($s7)
/* C2410 8012BD10 24620010 */  addiu     $v0, $v1, 0x10
/* C2414 8012BD14 AC700000 */  sw        $s0, ($v1)
/* C2418 8012BD18 AC660004 */  sw        $a2, 4($v1)
/* C241C 8012BD1C AEE20000 */  sw        $v0, ($s7)
/* C2420 8012BD20 3C02FA00 */  lui       $v0, 0xfa00
/* C2424 8012BD24 AC690008 */  sw        $t1, 8($v1)
/* C2428 8012BD28 AC68000C */  sw        $t0, 0xc($v1)
/* C242C 8012BD2C AC620010 */  sw        $v0, 0x10($v1)
/* C2430 8012BD30 AC6A0014 */  sw        $t2, 0x14($v1)
/* C2434 8012BD34 8CA6004C */  lw        $a2, 0x4c($a1)
/* C2438 8012BD38 8CA20020 */  lw        $v0, 0x20($a1)
/* C243C 8012BD3C 24630018 */  addiu     $v1, $v1, 0x18
/* C2440 8012BD40 AEE30000 */  sw        $v1, ($s7)
/* C2444 8012BD44 00C23021 */  addu      $a2, $a2, $v0
/* C2448 8012BD48 00111400 */  sll       $v0, $s1, 0x10
/* C244C 8012BD4C 00021403 */  sra       $v0, $v0, 0x10
/* C2450 8012BD50 90C60000 */  lbu       $a2, ($a2)
/* C2454 8012BD54 24420002 */  addiu     $v0, $v0, 2
/* C2458 8012BD58 AFA20010 */  sw        $v0, 0x10($sp)
/* C245C 8012BD5C 00131400 */  sll       $v0, $s3, 0x10
/* C2460 8012BD60 00021403 */  sra       $v0, $v0, 0x10
/* C2464 8012BD64 24420002 */  addiu     $v0, $v0, 2
/* C2468 8012BD68 0C04B0C9 */  jal       msg_draw_char
/* C246C 8012BD6C AFA20014 */   sw       $v0, 0x14($sp)
/* C2470 8012BD70 3C040F0A */  lui       $a0, 0xf0a
/* C2474 8012BD74 34847008 */  ori       $a0, $a0, 0x7008
/* C2478 8012BD78 3C06FCFF */  lui       $a2, 0xfcff
/* C247C 8012BD7C 34C6FFFF */  ori       $a2, $a2, 0xffff
/* C2480 8012BD80 3C05FFFC */  lui       $a1, 0xfffc
/* C2484 8012BD84 8EE30000 */  lw        $v1, ($s7)
/* C2488 8012BD88 34A5F279 */  ori       $a1, $a1, 0xf279
/* C248C 8012BD8C 0060102D */  daddu     $v0, $v1, $zero
/* C2490 8012BD90 24630008 */  addiu     $v1, $v1, 8
/* C2494 8012BD94 3C19E700 */  lui       $t9, 0xe700
/* C2498 8012BD98 AEE30000 */  sw        $v1, ($s7)
/* C249C 8012BD9C AC590000 */  sw        $t9, ($v0)
/* C24A0 8012BDA0 AC400004 */  sw        $zero, 4($v0)
/* C24A4 8012BDA4 24620008 */  addiu     $v0, $v1, 8
/* C24A8 8012BDA8 AEE20000 */  sw        $v0, ($s7)
/* C24AC 8012BDAC 24620010 */  addiu     $v0, $v1, 0x10
/* C24B0 8012BDB0 AC700000 */  sw        $s0, ($v1)
/* C24B4 8012BDB4 AC640004 */  sw        $a0, 4($v1)
/* C24B8 8012BDB8 AEE20000 */  sw        $v0, ($s7)
/* C24BC 8012BDBC AC660008 */  sw        $a2, 8($v1)
/* C24C0 8012BDC0 AC65000C */  sw        $a1, 0xc($v1)
/* C24C4 8012BDC4 3C058015 */  lui       $a1, %hi(gMessageDrawStatePtr)
/* C24C8 8012BDC8 8CA55D74 */  lw        $a1, %lo(gMessageDrawStatePtr)($a1)
.L8012BDCC:
/* C24CC 8012BDCC 8CA20038 */  lw        $v0, 0x38($a1)
/* C24D0 8012BDD0 30420020 */  andi      $v0, $v0, 0x20
/* C24D4 8012BDD4 10400036 */  beqz      $v0, .L8012BEB0
/* C24D8 8012BDD8 0000902D */   daddu    $s2, $zero, $zero
/* C24DC 8012BDDC 0011B400 */  sll       $s6, $s1, 0x10
/* C24E0 8012BDE0 0013AC00 */  sll       $s5, $s3, 0x10
/* C24E4 8012BDE4 93B400B8 */  lbu       $s4, 0xb8($sp)
/* C24E8 8012BDE8 3C135555 */  lui       $s3, 0x5555
/* C24EC 8012BDEC 36735556 */  ori       $s3, $s3, 0x5556
/* C24F0 8012BDF0 00168403 */  sra       $s0, $s6, 0x10
.L8012BDF4:
/* C24F4 8012BDF4 24180002 */  addiu     $t8, $zero, 2
/* C24F8 8012BDF8 1298000C */  beq       $s4, $t8, .L8012BE2C
/* C24FC 8012BDFC 00158C03 */   sra      $s1, $s5, 0x10
/* C2500 8012BE00 0C00A67F */  jal       rand_int
/* C2504 8012BE04 24042710 */   addiu    $a0, $zero, 0x2710
/* C2508 8012BE08 00530018 */  mult      $v0, $s3
/* C250C 8012BE0C 2605FFFF */  addiu     $a1, $s0, -1
/* C2510 8012BE10 000227C3 */  sra       $a0, $v0, 0x1f
/* C2514 8012BE14 0000C010 */  mfhi      $t8
/* C2518 8012BE18 03042023 */  subu      $a0, $t8, $a0
/* C251C 8012BE1C 00041840 */  sll       $v1, $a0, 1
/* C2520 8012BE20 00641821 */  addu      $v1, $v1, $a0
/* C2524 8012BE24 00431023 */  subu      $v0, $v0, $v1
/* C2528 8012BE28 00A28021 */  addu      $s0, $a1, $v0
.L8012BE2C:
/* C252C 8012BE2C 24190001 */  addiu     $t9, $zero, 1
/* C2530 8012BE30 1299000D */  beq       $s4, $t9, .L8012BE68
/* C2534 8012BE34 03C0202D */   daddu    $a0, $fp, $zero
/* C2538 8012BE38 0C00A67F */  jal       rand_int
/* C253C 8012BE3C 24042710 */   addiu    $a0, $zero, 0x2710
/* C2540 8012BE40 00530018 */  mult      $v0, $s3
/* C2544 8012BE44 2625FFFF */  addiu     $a1, $s1, -1
/* C2548 8012BE48 000227C3 */  sra       $a0, $v0, 0x1f
/* C254C 8012BE4C 0000C010 */  mfhi      $t8
/* C2550 8012BE50 03042023 */  subu      $a0, $t8, $a0
/* C2554 8012BE54 00041840 */  sll       $v1, $a0, 1
/* C2558 8012BE58 00641821 */  addu      $v1, $v1, $a0
/* C255C 8012BE5C 00431023 */  subu      $v0, $v0, $v1
/* C2560 8012BE60 00A28821 */  addu      $s1, $a1, $v0
/* C2564 8012BE64 03C0202D */  daddu     $a0, $fp, $zero
.L8012BE68:
/* C2568 8012BE68 26520001 */  addiu     $s2, $s2, 1
/* C256C 8012BE6C 3C058015 */  lui       $a1, %hi(gMessageDrawStatePtr)
/* C2570 8012BE70 8CA55D74 */  lw        $a1, %lo(gMessageDrawStatePtr)($a1)
/* C2574 8012BE74 97B900A6 */  lhu       $t9, 0xa6($sp)
/* C2578 8012BE78 8CA2004C */  lw        $v0, 0x4c($a1)
/* C257C 8012BE7C 8CA30020 */  lw        $v1, 0x20($a1)
/* C2580 8012BE80 00193C00 */  sll       $a3, $t9, 0x10
/* C2584 8012BE84 00431021 */  addu      $v0, $v0, $v1
/* C2588 8012BE88 90460000 */  lbu       $a2, ($v0)
/* C258C 8012BE8C 00073C03 */  sra       $a3, $a3, 0x10
/* C2590 8012BE90 AFB00010 */  sw        $s0, 0x10($sp)
/* C2594 8012BE94 0C04B0C9 */  jal       msg_draw_char
/* C2598 8012BE98 AFB10014 */   sw       $s1, 0x14($sp)
/* C259C 8012BE9C 2A420005 */  slti      $v0, $s2, 5
/* C25A0 8012BEA0 1440FFD4 */  bnez      $v0, .L8012BDF4
/* C25A4 8012BEA4 00168403 */   sra      $s0, $s6, 0x10
/* C25A8 8012BEA8 0804AFBB */  j         .L8012BEEC
/* C25AC 8012BEAC 00000000 */   nop
.L8012BEB0:
/* C25B0 8012BEB0 03C0202D */  daddu     $a0, $fp, $zero
/* C25B4 8012BEB4 97B800A6 */  lhu       $t8, 0xa6($sp)
/* C25B8 8012BEB8 8CA3004C */  lw        $v1, 0x4c($a1)
/* C25BC 8012BEBC 8CA20020 */  lw        $v0, 0x20($a1)
/* C25C0 8012BEC0 00183C00 */  sll       $a3, $t8, 0x10
/* C25C4 8012BEC4 00073C03 */  sra       $a3, $a3, 0x10
/* C25C8 8012BEC8 00621821 */  addu      $v1, $v1, $v0
/* C25CC 8012BECC 00111400 */  sll       $v0, $s1, 0x10
/* C25D0 8012BED0 90660000 */  lbu       $a2, ($v1)
/* C25D4 8012BED4 00021403 */  sra       $v0, $v0, 0x10
/* C25D8 8012BED8 AFA20010 */  sw        $v0, 0x10($sp)
/* C25DC 8012BEDC 00131400 */  sll       $v0, $s3, 0x10
/* C25E0 8012BEE0 00021403 */  sra       $v0, $v0, 0x10
/* C25E4 8012BEE4 0C04B0C9 */  jal       msg_draw_char
/* C25E8 8012BEE8 AFA20014 */   sw       $v0, 0x14($sp)
.L8012BEEC:
/* C25EC 8012BEEC 3C048015 */  lui       $a0, %hi(gMessageDrawStatePtr)
/* C25F0 8012BEF0 8C845D74 */  lw        $a0, %lo(gMessageDrawStatePtr)($a0)
/* C25F4 8012BEF4 94830034 */  lhu       $v1, 0x34($a0)
/* C25F8 8012BEF8 30620002 */  andi      $v0, $v1, 2
/* C25FC 8012BEFC 10400002 */  beqz      $v0, .L8012BF08
/* C2600 8012BF00 3062FFFD */   andi     $v0, $v1, 0xfffd
/* C2604 8012BF04 A4820034 */  sh        $v0, 0x34($a0)
.L8012BF08:
/* C2608 8012BF08 3C038015 */  lui       $v1, %hi(gMessageDrawStatePtr)
/* C260C 8012BF0C 8C635D74 */  lw        $v1, %lo(gMessageDrawStatePtr)($v1)
/* C2610 8012BF10 8C620030 */  lw        $v0, 0x30($v1)
/* C2614 8012BF14 8C64004C */  lw        $a0, 0x4c($v1)
/* C2618 8012BF18 8C650020 */  lw        $a1, 0x20($v1)
/* C261C 8012BF1C 9466003E */  lhu       $a2, 0x3e($v1)
/* C2620 8012BF20 24420001 */  addiu     $v0, $v0, 1
/* C2624 8012BF24 00852021 */  addu      $a0, $a0, $a1
/* C2628 8012BF28 AC620030 */  sw        $v0, 0x30($v1)
/* C262C 8012BF2C 90620040 */  lbu       $v0, 0x40($v1)
/* C2630 8012BF30 90840000 */  lbu       $a0, ($a0)
/* C2634 8012BF34 9465003C */  lhu       $a1, 0x3c($v1)
/* C2638 8012BF38 AFA20010 */  sw        $v0, 0x10($sp)
/* C263C 8012BF3C 94620034 */  lhu       $v0, 0x34($v1)
/* C2640 8012BF40 AFA20014 */  sw        $v0, 0x14($sp)
/* C2644 8012BF44 8C670010 */  lw        $a3, 0x10($v1)
.L8012BF48:
/* C2648 8012BF48 0C04977D */  jal       msg_get_draw_char_width
/* C264C 8012BF4C 00000000 */   nop
/* C2650 8012BF50 3C058015 */  lui       $a1, %hi(gMessageDrawStatePtr)
/* C2654 8012BF54 8CA55D74 */  lw        $a1, %lo(gMessageDrawStatePtr)($a1)
/* C2658 8012BF58 94A30042 */  lhu       $v1, 0x42($a1)
/* C265C 8012BF5C 8CA40020 */  lw        $a0, 0x20($a1)
/* C2660 8012BF60 00621821 */  addu      $v1, $v1, $v0
/* C2664 8012BF64 24840001 */  addiu     $a0, $a0, 1
/* C2668 8012BF68 A4A30042 */  sh        $v1, 0x42($a1)
.L8012BF6C:
/* C266C 8012BF6C ACA40020 */  sw        $a0, 0x20($a1)
glabel L8012BF70_C2670
/* C2670 8012BF70 97A20080 */  lhu       $v0, 0x80($sp)
/* C2674 8012BF74 1040EFFE */  beqz      $v0, .L80127F70
/* C2678 8012BF78 00000000 */   nop
/* C267C 8012BF7C 97C2052C */  lhu       $v0, 0x52c($fp)
/* C2680 8012BF80 104000BA */  beqz      $v0, .L8012C26C
/* C2684 8012BF84 0000302D */   daddu    $a2, $zero, $zero
/* C2688 8012BF88 93C2052B */  lbu       $v0, 0x52b($fp)
/* C268C 8012BF8C 93D00531 */  lbu       $s0, 0x531($fp)
/* C2690 8012BF90 93C40530 */  lbu       $a0, 0x530($fp)
/* C2694 8012BF94 00021880 */  sll       $v1, $v0, 2
/* C2698 8012BF98 00621821 */  addu      $v1, $v1, $v0
/* C269C 8012BF9C 3C028015 */  lui       $v0, %hi(gMsgVarImages)
/* C26A0 8012BFA0 8C4212F4 */  lw        $v0, %lo(gMsgVarImages)($v0)
/* C26A4 8012BFA4 00031880 */  sll       $v1, $v1, 2
/* C26A8 8012BFA8 04800078 */  bltz      $a0, .L8012C18C
/* C26AC 8012BFAC 00438821 */   addu     $s1, $v0, $v1
/* C26B0 8012BFB0 28820002 */  slti      $v0, $a0, 2
/* C26B4 8012BFB4 14400005 */  bnez      $v0, .L8012BFCC
/* C26B8 8012BFB8 24020002 */   addiu    $v0, $zero, 2
/* C26BC 8012BFBC 10820050 */  beq       $a0, $v0, .L8012C100
/* C26C0 8012BFC0 00101400 */   sll      $v0, $s0, 0x10
/* C26C4 8012BFC4 0804B064 */  j         .L8012C190
/* C26C8 8012BFC8 00000000 */   nop
.L8012BFCC:
/* C26CC 8012BFCC 54800001 */  bnel      $a0, $zero, .L8012BFD4
/* C26D0 8012BFD0 24060001 */   addiu    $a2, $zero, 1
.L8012BFD4:
/* C26D4 8012BFD4 93C30533 */  lbu       $v1, 0x533($fp)
/* C26D8 8012BFD8 24050001 */  addiu     $a1, $zero, 1
/* C26DC 8012BFDC 1065001E */  beq       $v1, $a1, .L8012C058
/* C26E0 8012BFE0 28620002 */   slti     $v0, $v1, 2
/* C26E4 8012BFE4 10400005 */  beqz      $v0, .L8012BFFC
/* C26E8 8012BFE8 24020002 */   addiu    $v0, $zero, 2
/* C26EC 8012BFEC 10600007 */  beqz      $v1, .L8012C00C
/* C26F0 8012BFF0 00101400 */   sll      $v0, $s0, 0x10
/* C26F4 8012BFF4 0804B064 */  j         .L8012C190
/* C26F8 8012BFF8 00000000 */   nop
.L8012BFFC:
/* C26FC 8012BFFC 10620031 */  beq       $v1, $v0, .L8012C0C4
/* C2700 8012C000 00101400 */   sll      $v0, $s0, 0x10
/* C2704 8012C004 0804B064 */  j         .L8012C190
/* C2708 8012C008 00000000 */   nop
.L8012C00C:
/* C270C 8012C00C 97C30534 */  lhu       $v1, 0x534($fp)
/* C2710 8012C010 93C40532 */  lbu       $a0, 0x532($fp)
/* C2714 8012C014 24630001 */  addiu     $v1, $v1, 1
/* C2718 8012C018 00031400 */  sll       $v0, $v1, 0x10
/* C271C 8012C01C 00021403 */  sra       $v0, $v0, 0x10
/* C2720 8012C020 00440018 */  mult      $v0, $a0
/* C2724 8012C024 A7C30534 */  sh        $v1, 0x534($fp)
/* C2728 8012C028 93C30531 */  lbu       $v1, 0x531($fp)
/* C272C 8012C02C 00001012 */  mflo      $v0
/* C2730 8012C030 0040802D */  daddu     $s0, $v0, $zero
/* C2734 8012C034 00021400 */  sll       $v0, $v0, 0x10
/* C2738 8012C038 00021403 */  sra       $v0, $v0, 0x10
/* C273C 8012C03C 0043102A */  slt       $v0, $v0, $v1
/* C2740 8012C040 14400053 */  bnez      $v0, .L8012C190
/* C2744 8012C044 00101400 */   sll      $v0, $s0, 0x10
/* C2748 8012C048 93D00531 */  lbu       $s0, 0x531($fp)
/* C274C 8012C04C A7C00534 */  sh        $zero, 0x534($fp)
/* C2750 8012C050 0804B063 */  j         .L8012C18C
/* C2754 8012C054 A3C50533 */   sb       $a1, 0x533($fp)
.L8012C058:
/* C2758 8012C058 97B800AE */  lhu       $t8, 0xae($sp)
/* C275C 8012C05C 3C018015 */  lui       $at, %hi(D_801509F8)
/* C2760 8012C060 D42009F8 */  ldc1      $f0, %lo(D_801509F8)($at)
/* C2764 8012C064 00181400 */  sll       $v0, $t8, 0x10
/* C2768 8012C068 00021403 */  sra       $v0, $v0, 0x10
/* C276C 8012C06C 44821000 */  mtc1      $v0, $f2
/* C2770 8012C070 00000000 */  nop
/* C2774 8012C074 468010A0 */  cvt.s.w   $f2, $f2
/* C2778 8012C078 460010A1 */  cvt.d.s   $f2, $f2
/* C277C 8012C07C 93C20531 */  lbu       $v0, 0x531($fp)
/* C2780 8012C080 46201083 */  div.d     $f2, $f2, $f0
/* C2784 8012C084 44820000 */  mtc1      $v0, $f0
/* C2788 8012C088 00000000 */  nop
/* C278C 8012C08C 46800020 */  cvt.s.w   $f0, $f0
/* C2790 8012C090 46000021 */  cvt.d.s   $f0, $f0
/* C2794 8012C094 46201002 */  mul.d     $f0, $f2, $f0
/* C2798 8012C098 00000000 */  nop
/* C279C 8012C09C 3C0141E0 */  lui       $at, 0x41e0
/* C27A0 8012C0A0 44811800 */  mtc1      $at, $f3
/* C27A4 8012C0A4 44801000 */  mtc1      $zero, $f2
/* C27A8 8012C0A8 00000000 */  nop
/* C27AC 8012C0AC 4620103E */  c.le.d    $f2, $f0
/* C27B0 8012C0B0 00000000 */  nop
/* C27B4 8012C0B4 4500002B */  bc1f      .L8012C164
/* C27B8 8012C0B8 00000000 */   nop
/* C27BC 8012C0BC 0804B05D */  j         .L8012C174
/* C27C0 8012C0C0 46220001 */   sub.d    $f0, $f0, $f2
.L8012C0C4:
/* C27C4 8012C0C4 97C30534 */  lhu       $v1, 0x534($fp)
/* C27C8 8012C0C8 93C40532 */  lbu       $a0, 0x532($fp)
/* C27CC 8012C0CC 24630001 */  addiu     $v1, $v1, 1
/* C27D0 8012C0D0 00031400 */  sll       $v0, $v1, 0x10
/* C27D4 8012C0D4 00021403 */  sra       $v0, $v0, 0x10
/* C27D8 8012C0D8 00820018 */  mult      $a0, $v0
/* C27DC 8012C0DC 93C20531 */  lbu       $v0, 0x531($fp)
/* C27E0 8012C0E0 0000C012 */  mflo      $t8
/* C27E4 8012C0E4 00581023 */  subu      $v0, $v0, $t8
/* C27E8 8012C0E8 0040802D */  daddu     $s0, $v0, $zero
/* C27EC 8012C0EC 00021400 */  sll       $v0, $v0, 0x10
/* C27F0 8012C0F0 1C400029 */  bgtz      $v0, .L8012C198
/* C27F4 8012C0F4 A7C30534 */   sh       $v1, 0x534($fp)
/* C27F8 8012C0F8 0804B063 */  j         .L8012C18C
/* C27FC 8012C0FC A7C0052C */   sh       $zero, 0x52c($fp)
.L8012C100:
/* C2800 8012C100 97B900AE */  lhu       $t9, 0xae($sp)
/* C2804 8012C104 3C018015 */  lui       $at, %hi(D_80150A00)
/* C2808 8012C108 D4200A00 */  ldc1      $f0, %lo(D_80150A00)($at)
/* C280C 8012C10C 00191400 */  sll       $v0, $t9, 0x10
/* C2810 8012C110 00021403 */  sra       $v0, $v0, 0x10
/* C2814 8012C114 44821000 */  mtc1      $v0, $f2
/* C2818 8012C118 00000000 */  nop
/* C281C 8012C11C 468010A0 */  cvt.s.w   $f2, $f2
/* C2820 8012C120 460010A1 */  cvt.d.s   $f2, $f2
/* C2824 8012C124 93C20531 */  lbu       $v0, 0x531($fp)
/* C2828 8012C128 46201083 */  div.d     $f2, $f2, $f0
/* C282C 8012C12C 44820000 */  mtc1      $v0, $f0
/* C2830 8012C130 00000000 */  nop
/* C2834 8012C134 46800020 */  cvt.s.w   $f0, $f0
/* C2838 8012C138 46000021 */  cvt.d.s   $f0, $f0
/* C283C 8012C13C 46201002 */  mul.d     $f0, $f2, $f0
/* C2840 8012C140 00000000 */  nop
/* C2844 8012C144 3C0141E0 */  lui       $at, 0x41e0
/* C2848 8012C148 44811800 */  mtc1      $at, $f3
/* C284C 8012C14C 44801000 */  mtc1      $zero, $f2
/* C2850 8012C150 00000000 */  nop
/* C2854 8012C154 4620103E */  c.le.d    $f2, $f0
/* C2858 8012C158 00000000 */  nop
/* C285C 8012C15C 45030005 */  bc1tl     .L8012C174
/* C2860 8012C160 46220001 */   sub.d    $f0, $f0, $f2
.L8012C164:
/* C2864 8012C164 4620030D */  trunc.w.d $f12, $f0
/* C2868 8012C168 44036000 */  mfc1      $v1, $f12
/* C286C 8012C16C 0804B063 */  j         .L8012C18C
/* C2870 8012C170 307000FF */   andi     $s0, $v1, 0xff
.L8012C174:
/* C2874 8012C174 3C028000 */  lui       $v0, 0x8000
/* C2878 8012C178 4620030D */  trunc.w.d $f12, $f0
/* C287C 8012C17C 44036000 */  mfc1      $v1, $f12
/* C2880 8012C180 00000000 */  nop
/* C2884 8012C184 00621825 */  or        $v1, $v1, $v0
/* C2888 8012C188 307000FF */  andi      $s0, $v1, 0xff
.L8012C18C:
/* C288C 8012C18C 00101400 */  sll       $v0, $s0, 0x10
.L8012C190:
/* C2890 8012C190 18400036 */  blez      $v0, .L8012C26C
/* C2894 8012C194 00000000 */   nop
.L8012C198:
/* C2898 8012C198 00C0102D */  daddu     $v0, $a2, $zero
/* C289C 8012C19C 1040001E */  beqz      $v0, .L8012C218
/* C28A0 8012C1A0 0000202D */   daddu    $a0, $zero, $zero
/* C28A4 8012C1A4 97C6052C */  lhu       $a2, 0x52c($fp)
/* C28A8 8012C1A8 97C7052E */  lhu       $a3, 0x52e($fp)
/* C28AC 8012C1AC 2405000F */  addiu     $a1, $zero, 0xf
/* C28B0 8012C1B0 AFA00010 */  sw        $zero, 0x10($sp)
/* C28B4 8012C1B4 96220008 */  lhu       $v0, 8($s1)
/* C28B8 8012C1B8 24C6FFF9 */  addiu     $a2, $a2, -7
/* C28BC 8012C1BC 24E7FFF9 */  addiu     $a3, $a3, -7
/* C28C0 8012C1C0 00451021 */  addu      $v0, $v0, $a1
/* C28C4 8012C1C4 AFA20014 */  sw        $v0, 0x14($sp)
/* C28C8 8012C1C8 9623000A */  lhu       $v1, 0xa($s1)
/* C28CC 8012C1CC 320200FF */  andi      $v0, $s0, 0xff
/* C28D0 8012C1D0 AFA2001C */  sw        $v0, 0x1c($sp)
/* C28D4 8012C1D4 24020140 */  addiu     $v0, $zero, 0x140
/* C28D8 8012C1D8 AFA20044 */  sw        $v0, 0x44($sp)
/* C28DC 8012C1DC 240200F0 */  addiu     $v0, $zero, 0xf0
/* C28E0 8012C1E0 AFA00020 */  sw        $zero, 0x20($sp)
/* C28E4 8012C1E4 AFA00024 */  sw        $zero, 0x24($sp)
/* C28E8 8012C1E8 AFA00028 */  sw        $zero, 0x28($sp)
/* C28EC 8012C1EC AFA0002C */  sw        $zero, 0x2c($sp)
/* C28F0 8012C1F0 AFA00030 */  sw        $zero, 0x30($sp)
/* C28F4 8012C1F4 AFA00034 */  sw        $zero, 0x34($sp)
/* C28F8 8012C1F8 AFA00038 */  sw        $zero, 0x38($sp)
/* C28FC 8012C1FC AFA0003C */  sw        $zero, 0x3c($sp)
/* C2900 8012C200 AFA00040 */  sw        $zero, 0x40($sp)
/* C2904 8012C204 AFA20048 */  sw        $v0, 0x48($sp)
/* C2908 8012C208 AFA0004C */  sw        $zero, 0x4c($sp)
/* C290C 8012C20C 2463000E */  addiu     $v1, $v1, 0xe
/* C2910 8012C210 0C03D4B8 */  jal       draw_box
/* C2914 8012C214 AFA30018 */   sw       $v1, 0x18($sp)
.L8012C218:
/* C2918 8012C218 8E220010 */  lw        $v0, 0x10($s1)
/* C291C 8012C21C 96250008 */  lhu       $a1, 8($s1)
/* C2920 8012C220 9626000A */  lhu       $a2, 0xa($s1)
/* C2924 8012C224 AFA20010 */  sw        $v0, 0x10($sp)
/* C2928 8012C228 8E220004 */  lw        $v0, 4($s1)
/* C292C 8012C22C AFA20014 */  sw        $v0, 0x14($sp)
/* C2930 8012C230 87C2052C */  lh        $v0, 0x52c($fp)
/* C2934 8012C234 AFA20018 */  sw        $v0, 0x18($sp)
/* C2938 8012C238 87C3052E */  lh        $v1, 0x52e($fp)
/* C293C 8012C23C 2402013F */  addiu     $v0, $zero, 0x13f
/* C2940 8012C240 AFA20028 */  sw        $v0, 0x28($sp)
/* C2944 8012C244 240200EF */  addiu     $v0, $zero, 0xef
/* C2948 8012C248 AFA2002C */  sw        $v0, 0x2c($sp)
/* C294C 8012C24C 320200FF */  andi      $v0, $s0, 0xff
/* C2950 8012C250 AFA00020 */  sw        $zero, 0x20($sp)
/* C2954 8012C254 AFA00024 */  sw        $zero, 0x24($sp)
/* C2958 8012C258 AFA20030 */  sw        $v0, 0x30($sp)
/* C295C 8012C25C AFA3001C */  sw        $v1, 0x1c($sp)
/* C2960 8012C260 8E240000 */  lw        $a0, ($s1)
/* C2964 8012C264 0C04BA68 */  jal       draw_ci_image_with_clipping
/* C2968 8012C268 8E27000C */   lw       $a3, 0xc($s1)
.L8012C26C:
/* C296C 8012C26C 3C02800A */  lui       $v0, %hi(gMasterGfxPos)
/* C2970 8012C270 2442A66C */  addiu     $v0, $v0, %lo(gMasterGfxPos)
/* C2974 8012C274 8C430000 */  lw        $v1, ($v0)
/* C2978 8012C278 0060202D */  daddu     $a0, $v1, $zero
/* C297C 8012C27C 24630008 */  addiu     $v1, $v1, 8
/* C2980 8012C280 AC430000 */  sw        $v1, ($v0)
/* C2984 8012C284 3C02E700 */  lui       $v0, 0xe700
/* C2988 8012C288 AC820000 */  sw        $v0, ($a0)
/* C298C 8012C28C AC800004 */  sw        $zero, 4($a0)
/* C2990 8012C290 8FBF010C */  lw        $ra, 0x10c($sp)
/* C2994 8012C294 8FBE0108 */  lw        $fp, 0x108($sp)
/* C2998 8012C298 8FB70104 */  lw        $s7, 0x104($sp)
/* C299C 8012C29C 8FB60100 */  lw        $s6, 0x100($sp)
/* C29A0 8012C2A0 8FB500FC */  lw        $s5, 0xfc($sp)
/* C29A4 8012C2A4 8FB400F8 */  lw        $s4, 0xf8($sp)
/* C29A8 8012C2A8 8FB300F4 */  lw        $s3, 0xf4($sp)
/* C29AC 8012C2AC 8FB200F0 */  lw        $s2, 0xf0($sp)
/* C29B0 8012C2B0 8FB100EC */  lw        $s1, 0xec($sp)
/* C29B4 8012C2B4 8FB000E8 */  lw        $s0, 0xe8($sp)
/* C29B8 8012C2B8 D7BE0138 */  ldc1      $f30, 0x138($sp)
/* C29BC 8012C2BC D7BC0130 */  ldc1      $f28, 0x130($sp)
/* C29C0 8012C2C0 D7BA0128 */  ldc1      $f26, 0x128($sp)
/* C29C4 8012C2C4 D7B80120 */  ldc1      $f24, 0x120($sp)
/* C29C8 8012C2C8 D7B60118 */  ldc1      $f22, 0x118($sp)
/* C29CC 8012C2CC D7B40110 */  ldc1      $f20, 0x110($sp)
/* C29D0 8012C2D0 3C018015 */  lui       $at, %hi(D_80151338)
/* C29D4 8012C2D4 AC231338 */  sw        $v1, %lo(D_80151338)($at)
/* C29D8 8012C2D8 03E00008 */  jr        $ra
/* C29DC 8012C2DC 27BD0140 */   addiu    $sp, $sp, 0x140
