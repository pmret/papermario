.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel free_npc_by_index
/* 13CA0 800388A0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 13CA4 800388A4 2402F7FF */  addiu     $v0, $zero, -0x801
/* 13CA8 800388A8 AFB20018 */  sw        $s2, 0x18($sp)
/* 13CAC 800388AC 00829024 */  and       $s2, $a0, $v0
/* 13CB0 800388B0 3C03800A */  lui       $v1, %hi(gCurrentNpcListPtr)
/* 13CB4 800388B4 8C630B90 */  lw        $v1, %lo(gCurrentNpcListPtr)($v1)
/* 13CB8 800388B8 00121080 */  sll       $v0, $s2, 2
/* 13CBC 800388BC AFBF001C */  sw        $ra, 0x1c($sp)
/* 13CC0 800388C0 AFB10014 */  sw        $s1, 0x14($sp)
/* 13CC4 800388C4 AFB00010 */  sw        $s0, 0x10($sp)
/* 13CC8 800388C8 00431021 */  addu      $v0, $v0, $v1
/* 13CCC 800388CC 8C500000 */  lw        $s0, ($v0)
/* 13CD0 800388D0 12000038 */  beqz      $s0, .L800389B4
/* 13CD4 800388D4 00000000 */   nop      
/* 13CD8 800388D8 8E020000 */  lw        $v0, ($s0)
/* 13CDC 800388DC 10400035 */  beqz      $v0, .L800389B4
/* 13CE0 800388E0 00000000 */   nop      
/* 13CE4 800388E4 8E040020 */  lw        $a0, 0x20($s0)
/* 13CE8 800388E8 10800004 */  beqz      $a0, .L800388FC
/* 13CEC 800388EC 00000000 */   nop      
/* 13CF0 800388F0 0C00AB4B */  jal       heap_free
/* 13CF4 800388F4 00000000 */   nop      
/* 13CF8 800388F8 AE000020 */  sw        $zero, 0x20($s0)
.L800388FC:
/* 13CFC 800388FC 8E030000 */  lw        $v1, ($s0)
/* 13D00 80038900 3C024000 */  lui       $v0, 0x4000
/* 13D04 80038904 00621024 */  and       $v0, $v1, $v0
/* 13D08 80038908 1440000A */  bnez      $v0, .L80038934
/* 13D0C 8003890C 3C020100 */   lui      $v0, 0x100
/* 13D10 80038910 00621024 */  and       $v0, $v1, $v0
/* 13D14 80038914 14400007 */  bnez      $v0, .L80038934
/* 13D18 80038918 00000000 */   nop      
/* 13D1C 8003891C 0C0B797A */  jal       func_802DE5E8
/* 13D20 80038920 8E040024 */   lw       $a0, 0x24($s0)
/* 13D24 80038924 10400003 */  beqz      $v0, .L80038934
/* 13D28 80038928 00000000 */   nop      
.L8003892C:
/* 13D2C 8003892C 0800E24B */  j         .L8003892C
/* 13D30 80038930 00000000 */   nop      
.L80038934:
/* 13D34 80038934 8E040078 */  lw        $a0, 0x78($s0)
/* 13D38 80038938 0C0448CA */  jal       func_80112328
/* 13D3C 8003893C 0000882D */   daddu    $s1, $zero, $zero
/* 13D40 80038940 0200202D */  daddu     $a0, $s0, $zero
.L80038944:
/* 13D44 80038944 0C00F10A */  jal       func_8003C428
/* 13D48 80038948 0220282D */   daddu    $a1, $s1, $zero
/* 13D4C 8003894C 26310001 */  addiu     $s1, $s1, 1
/* 13D50 80038950 2A220002 */  slti      $v0, $s1, 2
/* 13D54 80038954 1440FFFB */  bnez      $v0, .L80038944
/* 13D58 80038958 0200202D */   daddu    $a0, $s0, $zero
/* 13D5C 8003895C 8E020000 */  lw        $v0, ($s0)
/* 13D60 80038960 3C030010 */  lui       $v1, 0x10
/* 13D64 80038964 00431024 */  and       $v0, $v0, $v1
/* 13D68 80038968 10400003 */  beqz      $v0, .L80038978
/* 13D6C 8003896C 00000000 */   nop      
/* 13D70 80038970 0C00EB6B */  jal       disable_npc_blur
/* 13D74 80038974 0200202D */   daddu    $a0, $s0, $zero
.L80038978:
/* 13D78 80038978 3C11800A */  lui       $s1, %hi(gCurrentNpcListPtr)
/* 13D7C 8003897C 26310B90 */  addiu     $s1, $s1, %lo(gCurrentNpcListPtr)
/* 13D80 80038980 8E220000 */  lw        $v0, ($s1)
/* 13D84 80038984 00128080 */  sll       $s0, $s2, 2
/* 13D88 80038988 02021021 */  addu      $v0, $s0, $v0
/* 13D8C 8003898C 0C00AB4B */  jal       heap_free
/* 13D90 80038990 8C440000 */   lw       $a0, ($v0)
/* 13D94 80038994 3C04800A */  lui       $a0, 0x800a
/* 13D98 80038998 2484A604 */  addiu     $a0, $a0, -0x59fc
/* 13D9C 8003899C 8E230000 */  lw        $v1, ($s1)
/* 13DA0 800389A0 94820000 */  lhu       $v0, ($a0)
/* 13DA4 800389A4 02038021 */  addu      $s0, $s0, $v1
/* 13DA8 800389A8 2442FFFF */  addiu     $v0, $v0, -1
/* 13DAC 800389AC AE000000 */  sw        $zero, ($s0)
/* 13DB0 800389B0 A4820000 */  sh        $v0, ($a0)
.L800389B4:
/* 13DB4 800389B4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 13DB8 800389B8 8FB20018 */  lw        $s2, 0x18($sp)
/* 13DBC 800389BC 8FB10014 */  lw        $s1, 0x14($sp)
/* 13DC0 800389C0 8FB00010 */  lw        $s0, 0x10($sp)
/* 13DC4 800389C4 03E00008 */  jr        $ra
/* 13DC8 800389C8 27BD0020 */   addiu    $sp, $sp, 0x20
