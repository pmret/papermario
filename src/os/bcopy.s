.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .text, "ax"

glabel bcopy
/* 3FA50 80064650 10C0001B */  beqz      $a2, .L800646C0
/* 3FA54 80064654 00A03821 */   addu     $a3, $a1, $zero
/* 3FA58 80064658 10850019 */  beq       $a0, $a1, .L800646C0
/* 3FA5C 8006465C 00000000 */   nop
/* 3FA60 80064660 00A4082A */  slt       $at, $a1, $a0
/* 3FA64 80064664 14200007 */  bnez      $at, .L80064684
/* 3FA68 80064668 00000000 */   nop
/* 3FA6C 8006466C 00861020 */  add       $v0, $a0, $a2
/* 3FA70 80064670 00A2082A */  slt       $at, $a1, $v0
/* 3FA74 80064674 10200003 */  beqz      $at, .L80064684
/* 3FA78 80064678 00000000 */   nop
/* 3FA7C 8006467C 1000005C */  b         .L800647F0
/* 3FA80 80064680 00000000 */   nop
.L80064684:
/* 3FA84 80064684 28C10010 */  slti      $at, $a2, 0x10
/* 3FA88 80064688 14200005 */  bnez      $at, .L800646A0
/* 3FA8C 8006468C 00000000 */   nop
/* 3FA90 80064690 30820003 */  andi      $v0, $a0, 3
/* 3FA94 80064694 30A30003 */  andi      $v1, $a1, 3
/* 3FA98 80064698 1043000B */  beq       $v0, $v1, .L800646C8
/* 3FA9C 8006469C 00000000 */   nop
.L800646A0:
/* 3FAA0 800646A0 10C00007 */  beqz      $a2, .L800646C0
/* 3FAA4 800646A4 00000000 */   nop
/* 3FAA8 800646A8 00861821 */  addu      $v1, $a0, $a2
.L800646AC:
/* 3FAAC 800646AC 80820000 */  lb        $v0, ($a0)
/* 3FAB0 800646B0 24840001 */  addiu     $a0, $a0, 1
/* 3FAB4 800646B4 A0A20000 */  sb        $v0, ($a1)
/* 3FAB8 800646B8 1483FFFC */  bne       $a0, $v1, .L800646AC
/* 3FABC 800646BC 24A50001 */   addiu    $a1, $a1, 1
.L800646C0:
/* 3FAC0 800646C0 03E00008 */  jr        $ra
/* 3FAC4 800646C4 00E01021 */   addu     $v0, $a3, $zero
.L800646C8:
/* 3FAC8 800646C8 1040001A */  beqz      $v0, .L80064734
/* 3FACC 800646CC 00000000 */   nop
/* 3FAD0 800646D0 24010001 */  addiu     $at, $zero, 1
/* 3FAD4 800646D4 10410010 */  beq       $v0, $at, .L80064718
/* 3FAD8 800646D8 00000000 */   nop
/* 3FADC 800646DC 24010002 */  addiu     $at, $zero, 2
/* 3FAE0 800646E0 10410007 */  beq       $v0, $at, .L80064700
/* 3FAE4 800646E4 00000000 */   nop
/* 3FAE8 800646E8 80820000 */  lb        $v0, ($a0)
/* 3FAEC 800646EC 24840001 */  addiu     $a0, $a0, 1
/* 3FAF0 800646F0 A0A20000 */  sb        $v0, ($a1)
/* 3FAF4 800646F4 24A50001 */  addiu     $a1, $a1, 1
/* 3FAF8 800646F8 1000000E */  b         .L80064734
/* 3FAFC 800646FC 24C6FFFF */   addiu    $a2, $a2, -1
.L80064700:
/* 3FB00 80064700 84820000 */  lh        $v0, ($a0)
/* 3FB04 80064704 24840002 */  addiu     $a0, $a0, 2
/* 3FB08 80064708 A4A20000 */  sh        $v0, ($a1)
/* 3FB0C 8006470C 24A50002 */  addiu     $a1, $a1, 2
/* 3FB10 80064710 10000008 */  b         .L80064734
/* 3FB14 80064714 24C6FFFE */   addiu    $a2, $a2, -2
.L80064718:
/* 3FB18 80064718 80820000 */  lb        $v0, ($a0)
/* 3FB1C 8006471C 84830001 */  lh        $v1, 1($a0)
/* 3FB20 80064720 24840003 */  addiu     $a0, $a0, 3
/* 3FB24 80064724 A0A20000 */  sb        $v0, ($a1)
/* 3FB28 80064728 A4A30001 */  sh        $v1, 1($a1)
/* 3FB2C 8006472C 24A50003 */  addiu     $a1, $a1, 3
/* 3FB30 80064730 24C6FFFD */  addiu     $a2, $a2, -3
.L80064734:
/* 3FB34 80064734 28C10020 */  slti      $at, $a2, 0x20
/* 3FB38 80064738 14200015 */  bnez      $at, .L80064790
/* 3FB3C 8006473C 00000000 */   nop
/* 3FB40 80064740 8C820000 */  lw        $v0, ($a0)
/* 3FB44 80064744 8C830004 */  lw        $v1, 4($a0)
/* 3FB48 80064748 8C880008 */  lw        $t0, 8($a0)
/* 3FB4C 8006474C 8C89000C */  lw        $t1, 0xc($a0)
/* 3FB50 80064750 8C8A0010 */  lw        $t2, 0x10($a0)
/* 3FB54 80064754 8C8B0014 */  lw        $t3, 0x14($a0)
/* 3FB58 80064758 8C8C0018 */  lw        $t4, 0x18($a0)
/* 3FB5C 8006475C 8C8D001C */  lw        $t5, 0x1c($a0)
/* 3FB60 80064760 24840020 */  addiu     $a0, $a0, 0x20
/* 3FB64 80064764 ACA20000 */  sw        $v0, ($a1)
/* 3FB68 80064768 ACA30004 */  sw        $v1, 4($a1)
/* 3FB6C 8006476C ACA80008 */  sw        $t0, 8($a1)
/* 3FB70 80064770 ACA9000C */  sw        $t1, 0xc($a1)
/* 3FB74 80064774 ACAA0010 */  sw        $t2, 0x10($a1)
/* 3FB78 80064778 ACAB0014 */  sw        $t3, 0x14($a1)
/* 3FB7C 8006477C ACAC0018 */  sw        $t4, 0x18($a1)
/* 3FB80 80064780 ACAD001C */  sw        $t5, 0x1c($a1)
/* 3FB84 80064784 24A50020 */  addiu     $a1, $a1, 0x20
/* 3FB88 80064788 1000FFEA */  b         .L80064734
/* 3FB8C 8006478C 24C6FFE0 */   addiu    $a2, $a2, -0x20
.L80064790:
/* 3FB90 80064790 28C10010 */  slti      $at, $a2, 0x10
/* 3FB94 80064794 1420000D */  bnez      $at, .L800647CC
/* 3FB98 80064798 00000000 */   nop
/* 3FB9C 8006479C 8C820000 */  lw        $v0, ($a0)
/* 3FBA0 800647A0 8C830004 */  lw        $v1, 4($a0)
/* 3FBA4 800647A4 8C880008 */  lw        $t0, 8($a0)
/* 3FBA8 800647A8 8C89000C */  lw        $t1, 0xc($a0)
/* 3FBAC 800647AC 24840010 */  addiu     $a0, $a0, 0x10
/* 3FBB0 800647B0 ACA20000 */  sw        $v0, ($a1)
/* 3FBB4 800647B4 ACA30004 */  sw        $v1, 4($a1)
/* 3FBB8 800647B8 ACA80008 */  sw        $t0, 8($a1)
/* 3FBBC 800647BC ACA9000C */  sw        $t1, 0xc($a1)
/* 3FBC0 800647C0 24A50010 */  addiu     $a1, $a1, 0x10
/* 3FBC4 800647C4 1000FFF2 */  b         .L80064790
/* 3FBC8 800647C8 24C6FFF0 */   addiu    $a2, $a2, -0x10
.L800647CC:
/* 3FBCC 800647CC 28C10004 */  slti      $at, $a2, 4
/* 3FBD0 800647D0 1420FFB3 */  bnez      $at, .L800646A0
/* 3FBD4 800647D4 00000000 */   nop
/* 3FBD8 800647D8 8C820000 */  lw        $v0, ($a0)
/* 3FBDC 800647DC 24840004 */  addiu     $a0, $a0, 4
/* 3FBE0 800647E0 ACA20000 */  sw        $v0, ($a1)
/* 3FBE4 800647E4 24A50004 */  addiu     $a1, $a1, 4
/* 3FBE8 800647E8 1000FFF8 */  b         .L800647CC
/* 3FBEC 800647EC 24C6FFFC */   addiu    $a2, $a2, -4
.L800647F0:
/* 3FBF0 800647F0 00862020 */  add       $a0, $a0, $a2
/* 3FBF4 800647F4 00A62820 */  add       $a1, $a1, $a2
/* 3FBF8 800647F8 28C10010 */  slti      $at, $a2, 0x10
/* 3FBFC 800647FC 14200005 */  bnez      $at, .L80064814
/* 3FC00 80064800 00000000 */   nop
/* 3FC04 80064804 30820003 */  andi      $v0, $a0, 3
/* 3FC08 80064808 30A30003 */  andi      $v1, $a1, 3
/* 3FC0C 8006480C 1043000D */  beq       $v0, $v1, .L80064844
/* 3FC10 80064810 00000000 */   nop
.L80064814:
/* 3FC14 80064814 10C0FFAA */  beqz      $a2, .L800646C0
/* 3FC18 80064818 00000000 */   nop
/* 3FC1C 8006481C 2484FFFF */  addiu     $a0, $a0, -1
/* 3FC20 80064820 24A5FFFF */  addiu     $a1, $a1, -1
/* 3FC24 80064824 00861823 */  subu      $v1, $a0, $a2
.L80064828:
/* 3FC28 80064828 80820000 */  lb        $v0, ($a0)
/* 3FC2C 8006482C 2484FFFF */  addiu     $a0, $a0, -1
/* 3FC30 80064830 A0A20000 */  sb        $v0, ($a1)
/* 3FC34 80064834 1483FFFC */  bne       $a0, $v1, .L80064828
/* 3FC38 80064838 24A5FFFF */   addiu    $a1, $a1, -1
/* 3FC3C 8006483C 03E00008 */  jr        $ra
/* 3FC40 80064840 00E01021 */   addu     $v0, $a3, $zero
.L80064844:
/* 3FC44 80064844 1040001A */  beqz      $v0, .L800648B0
/* 3FC48 80064848 00000000 */   nop
/* 3FC4C 8006484C 24010003 */  addiu     $at, $zero, 3
/* 3FC50 80064850 10410010 */  beq       $v0, $at, .L80064894
/* 3FC54 80064854 00000000 */   nop
/* 3FC58 80064858 24010002 */  addiu     $at, $zero, 2
/* 3FC5C 8006485C 10410007 */  beq       $v0, $at, .L8006487C
/* 3FC60 80064860 00000000 */   nop
/* 3FC64 80064864 8082FFFF */  lb        $v0, -1($a0)
/* 3FC68 80064868 2484FFFF */  addiu     $a0, $a0, -1
/* 3FC6C 8006486C A0A2FFFF */  sb        $v0, -1($a1)
/* 3FC70 80064870 24A5FFFF */  addiu     $a1, $a1, -1
/* 3FC74 80064874 1000000E */  b         .L800648B0
/* 3FC78 80064878 24C6FFFF */   addiu    $a2, $a2, -1
.L8006487C:
/* 3FC7C 8006487C 8482FFFE */  lh        $v0, -2($a0)
/* 3FC80 80064880 2484FFFE */  addiu     $a0, $a0, -2
/* 3FC84 80064884 A4A2FFFE */  sh        $v0, -2($a1)
/* 3FC88 80064888 24A5FFFE */  addiu     $a1, $a1, -2
/* 3FC8C 8006488C 10000008 */  b         .L800648B0
/* 3FC90 80064890 24C6FFFE */   addiu    $a2, $a2, -2
.L80064894:
/* 3FC94 80064894 8082FFFF */  lb        $v0, -1($a0)
/* 3FC98 80064898 8483FFFD */  lh        $v1, -3($a0)
/* 3FC9C 8006489C 2484FFFD */  addiu     $a0, $a0, -3
/* 3FCA0 800648A0 A0A2FFFF */  sb        $v0, -1($a1)
/* 3FCA4 800648A4 A4A3FFFD */  sh        $v1, -3($a1)
/* 3FCA8 800648A8 24A5FFFD */  addiu     $a1, $a1, -3
/* 3FCAC 800648AC 24C6FFFD */  addiu     $a2, $a2, -3
.L800648B0:
/* 3FCB0 800648B0 28C10020 */  slti      $at, $a2, 0x20
/* 3FCB4 800648B4 14200015 */  bnez      $at, .L8006490C
/* 3FCB8 800648B8 00000000 */   nop
/* 3FCBC 800648BC 8C82FFFC */  lw        $v0, -4($a0)
/* 3FCC0 800648C0 8C83FFF8 */  lw        $v1, -8($a0)
/* 3FCC4 800648C4 8C88FFF4 */  lw        $t0, -0xc($a0)
/* 3FCC8 800648C8 8C89FFF0 */  lw        $t1, -0x10($a0)
/* 3FCCC 800648CC 8C8AFFEC */  lw        $t2, -0x14($a0)
/* 3FCD0 800648D0 8C8BFFE8 */  lw        $t3, -0x18($a0)
/* 3FCD4 800648D4 8C8CFFE4 */  lw        $t4, -0x1c($a0)
/* 3FCD8 800648D8 8C8DFFE0 */  lw        $t5, -0x20($a0)
/* 3FCDC 800648DC 2484FFE0 */  addiu     $a0, $a0, -0x20
/* 3FCE0 800648E0 ACA2FFFC */  sw        $v0, -4($a1)
/* 3FCE4 800648E4 ACA3FFF8 */  sw        $v1, -8($a1)
/* 3FCE8 800648E8 ACA8FFF4 */  sw        $t0, -0xc($a1)
/* 3FCEC 800648EC ACA9FFF0 */  sw        $t1, -0x10($a1)
/* 3FCF0 800648F0 ACAAFFEC */  sw        $t2, -0x14($a1)
/* 3FCF4 800648F4 ACABFFE8 */  sw        $t3, -0x18($a1)
/* 3FCF8 800648F8 ACACFFE4 */  sw        $t4, -0x1c($a1)
/* 3FCFC 800648FC ACADFFE0 */  sw        $t5, -0x20($a1)
/* 3FD00 80064900 24A5FFE0 */  addiu     $a1, $a1, -0x20
/* 3FD04 80064904 1000FFEA */  b         .L800648B0
/* 3FD08 80064908 24C6FFE0 */   addiu    $a2, $a2, -0x20
.L8006490C:
/* 3FD0C 8006490C 28C10010 */  slti      $at, $a2, 0x10
/* 3FD10 80064910 1420000D */  bnez      $at, .L80064948
/* 3FD14 80064914 00000000 */   nop
/* 3FD18 80064918 8C82FFFC */  lw        $v0, -4($a0)
/* 3FD1C 8006491C 8C83FFF8 */  lw        $v1, -8($a0)
/* 3FD20 80064920 8C88FFF4 */  lw        $t0, -0xc($a0)
/* 3FD24 80064924 8C89FFF0 */  lw        $t1, -0x10($a0)
/* 3FD28 80064928 2484FFF0 */  addiu     $a0, $a0, -0x10
/* 3FD2C 8006492C ACA2FFFC */  sw        $v0, -4($a1)
/* 3FD30 80064930 ACA3FFF8 */  sw        $v1, -8($a1)
/* 3FD34 80064934 ACA8FFF4 */  sw        $t0, -0xc($a1)
/* 3FD38 80064938 ACA9FFF0 */  sw        $t1, -0x10($a1)
/* 3FD3C 8006493C 24A5FFF0 */  addiu     $a1, $a1, -0x10
/* 3FD40 80064940 1000FFF2 */  b         .L8006490C
/* 3FD44 80064944 24C6FFF0 */   addiu    $a2, $a2, -0x10
.L80064948:
/* 3FD48 80064948 28C10004 */  slti      $at, $a2, 4
/* 3FD4C 8006494C 1420FFB1 */  bnez      $at, .L80064814
/* 3FD50 80064950 00000000 */   nop
/* 3FD54 80064954 8C82FFFC */  lw        $v0, -4($a0)
/* 3FD58 80064958 2484FFFC */  addiu     $a0, $a0, -4
/* 3FD5C 8006495C ACA2FFFC */  sw        $v0, -4($a1)
/* 3FD60 80064960 24A5FFFC */  addiu     $a1, $a1, -4
/* 3FD64 80064964 1000FFF8 */  b         .L80064948
/* 3FD68 80064968 24C6FFFC */   addiu    $a2, $a2, -4
/* 3FD6C 8006496C 00000000 */  nop
