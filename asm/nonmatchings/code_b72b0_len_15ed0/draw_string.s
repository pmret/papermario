.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel draw_string
/* 0BCBEC 801264EC 27BDFA58 */  addiu $sp, $sp, -0x5a8
/* 0BCBF0 801264F0 8FA205BC */  lw    $v0, 0x5bc($sp)
/* 0BCBF4 801264F4 AFB7059C */  sw    $s7, 0x59c($sp)
/* 0BCBF8 801264F8 8FB705B8 */  lw    $s7, 0x5b8($sp)
/* 0BCBFC 801264FC AFB00580 */  sw    $s0, 0x580($sp)
/* 0BCC00 80126500 0080802D */  daddu $s0, $a0, $zero
/* 0BCC04 80126504 AFBE05A0 */  sw    $fp, 0x5a0($sp)
/* 0BCC08 80126508 00E0F02D */  daddu $fp, $a3, $zero
/* 0BCC0C 8012650C AFB60598 */  sw    $s6, 0x598($sp)
/* 0BCC10 80126510 0000B02D */  daddu $s6, $zero, $zero
/* 0BCC14 80126514 AFB20588 */  sw    $s2, 0x588($sp)
/* 0BCC18 80126518 02C0902D */  daddu $s2, $s6, $zero
/* 0BCC1C 8012651C AFB40590 */  sw    $s4, 0x590($sp)
/* 0BCC20 80126520 0000A02D */  daddu $s4, $zero, $zero
/* 0BCC24 80126524 AFB3058C */  sw    $s3, 0x58c($sp)
/* 0BCC28 80126528 0280982D */  daddu $s3, $s4, $zero
/* 0BCC2C 8012652C AFBF05A4 */  sw    $ra, 0x5a4($sp)
/* 0BCC30 80126530 AFB50594 */  sw    $s5, 0x594($sp)
/* 0BCC34 80126534 AFB10584 */  sw    $s1, 0x584($sp)
/* 0BCC38 80126538 AFA505AC */  sw    $a1, 0x5ac($sp)
/* 0BCC3C 8012653C AFA605B0 */  sw    $a2, 0x5b0($sp)
/* 0BCC40 80126540 12000087 */  beqz  $s0, .L80126760
/* 0BCC44 80126544 0040A82D */   daddu $s5, $v0, $zero
/* 0BCC48 80126548 30420001 */  andi  $v0, $v0, 1
/* 0BCC4C 8012654C 10400003 */  beqz  $v0, .L8012655C
/* 0BCC50 80126550 2BC200FF */   slti  $v0, $fp, 0xff
/* 0BCC54 80126554 24160002 */  addiu $s6, $zero, 2
/* 0BCC58 80126558 24130001 */  addiu $s3, $zero, 1
.L8012655C:
/* 0BCC5C 8012655C 54400001 */  bnel  $v0, $zero, .L80126564
/* 0BCC60 80126560 36D60001 */   ori   $s6, $s6, 1
.L80126564:
/* 0BCC64 80126564 27B10020 */  addiu $s1, $sp, 0x20
/* 0BCC68 80126568 0220202D */  daddu $a0, $s1, $zero
/* 0BCC6C 8012656C 24050001 */  addiu $a1, $zero, 1
/* 0BCC70 80126570 0C0495A9 */  jal   initialize_printer
/* 0BCC74 80126574 0000302D */   daddu $a2, $zero, $zero
/* 0BCC78 80126578 06010003 */  bgez  $s0, .L80126588
/* 0BCC7C 8012657C 00000000 */   nop   
/* 0BCC80 80126580 08049975 */  j     .L801265D4
/* 0BCC84 80126584 AFB00020 */   sw    $s0, 0x20($sp)

