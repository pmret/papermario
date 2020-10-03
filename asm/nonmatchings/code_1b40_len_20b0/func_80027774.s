.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80027774
/* 2B74 80027774 27BDFF90 */  addiu     $sp, $sp, -0x70
/* 2B78 80027778 AFB40058 */  sw        $s4, 0x58($sp)
/* 2B7C 8002777C 0080A02D */  daddu     $s4, $a0, $zero
/* 2B80 80027780 AFB5005C */  sw        $s5, 0x5c($sp)
/* 2B84 80027784 00A0A82D */  daddu     $s5, $a1, $zero
/* 2B88 80027788 AFB30054 */  sw        $s3, 0x54($sp)
/* 2B8C 8002778C 24130001 */  addiu     $s3, $zero, 1
/* 2B90 80027790 27A80018 */  addiu     $t0, $sp, 0x18
/* 2B94 80027794 AFA80040 */  sw        $t0, 0x40($sp)
/* 2B98 80027798 24080140 */  addiu     $t0, $zero, 0x140
/* 2B9C 8002779C AFBF006C */  sw        $ra, 0x6c($sp)
/* 2BA0 800277A0 AFBE0068 */  sw        $fp, 0x68($sp)
/* 2BA4 800277A4 AFB70064 */  sw        $s7, 0x64($sp)
/* 2BA8 800277A8 AFB60060 */  sw        $s6, 0x60($sp)
/* 2BAC 800277AC AFB20050 */  sw        $s2, 0x50($sp)
/* 2BB0 800277B0 AFB1004C */  sw        $s1, 0x4c($sp)
/* 2BB4 800277B4 AFB00048 */  sw        $s0, 0x48($sp)
/* 2BB8 800277B8 AFA60078 */  sw        $a2, 0x78($sp)
/* 2BBC 800277BC AFA80044 */  sw        $t0, 0x44($sp)
.L800277C0:
/* 2BC0 800277C0 24120001 */  addiu     $s2, $zero, 1
/* 2BC4 800277C4 267EFFFF */  addiu     $fp, $s3, -1
/* 2BC8 800277C8 8FA80044 */  lw        $t0, 0x44($sp)
/* 2BCC 800277CC 0272B821 */  addu      $s7, $s3, $s2
/* 2BD0 800277D0 0112B021 */  addu      $s6, $t0, $s2
/* 2BD4 800277D4 00161840 */  sll       $v1, $s6, 1
.L800277D8:
/* 2BD8 800277D8 00752021 */  addu      $a0, $v1, $s5
/* 2BDC 800277DC 9482FFFE */  lhu       $v0, -2($a0)
/* 2BE0 800277E0 00021082 */  srl       $v0, $v0, 2
/* 2BE4 800277E4 3042000F */  andi      $v0, $v0, 0xf
/* 2BE8 800277E8 2C420008 */  sltiu     $v0, $v0, 8
/* 2BEC 800277EC 5440000D */  bnel      $v0, $zero, .L80027824
/* 2BF0 800277F0 0280202D */   daddu    $a0, $s4, $zero
/* 2BF4 800277F4 94820000 */  lhu       $v0, ($a0)
/* 2BF8 800277F8 00021082 */  srl       $v0, $v0, 2
/* 2BFC 800277FC 3042000F */  andi      $v0, $v0, 0xf
/* 2C00 80027800 2C420008 */  sltiu     $v0, $v0, 8
/* 2C04 80027804 54400007 */  bnel      $v0, $zero, .L80027824
/* 2C08 80027808 0280202D */   daddu    $a0, $s4, $zero
/* 2C0C 8002780C 94820002 */  lhu       $v0, 2($a0)
/* 2C10 80027810 00021082 */  srl       $v0, $v0, 2
/* 2C14 80027814 3042000F */  andi      $v0, $v0, 0xf
/* 2C18 80027818 2C420008 */  sltiu     $v0, $v0, 8
/* 2C1C 8002781C 10400048 */  beqz      $v0, .L80027940
/* 2C20 80027820 0280202D */   daddu    $a0, $s4, $zero
.L80027824:
/* 2C24 80027824 02A0282D */  daddu     $a1, $s5, $zero
/* 2C28 80027828 03C0302D */  daddu     $a2, $fp, $zero
/* 2C2C 8002782C 2650FFFF */  addiu     $s0, $s2, -1
/* 2C30 80027830 8FA80040 */  lw        $t0, 0x40($sp)
/* 2C34 80027834 0200382D */  daddu     $a3, $s0, $zero
/* 2C38 80027838 0C009C7F */  jal       func_800271FC
/* 2C3C 8002783C AFA80010 */   sw       $t0, 0x10($sp)
/* 2C40 80027840 0280202D */  daddu     $a0, $s4, $zero
/* 2C44 80027844 02A0282D */  daddu     $a1, $s5, $zero
/* 2C48 80027848 03C0302D */  daddu     $a2, $fp, $zero
/* 2C4C 8002784C 0240382D */  daddu     $a3, $s2, $zero
/* 2C50 80027850 27A2001C */  addiu     $v0, $sp, 0x1c
/* 2C54 80027854 0C009C7F */  jal       func_800271FC
/* 2C58 80027858 AFA20010 */   sw       $v0, 0x10($sp)
/* 2C5C 8002785C 0280202D */  daddu     $a0, $s4, $zero
/* 2C60 80027860 02A0282D */  daddu     $a1, $s5, $zero
/* 2C64 80027864 03C0302D */  daddu     $a2, $fp, $zero
/* 2C68 80027868 26510001 */  addiu     $s1, $s2, 1
/* 2C6C 8002786C 0220382D */  daddu     $a3, $s1, $zero
/* 2C70 80027870 27A20020 */  addiu     $v0, $sp, 0x20
/* 2C74 80027874 0C009C7F */  jal       func_800271FC
/* 2C78 80027878 AFA20010 */   sw       $v0, 0x10($sp)
/* 2C7C 8002787C 0280202D */  daddu     $a0, $s4, $zero
/* 2C80 80027880 02A0282D */  daddu     $a1, $s5, $zero
/* 2C84 80027884 0260302D */  daddu     $a2, $s3, $zero
/* 2C88 80027888 0200382D */  daddu     $a3, $s0, $zero
/* 2C8C 8002788C 27A20024 */  addiu     $v0, $sp, 0x24
/* 2C90 80027890 0C009C7F */  jal       func_800271FC
/* 2C94 80027894 AFA20010 */   sw       $v0, 0x10($sp)
/* 2C98 80027898 0280202D */  daddu     $a0, $s4, $zero
/* 2C9C 8002789C 02A0282D */  daddu     $a1, $s5, $zero
/* 2CA0 800278A0 0260302D */  daddu     $a2, $s3, $zero
/* 2CA4 800278A4 0240382D */  daddu     $a3, $s2, $zero
/* 2CA8 800278A8 27A20028 */  addiu     $v0, $sp, 0x28
/* 2CAC 800278AC 0C009C7F */  jal       func_800271FC
/* 2CB0 800278B0 AFA20010 */   sw       $v0, 0x10($sp)
/* 2CB4 800278B4 0280202D */  daddu     $a0, $s4, $zero
/* 2CB8 800278B8 02A0282D */  daddu     $a1, $s5, $zero
/* 2CBC 800278BC 0260302D */  daddu     $a2, $s3, $zero
/* 2CC0 800278C0 0220382D */  daddu     $a3, $s1, $zero
/* 2CC4 800278C4 27A2002C */  addiu     $v0, $sp, 0x2c
/* 2CC8 800278C8 0C009C7F */  jal       func_800271FC
/* 2CCC 800278CC AFA20010 */   sw       $v0, 0x10($sp)
/* 2CD0 800278D0 0280202D */  daddu     $a0, $s4, $zero
/* 2CD4 800278D4 02A0282D */  daddu     $a1, $s5, $zero
/* 2CD8 800278D8 02E0302D */  daddu     $a2, $s7, $zero
/* 2CDC 800278DC 0200382D */  daddu     $a3, $s0, $zero
/* 2CE0 800278E0 27A20030 */  addiu     $v0, $sp, 0x30
/* 2CE4 800278E4 0C009C7F */  jal       func_800271FC
/* 2CE8 800278E8 AFA20010 */   sw       $v0, 0x10($sp)
/* 2CEC 800278EC 0280202D */  daddu     $a0, $s4, $zero
/* 2CF0 800278F0 02A0282D */  daddu     $a1, $s5, $zero
/* 2CF4 800278F4 02E0302D */  daddu     $a2, $s7, $zero
/* 2CF8 800278F8 0240382D */  daddu     $a3, $s2, $zero
/* 2CFC 800278FC 27A20034 */  addiu     $v0, $sp, 0x34
/* 2D00 80027900 0C009C7F */  jal       func_800271FC
/* 2D04 80027904 AFA20010 */   sw       $v0, 0x10($sp)
/* 2D08 80027908 0280202D */  daddu     $a0, $s4, $zero
/* 2D0C 8002790C 02A0282D */  daddu     $a1, $s5, $zero
/* 2D10 80027910 02E0302D */  daddu     $a2, $s7, $zero
/* 2D14 80027914 0220382D */  daddu     $a3, $s1, $zero
/* 2D18 80027918 27A20038 */  addiu     $v0, $sp, 0x38
/* 2D1C 8002791C 0C009C7F */  jal       func_800271FC
/* 2D20 80027920 AFA20010 */   sw       $v0, 0x10($sp)
/* 2D24 80027924 00162840 */  sll       $a1, $s6, 1
/* 2D28 80027928 8FA80078 */  lw        $t0, 0x78($sp)
/* 2D2C 8002792C 8FA40040 */  lw        $a0, 0x40($sp)
/* 2D30 80027930 0C009D80 */  jal       func_80027600
/* 2D34 80027934 01052821 */   addu     $a1, $t0, $a1
/* 2D38 80027938 08009E57 */  j         .L8002795C
/* 2D3C 8002793C 26D60001 */   addiu    $s6, $s6, 1
.L80027940:
/* 2D40 80027940 00741021 */  addu      $v0, $v1, $s4
/* 2D44 80027944 8FA80078 */  lw        $t0, 0x78($sp)
/* 2D48 80027948 94420000 */  lhu       $v0, ($v0)
/* 2D4C 8002794C 00681821 */  addu      $v1, $v1, $t0
/* 2D50 80027950 34420001 */  ori       $v0, $v0, 1
/* 2D54 80027954 A4620000 */  sh        $v0, ($v1)
/* 2D58 80027958 26D60001 */  addiu     $s6, $s6, 1
.L8002795C:
/* 2D5C 8002795C 26520001 */  addiu     $s2, $s2, 1
/* 2D60 80027960 2A42013F */  slti      $v0, $s2, 0x13f
/* 2D64 80027964 1440FF9C */  bnez      $v0, .L800277D8
/* 2D68 80027968 00161840 */   sll      $v1, $s6, 1
/* 2D6C 8002796C 26730001 */  addiu     $s3, $s3, 1
/* 2D70 80027970 8FA80044 */  lw        $t0, 0x44($sp)
/* 2D74 80027974 2A6200EF */  slti      $v0, $s3, 0xef
/* 2D78 80027978 25080140 */  addiu     $t0, $t0, 0x140
/* 2D7C 8002797C 1440FF90 */  bnez      $v0, .L800277C0
/* 2D80 80027980 AFA80044 */   sw       $t0, 0x44($sp)
/* 2D84 80027984 8FBF006C */  lw        $ra, 0x6c($sp)
/* 2D88 80027988 8FBE0068 */  lw        $fp, 0x68($sp)
/* 2D8C 8002798C 8FB70064 */  lw        $s7, 0x64($sp)
/* 2D90 80027990 8FB60060 */  lw        $s6, 0x60($sp)
/* 2D94 80027994 8FB5005C */  lw        $s5, 0x5c($sp)
/* 2D98 80027998 8FB40058 */  lw        $s4, 0x58($sp)
/* 2D9C 8002799C 8FB30054 */  lw        $s3, 0x54($sp)
/* 2DA0 800279A0 8FB20050 */  lw        $s2, 0x50($sp)
/* 2DA4 800279A4 8FB1004C */  lw        $s1, 0x4c($sp)
/* 2DA8 800279A8 8FB00048 */  lw        $s0, 0x48($sp)
/* 2DAC 800279AC 03E00008 */  jr        $ra
/* 2DB0 800279B0 27BD0070 */   addiu    $sp, $sp, 0x70
