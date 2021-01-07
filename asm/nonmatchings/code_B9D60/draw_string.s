.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel draw_string
/* BCBEC 801264EC 27BDFA58 */  addiu     $sp, $sp, -0x5a8
/* BCBF0 801264F0 8FA205BC */  lw        $v0, 0x5bc($sp)
/* BCBF4 801264F4 AFB7059C */  sw        $s7, 0x59c($sp)
/* BCBF8 801264F8 8FB705B8 */  lw        $s7, 0x5b8($sp)
/* BCBFC 801264FC AFB00580 */  sw        $s0, 0x580($sp)
/* BCC00 80126500 0080802D */  daddu     $s0, $a0, $zero
/* BCC04 80126504 AFBE05A0 */  sw        $fp, 0x5a0($sp)
/* BCC08 80126508 00E0F02D */  daddu     $fp, $a3, $zero
/* BCC0C 8012650C AFB60598 */  sw        $s6, 0x598($sp)
/* BCC10 80126510 0000B02D */  daddu     $s6, $zero, $zero
/* BCC14 80126514 AFB20588 */  sw        $s2, 0x588($sp)
/* BCC18 80126518 02C0902D */  daddu     $s2, $s6, $zero
/* BCC1C 8012651C AFB40590 */  sw        $s4, 0x590($sp)
/* BCC20 80126520 0000A02D */  daddu     $s4, $zero, $zero
/* BCC24 80126524 AFB3058C */  sw        $s3, 0x58c($sp)
/* BCC28 80126528 0280982D */  daddu     $s3, $s4, $zero
/* BCC2C 8012652C AFBF05A4 */  sw        $ra, 0x5a4($sp)
/* BCC30 80126530 AFB50594 */  sw        $s5, 0x594($sp)
/* BCC34 80126534 AFB10584 */  sw        $s1, 0x584($sp)
/* BCC38 80126538 AFA505AC */  sw        $a1, 0x5ac($sp)
/* BCC3C 8012653C AFA605B0 */  sw        $a2, 0x5b0($sp)
/* BCC40 80126540 12000087 */  beqz      $s0, .L80126760
/* BCC44 80126544 0040A82D */   daddu    $s5, $v0, $zero
/* BCC48 80126548 30420001 */  andi      $v0, $v0, 1
/* BCC4C 8012654C 10400003 */  beqz      $v0, .L8012655C
/* BCC50 80126550 2BC200FF */   slti     $v0, $fp, 0xff
/* BCC54 80126554 24160002 */  addiu     $s6, $zero, 2
/* BCC58 80126558 24130001 */  addiu     $s3, $zero, 1
.L8012655C:
/* BCC5C 8012655C 54400001 */  bnel      $v0, $zero, .L80126564
/* BCC60 80126560 36D60001 */   ori      $s6, $s6, 1
.L80126564:
/* BCC64 80126564 27B10020 */  addiu     $s1, $sp, 0x20
/* BCC68 80126568 0220202D */  daddu     $a0, $s1, $zero
/* BCC6C 8012656C 24050001 */  addiu     $a1, $zero, 1
/* BCC70 80126570 0C0495A9 */  jal       initialize_printer
/* BCC74 80126574 0000302D */   daddu    $a2, $zero, $zero
/* BCC78 80126578 06010003 */  bgez      $s0, .L80126588
/* BCC7C 8012657C 00000000 */   nop      
/* BCC80 80126580 08049975 */  j         .L801265D4
/* BCC84 80126584 AFB00020 */   sw       $s0, 0x20($sp)
.L80126588:
/* BCC88 80126588 0C00AB0A */  jal       general_heap_malloc
/* BCC8C 8012658C 24040400 */   addiu    $a0, $zero, 0x400
/* BCC90 80126590 0040A02D */  daddu     $s4, $v0, $zero
/* BCC94 80126594 0200202D */  daddu     $a0, $s0, $zero
/* BCC98 80126598 0C049601 */  jal       dma_load_string
/* BCC9C 8012659C 0280282D */   daddu    $a1, $s4, $zero
/* BCCA0 801265A0 0000282D */  daddu     $a1, $zero, $zero
/* BCCA4 801265A4 27B00578 */  addiu     $s0, $sp, 0x578
/* BCCA8 801265A8 0200302D */  daddu     $a2, $s0, $zero
/* BCCAC 801265AC AFB40020 */  sw        $s4, 0x20($sp)
/* BCCB0 801265B0 AFA00010 */  sw        $zero, 0x10($sp)
/* BCCB4 801265B4 AFA00014 */  sw        $zero, 0x14($sp)
/* BCCB8 801265B8 AFA00018 */  sw        $zero, 0x18($sp)
/* BCCBC 801265BC AFB3001C */  sw        $s3, 0x1c($sp)
/* BCCC0 801265C0 0280202D */  daddu     $a0, $s4, $zero
/* BCCC4 801265C4 0C0497DA */  jal       get_string_properties
/* BCCC8 801265C8 00A0382D */   daddu    $a3, $a1, $zero
/* BCCCC 801265CC 96020002 */  lhu       $v0, 2($s0)
/* BCCD0 801265D0 A7A20558 */  sh        $v0, 0x558($sp)
.L801265D4:
/* BCCD4 801265D4 06E00011 */  bltz      $s7, .L8012661C
/* BCCD8 801265D8 26450001 */   addiu    $a1, $s2, 1
/* BCCDC 801265DC 24A40001 */  addiu     $a0, $a1, 1
/* BCCE0 801265E0 3242FFFF */  andi      $v0, $s2, 0xffff
/* BCCE4 801265E4 02221021 */  addu      $v0, $s1, $v0
/* BCCE8 801265E8 240300FF */  addiu     $v1, $zero, 0xff
/* BCCEC 801265EC A0430010 */  sb        $v1, 0x10($v0)
/* BCCF0 801265F0 30A2FFFF */  andi      $v0, $a1, 0xffff
/* BCCF4 801265F4 02221021 */  addu      $v0, $s1, $v0
/* BCCF8 801265F8 24030004 */  addiu     $v1, $zero, 4
/* BCCFC 801265FC 3084FFFF */  andi      $a0, $a0, 0xffff
/* BCD00 80126600 02242021 */  addu      $a0, $s1, $a0
/* BCD04 80126604 A0430010 */  sb        $v1, 0x10($v0)
/* BCD08 80126608 A0970010 */  sb        $s7, 0x10($a0)
/* BCD0C 8012660C 96220004 */  lhu       $v0, 4($s1)
/* BCD10 80126610 24B20002 */  addiu     $s2, $a1, 2
/* BCD14 80126614 24420003 */  addiu     $v0, $v0, 3
/* BCD18 80126618 A6220004 */  sh        $v0, 4($s1)
.L8012661C:
/* BCD1C 8012661C 32A20002 */  andi      $v0, $s5, 2
/* BCD20 80126620 10400012 */  beqz      $v0, .L8012666C
/* BCD24 80126624 26450001 */   addiu    $a1, $s2, 1
/* BCD28 80126628 24A40001 */  addiu     $a0, $a1, 1
/* BCD2C 8012662C 3242FFFF */  andi      $v0, $s2, 0xffff
/* BCD30 80126630 02221021 */  addu      $v0, $s1, $v0
/* BCD34 80126634 240300FF */  addiu     $v1, $zero, 0xff
/* BCD38 80126638 A0430010 */  sb        $v1, 0x10($v0)
/* BCD3C 8012663C 30A2FFFF */  andi      $v0, $a1, 0xffff
/* BCD40 80126640 02221021 */  addu      $v0, $s1, $v0
/* BCD44 80126644 2403001C */  addiu     $v1, $zero, 0x1c
/* BCD48 80126648 3084FFFF */  andi      $a0, $a0, 0xffff
/* BCD4C 8012664C 02242021 */  addu      $a0, $s1, $a0
/* BCD50 80126650 A0430010 */  sb        $v1, 0x10($v0)
/* BCD54 80126654 24020008 */  addiu     $v0, $zero, 8
/* BCD58 80126658 A0820010 */  sb        $v0, 0x10($a0)
/* BCD5C 8012665C 96220004 */  lhu       $v0, 4($s1)
/* BCD60 80126660 24B20002 */  addiu     $s2, $a1, 2
/* BCD64 80126664 24420003 */  addiu     $v0, $v0, 3
/* BCD68 80126668 A6220004 */  sh        $v0, 4($s1)
.L8012666C:
/* BCD6C 8012666C 32A20004 */  andi      $v0, $s5, 4
/* BCD70 80126670 10400012 */  beqz      $v0, .L801266BC
/* BCD74 80126674 26450001 */   addiu    $a1, $s2, 1
/* BCD78 80126678 24A40001 */  addiu     $a0, $a1, 1
/* BCD7C 8012667C 3242FFFF */  andi      $v0, $s2, 0xffff
/* BCD80 80126680 02221021 */  addu      $v0, $s1, $v0
/* BCD84 80126684 240300FF */  addiu     $v1, $zero, 0xff
/* BCD88 80126688 A0430010 */  sb        $v1, 0x10($v0)
/* BCD8C 8012668C 30A2FFFF */  andi      $v0, $a1, 0xffff
/* BCD90 80126690 02221021 */  addu      $v0, $s1, $v0
/* BCD94 80126694 2403001C */  addiu     $v1, $zero, 0x1c
/* BCD98 80126698 3084FFFF */  andi      $a0, $a0, 0xffff
/* BCD9C 8012669C 02242021 */  addu      $a0, $s1, $a0
/* BCDA0 801266A0 A0430010 */  sb        $v1, 0x10($v0)
/* BCDA4 801266A4 24020009 */  addiu     $v0, $zero, 9
/* BCDA8 801266A8 A0820010 */  sb        $v0, 0x10($a0)
/* BCDAC 801266AC 96220004 */  lhu       $v0, 4($s1)
/* BCDB0 801266B0 24B20002 */  addiu     $s2, $a1, 2
/* BCDB4 801266B4 24420003 */  addiu     $v0, $v0, 3
/* BCDB8 801266B8 A6220004 */  sh        $v0, 4($s1)
.L801266BC:
/* BCDBC 801266BC 32A20008 */  andi      $v0, $s5, 8
/* BCDC0 801266C0 10400011 */  beqz      $v0, .L80126708
/* BCDC4 801266C4 26440001 */   addiu    $a0, $s2, 1
/* BCDC8 801266C8 24850001 */  addiu     $a1, $a0, 1
/* BCDCC 801266CC 3242FFFF */  andi      $v0, $s2, 0xffff
/* BCDD0 801266D0 02221021 */  addu      $v0, $s1, $v0
/* BCDD4 801266D4 240300FF */  addiu     $v1, $zero, 0xff
/* BCDD8 801266D8 3084FFFF */  andi      $a0, $a0, 0xffff
/* BCDDC 801266DC 02242021 */  addu      $a0, $s1, $a0
/* BCDE0 801266E0 A0430010 */  sb        $v1, 0x10($v0)
/* BCDE4 801266E4 2402001C */  addiu     $v0, $zero, 0x1c
/* BCDE8 801266E8 30A5FFFF */  andi      $a1, $a1, 0xffff
/* BCDEC 801266EC 02252821 */  addu      $a1, $s1, $a1
/* BCDF0 801266F0 A0820010 */  sb        $v0, 0x10($a0)
/* BCDF4 801266F4 2402000E */  addiu     $v0, $zero, 0xe
/* BCDF8 801266F8 A0A20010 */  sb        $v0, 0x10($a1)
/* BCDFC 801266FC 96220004 */  lhu       $v0, 4($s1)
/* BCE00 80126700 24420003 */  addiu     $v0, $v0, 3
/* BCE04 80126704 A6220004 */  sh        $v0, 4($s1)
.L80126708:
/* BCE08 80126708 0220202D */  daddu     $a0, $s1, $zero
/* BCE0C 8012670C 24052710 */  addiu     $a1, $zero, 0x2710
/* BCE10 80126710 0C04915C */  jal       func_80124570
/* BCE14 80126714 24060001 */   addiu    $a2, $zero, 1
/* BCE18 80126718 0220202D */  daddu     $a0, $s1, $zero
/* BCE1C 8012671C 0000382D */  daddu     $a3, $zero, $zero
/* BCE20 80126720 8FA805AC */  lw        $t0, 0x5ac($sp)
/* BCE24 80126724 32C2FFFF */  andi      $v0, $s6, 0xffff
/* BCE28 80126728 AFA20014 */  sw        $v0, 0x14($sp)
/* BCE2C 8012672C 33C200FF */  andi      $v0, $fp, 0xff
/* BCE30 80126730 AFA00010 */  sw        $zero, 0x10($sp)
/* BCE34 80126734 AFA20018 */  sw        $v0, 0x18($sp)
/* BCE38 80126738 00082C00 */  sll       $a1, $t0, 0x10
/* BCE3C 8012673C 8FA805B0 */  lw        $t0, 0x5b0($sp)
/* BCE40 80126740 00052C03 */  sra       $a1, $a1, 0x10
/* BCE44 80126744 00083400 */  sll       $a2, $t0, 0x10
/* BCE48 80126748 0C049F64 */  jal       func_80127D90
/* BCE4C 8012674C 00063403 */   sra      $a2, $a2, 0x10
/* BCE50 80126750 12800003 */  beqz      $s4, .L80126760
/* BCE54 80126754 00000000 */   nop      
/* BCE58 80126758 0C00AB1E */  jal       general_heap_free
/* BCE5C 8012675C 0280202D */   daddu    $a0, $s4, $zero
.L80126760:
/* BCE60 80126760 8FBF05A4 */  lw        $ra, 0x5a4($sp)
/* BCE64 80126764 8FBE05A0 */  lw        $fp, 0x5a0($sp)
/* BCE68 80126768 8FB7059C */  lw        $s7, 0x59c($sp)
/* BCE6C 8012676C 8FB60598 */  lw        $s6, 0x598($sp)
/* BCE70 80126770 8FB50594 */  lw        $s5, 0x594($sp)
/* BCE74 80126774 8FB40590 */  lw        $s4, 0x590($sp)
/* BCE78 80126778 8FB3058C */  lw        $s3, 0x58c($sp)
/* BCE7C 8012677C 8FB20588 */  lw        $s2, 0x588($sp)
/* BCE80 80126780 8FB10584 */  lw        $s1, 0x584($sp)
/* BCE84 80126784 8FB00580 */  lw        $s0, 0x580($sp)
/* BCE88 80126788 03E00008 */  jr        $ra
/* BCE8C 8012678C 27BD05A8 */   addiu    $sp, $sp, 0x5a8