.L80126588:
/* 0BCC88 80126588 0C00AB0A */  jal   general_heap_malloc
/* 0BCC8C 8012658C 24040400 */   addiu $a0, $zero, 0x400
/* 0BCC90 80126590 0040A02D */  daddu $s4, $v0, $zero
/* 0BCC94 80126594 0200202D */  daddu $a0, $s0, $zero
/* 0BCC98 80126598 0C049601 */  jal   dma_load_string
/* 0BCC9C 8012659C 0280282D */   daddu $a1, $s4, $zero
/* 0BCCA0 801265A0 0000282D */  daddu $a1, $zero, $zero
/* 0BCCA4 801265A4 27B00578 */  addiu $s0, $sp, 0x578
/* 0BCCA8 801265A8 0200302D */  daddu $a2, $s0, $zero
/* 0BCCAC 801265AC AFB40020 */  sw    $s4, 0x20($sp)
/* 0BCCB0 801265B0 AFA00010 */  sw    $zero, 0x10($sp)
/* 0BCCB4 801265B4 AFA00014 */  sw    $zero, 0x14($sp)
/* 0BCCB8 801265B8 AFA00018 */  sw    $zero, 0x18($sp)
/* 0BCCBC 801265BC AFB3001C */  sw    $s3, 0x1c($sp)
/* 0BCCC0 801265C0 0280202D */  daddu $a0, $s4, $zero
/* 0BCCC4 801265C4 0C0497DA */  jal   get_string_properties
/* 0BCCC8 801265C8 00A0382D */   daddu $a3, $a1, $zero
/* 0BCCCC 801265CC 96020002 */  lhu   $v0, 2($s0)
/* 0BCCD0 801265D0 A7A20558 */  sh    $v0, 0x558($sp)
.L801265D4:
/* 0BCCD4 801265D4 06E00011 */  bltz  $s7, .L8012661C
/* 0BCCD8 801265D8 26450001 */   addiu $a1, $s2, 1
/* 0BCCDC 801265DC 24A40001 */  addiu $a0, $a1, 1
/* 0BCCE0 801265E0 3242FFFF */  andi  $v0, $s2, 0xffff
/* 0BCCE4 801265E4 02221021 */  addu  $v0, $s1, $v0
/* 0BCCE8 801265E8 240300FF */  addiu $v1, $zero, 0xff
/* 0BCCEC 801265EC A0430010 */  sb    $v1, 0x10($v0)
/* 0BCCF0 801265F0 30A2FFFF */  andi  $v0, $a1, 0xffff
/* 0BCCF4 801265F4 02221021 */  addu  $v0, $s1, $v0
/* 0BCCF8 801265F8 24030004 */  addiu $v1, $zero, 4
/* 0BCCFC 801265FC 3084FFFF */  andi  $a0, $a0, 0xffff
/* 0BCD00 80126600 02242021 */  addu  $a0, $s1, $a0
/* 0BCD04 80126604 A0430010 */  sb    $v1, 0x10($v0)
/* 0BCD08 80126608 A0970010 */  sb    $s7, 0x10($a0)
/* 0BCD0C 8012660C 96220004 */  lhu   $v0, 4($s1)
/* 0BCD10 80126610 24B20002 */  addiu $s2, $a1, 2
/* 0BCD14 80126614 24420003 */  addiu $v0, $v0, 3
/* 0BCD18 80126618 A6220004 */  sh    $v0, 4($s1)
.L8012661C:
/* 0BCD1C 8012661C 32A20002 */  andi  $v0, $s5, 2
/* 0BCD20 80126620 10400012 */  beqz  $v0, .L8012666C
/* 0BCD24 80126624 26450001 */   addiu $a1, $s2, 1
/* 0BCD28 80126628 24A40001 */  addiu $a0, $a1, 1
/* 0BCD2C 8012662C 3242FFFF */  andi  $v0, $s2, 0xffff
/* 0BCD30 80126630 02221021 */  addu  $v0, $s1, $v0
/* 0BCD34 80126634 240300FF */  addiu $v1, $zero, 0xff
/* 0BCD38 80126638 A0430010 */  sb    $v1, 0x10($v0)
/* 0BCD3C 8012663C 30A2FFFF */  andi  $v0, $a1, 0xffff
/* 0BCD40 80126640 02221021 */  addu  $v0, $s1, $v0
/* 0BCD44 80126644 2403001C */  addiu $v1, $zero, 0x1c
/* 0BCD48 80126648 3084FFFF */  andi  $a0, $a0, 0xffff
/* 0BCD4C 8012664C 02242021 */  addu  $a0, $s1, $a0
/* 0BCD50 80126650 A0430010 */  sb    $v1, 0x10($v0)
/* 0BCD54 80126654 24020008 */  addiu $v0, $zero, 8
/* 0BCD58 80126658 A0820010 */  sb    $v0, 0x10($a0)
/* 0BCD5C 8012665C 96220004 */  lhu   $v0, 4($s1)
/* 0BCD60 80126660 24B20002 */  addiu $s2, $a1, 2
/* 0BCD64 80126664 24420003 */  addiu $v0, $v0, 3
/* 0BCD68 80126668 A6220004 */  sh    $v0, 4($s1)
.L8012666C:
/* 0BCD6C 8012666C 32A20004 */  andi  $v0, $s5, 4
/* 0BCD70 80126670 10400012 */  beqz  $v0, .L801266BC
/* 0BCD74 80126674 26450001 */   addiu $a1, $s2, 1
/* 0BCD78 80126678 24A40001 */  addiu $a0, $a1, 1
/* 0BCD7C 8012667C 3242FFFF */  andi  $v0, $s2, 0xffff
/* 0BCD80 80126680 02221021 */  addu  $v0, $s1, $v0
/* 0BCD84 80126684 240300FF */  addiu $v1, $zero, 0xff
/* 0BCD88 80126688 A0430010 */  sb    $v1, 0x10($v0)
/* 0BCD8C 8012668C 30A2FFFF */  andi  $v0, $a1, 0xffff
/* 0BCD90 80126690 02221021 */  addu  $v0, $s1, $v0
/* 0BCD94 80126694 2403001C */  addiu $v1, $zero, 0x1c
/* 0BCD98 80126698 3084FFFF */  andi  $a0, $a0, 0xffff
/* 0BCD9C 8012669C 02242021 */  addu  $a0, $s1, $a0
/* 0BCDA0 801266A0 A0430010 */  sb    $v1, 0x10($v0)
/* 0BCDA4 801266A4 24020009 */  addiu $v0, $zero, 9
/* 0BCDA8 801266A8 A0820010 */  sb    $v0, 0x10($a0)
/* 0BCDAC 801266AC 96220004 */  lhu   $v0, 4($s1)
/* 0BCDB0 801266B0 24B20002 */  addiu $s2, $a1, 2
/* 0BCDB4 801266B4 24420003 */  addiu $v0, $v0, 3
/* 0BCDB8 801266B8 A6220004 */  sh    $v0, 4($s1)
.L801266BC:
/* 0BCDBC 801266BC 32A20008 */  andi  $v0, $s5, 8
/* 0BCDC0 801266C0 10400011 */  beqz  $v0, .L80126708
/* 0BCDC4 801266C4 26440001 */   addiu $a0, $s2, 1
/* 0BCDC8 801266C8 24850001 */  addiu $a1, $a0, 1
/* 0BCDCC 801266CC 3242FFFF */  andi  $v0, $s2, 0xffff
/* 0BCDD0 801266D0 02221021 */  addu  $v0, $s1, $v0
/* 0BCDD4 801266D4 240300FF */  addiu $v1, $zero, 0xff
/* 0BCDD8 801266D8 3084FFFF */  andi  $a0, $a0, 0xffff
/* 0BCDDC 801266DC 02242021 */  addu  $a0, $s1, $a0
/* 0BCDE0 801266E0 A0430010 */  sb    $v1, 0x10($v0)
/* 0BCDE4 801266E4 2402001C */  addiu $v0, $zero, 0x1c
/* 0BCDE8 801266E8 30A5FFFF */  andi  $a1, $a1, 0xffff
/* 0BCDEC 801266EC 02252821 */  addu  $a1, $s1, $a1
/* 0BCDF0 801266F0 A0820010 */  sb    $v0, 0x10($a0)
/* 0BCDF4 801266F4 2402000E */  addiu $v0, $zero, 0xe
/* 0BCDF8 801266F8 A0A20010 */  sb    $v0, 0x10($a1)
/* 0BCDFC 801266FC 96220004 */  lhu   $v0, 4($s1)
/* 0BCE00 80126700 24420003 */  addiu $v0, $v0, 3
/* 0BCE04 80126704 A6220004 */  sh    $v0, 4($s1)
.L80126708:
/* 0BCE08 80126708 0220202D */  daddu $a0, $s1, $zero
/* 0BCE0C 8012670C 24052710 */  addiu $a1, $zero, 0x2710
/* 0BCE10 80126710 0C04915C */  jal   func_80124570
/* 0BCE14 80126714 24060001 */   addiu $a2, $zero, 1
/* 0BCE18 80126718 0220202D */  daddu $a0, $s1, $zero
/* 0BCE1C 8012671C 0000382D */  daddu $a3, $zero, $zero
/* 0BCE20 80126720 8FA805AC */  lw    $t0, 0x5ac($sp)
/* 0BCE24 80126724 32C2FFFF */  andi  $v0, $s6, 0xffff
/* 0BCE28 80126728 AFA20014 */  sw    $v0, 0x14($sp)
/* 0BCE2C 8012672C 33C200FF */  andi  $v0, $fp, 0xff
/* 0BCE30 80126730 AFA00010 */  sw    $zero, 0x10($sp)
/* 0BCE34 80126734 AFA20018 */  sw    $v0, 0x18($sp)
/* 0BCE38 80126738 00082C00 */  sll   $a1, $t0, 0x10
/* 0BCE3C 8012673C 8FA805B0 */  lw    $t0, 0x5b0($sp)
/* 0BCE40 80126740 00052C03 */  sra   $a1, $a1, 0x10
/* 0BCE44 80126744 00083400 */  sll   $a2, $t0, 0x10
/* 0BCE48 80126748 0C049F64 */  jal   func_80127D90
/* 0BCE4C 8012674C 00063403 */   sra   $a2, $a2, 0x10
/* 0BCE50 80126750 12800003 */  beqz  $s4, .L80126760
/* 0BCE54 80126754 00000000 */   nop   
/* 0BCE58 80126758 0C00AB1E */  jal   general_heap_free
/* 0BCE5C 8012675C 0280202D */   daddu $a0, $s4, $zero
.L80126760:
/* 0BCE60 80126760 8FBF05A4 */  lw    $ra, 0x5a4($sp)
/* 0BCE64 80126764 8FBE05A0 */  lw    $fp, 0x5a0($sp)
/* 0BCE68 80126768 8FB7059C */  lw    $s7, 0x59c($sp)
/* 0BCE6C 8012676C 8FB60598 */  lw    $s6, 0x598($sp)
/* 0BCE70 80126770 8FB50594 */  lw    $s5, 0x594($sp)
/* 0BCE74 80126774 8FB40590 */  lw    $s4, 0x590($sp)
/* 0BCE78 80126778 8FB3058C */  lw    $s3, 0x58c($sp)
/* 0BCE7C 8012677C 8FB20588 */  lw    $s2, 0x588($sp)
/* 0BCE80 80126780 8FB10584 */  lw    $s1, 0x584($sp)
/* 0BCE84 80126784 8FB00580 */  lw    $s0, 0x580($sp)
/* 0BCE88 80126788 03E00008 */  jr    $ra
/* 0BCE8C 8012678C 27BD05A8 */   addiu $sp, $sp, 0x5a8

