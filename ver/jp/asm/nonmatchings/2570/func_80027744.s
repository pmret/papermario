.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80027744
/* 2B44 80027744 27BDFF90 */  addiu     $sp, $sp, -0x70
/* 2B48 80027748 AFB40058 */  sw        $s4, 0x58($sp)
/* 2B4C 8002774C 0080A02D */  daddu     $s4, $a0, $zero
/* 2B50 80027750 AFB5005C */  sw        $s5, 0x5c($sp)
/* 2B54 80027754 00A0A82D */  daddu     $s5, $a1, $zero
/* 2B58 80027758 AFB30054 */  sw        $s3, 0x54($sp)
/* 2B5C 8002775C 24130001 */  addiu     $s3, $zero, 1
/* 2B60 80027760 27A80018 */  addiu     $t0, $sp, 0x18
/* 2B64 80027764 AFA80040 */  sw        $t0, 0x40($sp)
/* 2B68 80027768 24080140 */  addiu     $t0, $zero, 0x140
/* 2B6C 8002776C AFBF006C */  sw        $ra, 0x6c($sp)
/* 2B70 80027770 AFBE0068 */  sw        $fp, 0x68($sp)
/* 2B74 80027774 AFB70064 */  sw        $s7, 0x64($sp)
/* 2B78 80027778 AFB60060 */  sw        $s6, 0x60($sp)
/* 2B7C 8002777C AFB20050 */  sw        $s2, 0x50($sp)
/* 2B80 80027780 AFB1004C */  sw        $s1, 0x4c($sp)
/* 2B84 80027784 AFB00048 */  sw        $s0, 0x48($sp)
/* 2B88 80027788 AFA60078 */  sw        $a2, 0x78($sp)
/* 2B8C 8002778C AFA80044 */  sw        $t0, 0x44($sp)
.L80027790:
/* 2B90 80027790 24120001 */  addiu     $s2, $zero, 1
/* 2B94 80027794 267EFFFF */  addiu     $fp, $s3, -1
/* 2B98 80027798 8FA80044 */  lw        $t0, 0x44($sp)
/* 2B9C 8002779C 0272B821 */  addu      $s7, $s3, $s2
/* 2BA0 800277A0 0112B021 */  addu      $s6, $t0, $s2
/* 2BA4 800277A4 00161840 */  sll       $v1, $s6, 1
.L800277A8:
/* 2BA8 800277A8 00752021 */  addu      $a0, $v1, $s5
/* 2BAC 800277AC 9482FFFE */  lhu       $v0, -2($a0)
/* 2BB0 800277B0 00021082 */  srl       $v0, $v0, 2
/* 2BB4 800277B4 3042000F */  andi      $v0, $v0, 0xf
/* 2BB8 800277B8 2C420008 */  sltiu     $v0, $v0, 8
/* 2BBC 800277BC 5440000D */  bnel      $v0, $zero, .L800277F4
/* 2BC0 800277C0 0280202D */   daddu    $a0, $s4, $zero
/* 2BC4 800277C4 94820000 */  lhu       $v0, ($a0)
/* 2BC8 800277C8 00021082 */  srl       $v0, $v0, 2
/* 2BCC 800277CC 3042000F */  andi      $v0, $v0, 0xf
/* 2BD0 800277D0 2C420008 */  sltiu     $v0, $v0, 8
/* 2BD4 800277D4 54400007 */  bnel      $v0, $zero, .L800277F4
/* 2BD8 800277D8 0280202D */   daddu    $a0, $s4, $zero
/* 2BDC 800277DC 94820002 */  lhu       $v0, 2($a0)
/* 2BE0 800277E0 00021082 */  srl       $v0, $v0, 2
/* 2BE4 800277E4 3042000F */  andi      $v0, $v0, 0xf
/* 2BE8 800277E8 2C420008 */  sltiu     $v0, $v0, 8
/* 2BEC 800277EC 10400048 */  beqz      $v0, .L80027910
/* 2BF0 800277F0 0280202D */   daddu    $a0, $s4, $zero
.L800277F4:
/* 2BF4 800277F4 02A0282D */  daddu     $a1, $s5, $zero
/* 2BF8 800277F8 03C0302D */  daddu     $a2, $fp, $zero
/* 2BFC 800277FC 2650FFFF */  addiu     $s0, $s2, -1
/* 2C00 80027800 8FA80040 */  lw        $t0, 0x40($sp)
/* 2C04 80027804 0200382D */  daddu     $a3, $s0, $zero
/* 2C08 80027808 0C009C73 */  jal       func_800271CC
/* 2C0C 8002780C AFA80010 */   sw       $t0, 0x10($sp)
/* 2C10 80027810 0280202D */  daddu     $a0, $s4, $zero
/* 2C14 80027814 02A0282D */  daddu     $a1, $s5, $zero
/* 2C18 80027818 03C0302D */  daddu     $a2, $fp, $zero
/* 2C1C 8002781C 0240382D */  daddu     $a3, $s2, $zero
/* 2C20 80027820 27A2001C */  addiu     $v0, $sp, 0x1c
/* 2C24 80027824 0C009C73 */  jal       func_800271CC
/* 2C28 80027828 AFA20010 */   sw       $v0, 0x10($sp)
/* 2C2C 8002782C 0280202D */  daddu     $a0, $s4, $zero
/* 2C30 80027830 02A0282D */  daddu     $a1, $s5, $zero
/* 2C34 80027834 03C0302D */  daddu     $a2, $fp, $zero
/* 2C38 80027838 26510001 */  addiu     $s1, $s2, 1
/* 2C3C 8002783C 0220382D */  daddu     $a3, $s1, $zero
/* 2C40 80027840 27A20020 */  addiu     $v0, $sp, 0x20
/* 2C44 80027844 0C009C73 */  jal       func_800271CC
/* 2C48 80027848 AFA20010 */   sw       $v0, 0x10($sp)
/* 2C4C 8002784C 0280202D */  daddu     $a0, $s4, $zero
/* 2C50 80027850 02A0282D */  daddu     $a1, $s5, $zero
/* 2C54 80027854 0260302D */  daddu     $a2, $s3, $zero
/* 2C58 80027858 0200382D */  daddu     $a3, $s0, $zero
/* 2C5C 8002785C 27A20024 */  addiu     $v0, $sp, 0x24
/* 2C60 80027860 0C009C73 */  jal       func_800271CC
/* 2C64 80027864 AFA20010 */   sw       $v0, 0x10($sp)
/* 2C68 80027868 0280202D */  daddu     $a0, $s4, $zero
/* 2C6C 8002786C 02A0282D */  daddu     $a1, $s5, $zero
/* 2C70 80027870 0260302D */  daddu     $a2, $s3, $zero
/* 2C74 80027874 0240382D */  daddu     $a3, $s2, $zero
/* 2C78 80027878 27A20028 */  addiu     $v0, $sp, 0x28
/* 2C7C 8002787C 0C009C73 */  jal       func_800271CC
/* 2C80 80027880 AFA20010 */   sw       $v0, 0x10($sp)
/* 2C84 80027884 0280202D */  daddu     $a0, $s4, $zero
/* 2C88 80027888 02A0282D */  daddu     $a1, $s5, $zero
/* 2C8C 8002788C 0260302D */  daddu     $a2, $s3, $zero
/* 2C90 80027890 0220382D */  daddu     $a3, $s1, $zero
/* 2C94 80027894 27A2002C */  addiu     $v0, $sp, 0x2c
/* 2C98 80027898 0C009C73 */  jal       func_800271CC
/* 2C9C 8002789C AFA20010 */   sw       $v0, 0x10($sp)
/* 2CA0 800278A0 0280202D */  daddu     $a0, $s4, $zero
/* 2CA4 800278A4 02A0282D */  daddu     $a1, $s5, $zero
/* 2CA8 800278A8 02E0302D */  daddu     $a2, $s7, $zero
/* 2CAC 800278AC 0200382D */  daddu     $a3, $s0, $zero
/* 2CB0 800278B0 27A20030 */  addiu     $v0, $sp, 0x30
/* 2CB4 800278B4 0C009C73 */  jal       func_800271CC
/* 2CB8 800278B8 AFA20010 */   sw       $v0, 0x10($sp)
/* 2CBC 800278BC 0280202D */  daddu     $a0, $s4, $zero
/* 2CC0 800278C0 02A0282D */  daddu     $a1, $s5, $zero
/* 2CC4 800278C4 02E0302D */  daddu     $a2, $s7, $zero
/* 2CC8 800278C8 0240382D */  daddu     $a3, $s2, $zero
/* 2CCC 800278CC 27A20034 */  addiu     $v0, $sp, 0x34
/* 2CD0 800278D0 0C009C73 */  jal       func_800271CC
/* 2CD4 800278D4 AFA20010 */   sw       $v0, 0x10($sp)
/* 2CD8 800278D8 0280202D */  daddu     $a0, $s4, $zero
/* 2CDC 800278DC 02A0282D */  daddu     $a1, $s5, $zero
/* 2CE0 800278E0 02E0302D */  daddu     $a2, $s7, $zero
/* 2CE4 800278E4 0220382D */  daddu     $a3, $s1, $zero
/* 2CE8 800278E8 27A20038 */  addiu     $v0, $sp, 0x38
/* 2CEC 800278EC 0C009C73 */  jal       func_800271CC
/* 2CF0 800278F0 AFA20010 */   sw       $v0, 0x10($sp)
/* 2CF4 800278F4 00162840 */  sll       $a1, $s6, 1
/* 2CF8 800278F8 8FA80078 */  lw        $t0, 0x78($sp)
/* 2CFC 800278FC 8FA40040 */  lw        $a0, 0x40($sp)
/* 2D00 80027900 0C009D74 */  jal       func_800275D0
/* 2D04 80027904 01052821 */   addu     $a1, $t0, $a1
/* 2D08 80027908 08009E4B */  j         .L8002792C
/* 2D0C 8002790C 26D60001 */   addiu    $s6, $s6, 1
.L80027910:
/* 2D10 80027910 00741021 */  addu      $v0, $v1, $s4
/* 2D14 80027914 8FA80078 */  lw        $t0, 0x78($sp)
/* 2D18 80027918 94420000 */  lhu       $v0, ($v0)
/* 2D1C 8002791C 00681821 */  addu      $v1, $v1, $t0
/* 2D20 80027920 34420001 */  ori       $v0, $v0, 1
/* 2D24 80027924 A4620000 */  sh        $v0, ($v1)
/* 2D28 80027928 26D60001 */  addiu     $s6, $s6, 1
.L8002792C:
/* 2D2C 8002792C 26520001 */  addiu     $s2, $s2, 1
/* 2D30 80027930 2A42013F */  slti      $v0, $s2, 0x13f
/* 2D34 80027934 1440FF9C */  bnez      $v0, .L800277A8
/* 2D38 80027938 00161840 */   sll      $v1, $s6, 1
/* 2D3C 8002793C 26730001 */  addiu     $s3, $s3, 1
/* 2D40 80027940 8FA80044 */  lw        $t0, 0x44($sp)
/* 2D44 80027944 2A6200EF */  slti      $v0, $s3, 0xef
/* 2D48 80027948 25080140 */  addiu     $t0, $t0, 0x140
/* 2D4C 8002794C 1440FF90 */  bnez      $v0, .L80027790
/* 2D50 80027950 AFA80044 */   sw       $t0, 0x44($sp)
/* 2D54 80027954 8FBF006C */  lw        $ra, 0x6c($sp)
/* 2D58 80027958 8FBE0068 */  lw        $fp, 0x68($sp)
/* 2D5C 8002795C 8FB70064 */  lw        $s7, 0x64($sp)
/* 2D60 80027960 8FB60060 */  lw        $s6, 0x60($sp)
/* 2D64 80027964 8FB5005C */  lw        $s5, 0x5c($sp)
/* 2D68 80027968 8FB40058 */  lw        $s4, 0x58($sp)
/* 2D6C 8002796C 8FB30054 */  lw        $s3, 0x54($sp)
/* 2D70 80027970 8FB20050 */  lw        $s2, 0x50($sp)
/* 2D74 80027974 8FB1004C */  lw        $s1, 0x4c($sp)
/* 2D78 80027978 8FB00048 */  lw        $s0, 0x48($sp)
/* 2D7C 8002797C 03E00008 */  jr        $ra
/* 2D80 80027980 27BD0070 */   addiu    $sp, $sp, 0x70
