.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802418FC_824BBC
/* 824BBC 802418FC 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 824BC0 80241900 AFB10024 */  sw        $s1, 0x24($sp)
/* 824BC4 80241904 0080882D */  daddu     $s1, $a0, $zero
/* 824BC8 80241908 3C05F840 */  lui       $a1, 0xf840
/* 824BCC 8024190C AFBF0044 */  sw        $ra, 0x44($sp)
/* 824BD0 80241910 AFBE0040 */  sw        $fp, 0x40($sp)
/* 824BD4 80241914 AFB7003C */  sw        $s7, 0x3c($sp)
/* 824BD8 80241918 AFB60038 */  sw        $s6, 0x38($sp)
/* 824BDC 8024191C AFB50034 */  sw        $s5, 0x34($sp)
/* 824BE0 80241920 AFB40030 */  sw        $s4, 0x30($sp)
/* 824BE4 80241924 AFB3002C */  sw        $s3, 0x2c($sp)
/* 824BE8 80241928 AFB20028 */  sw        $s2, 0x28($sp)
/* 824BEC 8024192C AFB00020 */  sw        $s0, 0x20($sp)
/* 824BF0 80241930 8E3E0148 */  lw        $fp, 0x148($s1)
/* 824BF4 80241934 0C0B1EAF */  jal       get_variable
/* 824BF8 80241938 34A56268 */   ori      $a1, $a1, 0x6268
/* 824BFC 8024193C 0040802D */  daddu     $s0, $v0, $zero
/* 824C00 80241940 0220202D */  daddu     $a0, $s1, $zero
/* 824C04 80241944 3C05F840 */  lui       $a1, 0xf840
/* 824C08 80241948 0C0B1EAF */  jal       get_variable
/* 824C0C 8024194C 34A56269 */   ori      $a1, $a1, 0x6269
/* 824C10 80241950 0040B82D */  daddu     $s7, $v0, $zero
/* 824C14 80241954 0220202D */  daddu     $a0, $s1, $zero
/* 824C18 80241958 3C05F5DE */  lui       $a1, 0xf5de
/* 824C1C 8024195C 0C0B1EAF */  jal       get_variable
/* 824C20 80241960 34A502DE */   ori      $a1, $a1, 0x2de
/* 824C24 80241964 0040B02D */  daddu     $s6, $v0, $zero
/* 824C28 80241968 0220202D */  daddu     $a0, $s1, $zero
/* 824C2C 8024196C 3C05F5DE */  lui       $a1, 0xf5de
/* 824C30 80241970 0C0B1EAF */  jal       get_variable
/* 824C34 80241974 34A502DF */   ori      $a1, $a1, 0x2df
/* 824C38 80241978 0040A82D */  daddu     $s5, $v0, $zero
/* 824C3C 8024197C 93D3006D */  lbu       $s3, 0x6d($fp)
/* 824C40 80241980 32C2FFFF */  andi      $v0, $s6, 0xffff
/* 824C44 80241984 A7B30010 */  sh        $s3, 0x10($sp)
/* 824C48 80241988 93D2006E */  lbu       $s2, 0x6e($fp)
/* 824C4C 8024198C 93C7006F */  lbu       $a3, 0x6f($fp)
/* 824C50 80241990 3274FFFF */  andi      $s4, $s3, 0xffff
/* 824C54 80241994 12820003 */  beq       $s4, $v0, .L802419A4
/* 824C58 80241998 A7A7001E */   sh       $a3, 0x1e($sp)
/* 824C5C 8024199C 0000B82D */  daddu     $s7, $zero, $zero
/* 824C60 802419A0 02E0802D */  daddu     $s0, $s7, $zero
.L802419A4:
/* 824C64 802419A4 3202FFFF */  andi      $v0, $s0, 0xffff
/* 824C68 802419A8 14400016 */  bnez      $v0, .L80241A04
/* 824C6C 802419AC 0220202D */   daddu    $a0, $s1, $zero
/* 824C70 802419B0 0C00A67F */  jal       rand_int
/* 824C74 802419B4 24040064 */   addiu    $a0, $zero, 0x64
/* 824C78 802419B8 2842001E */  slti      $v0, $v0, 0x1e
/* 824C7C 802419BC 10400011 */  beqz      $v0, .L80241A04
/* 824C80 802419C0 0220202D */   daddu    $a0, $s1, $zero
/* 824C84 802419C4 0C00A67F */  jal       rand_int
/* 824C88 802419C8 2644FFFF */   addiu    $a0, $s2, -1
/* 824C8C 802419CC 0040A82D */  daddu     $s5, $v0, $zero
/* 824C90 802419D0 0260B02D */  daddu     $s6, $s3, $zero
/* 824C94 802419D4 0220202D */  daddu     $a0, $s1, $zero
/* 824C98 802419D8 3C05F5DE */  lui       $a1, 0xf5de
/* 824C9C 802419DC 34A502DE */  ori       $a1, $a1, 0x2de
/* 824CA0 802419E0 0C0B2026 */  jal       set_variable
/* 824CA4 802419E4 0280302D */   daddu    $a2, $s4, $zero
/* 824CA8 802419E8 0220202D */  daddu     $a0, $s1, $zero
/* 824CAC 802419EC 3C05F5DE */  lui       $a1, 0xf5de
/* 824CB0 802419F0 34A502DF */  ori       $a1, $a1, 0x2df
/* 824CB4 802419F4 0C0B2026 */  jal       set_variable
/* 824CB8 802419F8 32A6FFFF */   andi     $a2, $s5, 0xffff
/* 824CBC 802419FC 24100001 */  addiu     $s0, $zero, 1
/* 824CC0 80241A00 0220202D */  daddu     $a0, $s1, $zero
.L80241A04:
/* 824CC4 80241A04 3C05F840 */  lui       $a1, 0xf840
/* 824CC8 80241A08 34A56268 */  ori       $a1, $a1, 0x6268
/* 824CCC 80241A0C 0C0B2026 */  jal       set_variable
/* 824CD0 80241A10 3206FFFF */   andi     $a2, $s0, 0xffff
/* 824CD4 80241A14 0220202D */  daddu     $a0, $s1, $zero
/* 824CD8 80241A18 3C05F840 */  lui       $a1, 0xf840
/* 824CDC 80241A1C 34A56269 */  ori       $a1, $a1, 0x6269
/* 824CE0 80241A20 0C0B2026 */  jal       set_variable
/* 824CE4 80241A24 32E6FFFF */   andi     $a2, $s7, 0xffff
/* 824CE8 80241A28 0000202D */  daddu     $a0, $zero, $zero
/* 824CEC 80241A2C 3C05F5DE */  lui       $a1, 0xf5de
/* 824CF0 80241A30 0C0B1EAF */  jal       get_variable
/* 824CF4 80241A34 34A502E0 */   ori      $a1, $a1, 0x2e0
/* 824CF8 80241A38 0000202D */  daddu     $a0, $zero, $zero
/* 824CFC 80241A3C 3C05F5DE */  lui       $a1, 0xf5de
/* 824D00 80241A40 34A50180 */  ori       $a1, $a1, 0x180
/* 824D04 80241A44 0C0B1EAF */  jal       get_variable
/* 824D08 80241A48 0040802D */   daddu    $s0, $v0, $zero
/* 824D0C 80241A4C 0040282D */  daddu     $a1, $v0, $zero
/* 824D10 80241A50 0000182D */  daddu     $v1, $zero, $zero
/* 824D14 80241A54 3C068024 */  lui       $a2, 0x8024
/* 824D18 80241A58 24C661F4 */  addiu     $a2, $a2, 0x61f4
/* 824D1C 80241A5C 00C0202D */  daddu     $a0, $a2, $zero
.L80241A60:
/* 824D20 80241A60 8C820000 */  lw        $v0, ($a0)
/* 824D24 80241A64 00A2102A */  slt       $v0, $a1, $v0
/* 824D28 80241A68 14400006 */  bnez      $v0, .L80241A84
/* 824D2C 80241A6C 000310C0 */   sll      $v0, $v1, 3
/* 824D30 80241A70 24630001 */  addiu     $v1, $v1, 1
/* 824D34 80241A74 28620008 */  slti      $v0, $v1, 8
/* 824D38 80241A78 1440FFF9 */  bnez      $v0, .L80241A60
/* 824D3C 80241A7C 24840008 */   addiu    $a0, $a0, 8
/* 824D40 80241A80 000310C0 */  sll       $v0, $v1, 3
.L80241A84:
/* 824D44 80241A84 00461021 */  addu      $v0, $v0, $a2
/* 824D48 80241A88 8C420004 */  lw        $v0, 4($v0)
/* 824D4C 80241A8C 97A30010 */  lhu       $v1, 0x10($sp)
/* 824D50 80241A90 0202202A */  slt       $a0, $s0, $v0
/* 824D54 80241A94 32C2FFFF */  andi      $v0, $s6, 0xffff
/* 824D58 80241A98 14620008 */  bne       $v1, $v0, .L80241ABC
/* 824D5C 80241A9C 32A2FFFF */   andi     $v0, $s5, 0xffff
/* 824D60 80241AA0 97A7001E */  lhu       $a3, 0x1e($sp)
/* 824D64 80241AA4 14E20005 */  bne       $a3, $v0, .L80241ABC
/* 824D68 80241AA8 32E2FFFF */   andi     $v0, $s7, 0xffff
/* 824D6C 80241AAC 14400003 */  bnez      $v0, .L80241ABC
/* 824D70 80241AB0 00000000 */   nop      
/* 824D74 80241AB4 14800008 */  bnez      $a0, .L80241AD8
/* 824D78 80241AB8 24020001 */   addiu    $v0, $zero, 1
.L80241ABC:
/* 824D7C 80241ABC 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 824D80 80241AC0 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 824D84 80241AC4 80420075 */  lb        $v0, 0x75($v0)
/* 824D88 80241AC8 10400005 */  beqz      $v0, .L80241AE0
/* 824D8C 80241ACC 00000000 */   nop      
/* 824D90 80241AD0 10800003 */  beqz      $a0, .L80241AE0
/* 824D94 80241AD4 24020001 */   addiu    $v0, $zero, 1
.L80241AD8:
/* 824D98 80241AD8 080906BB */  j         .L80241AEC
/* 824D9C 80241ADC AE220084 */   sw       $v0, 0x84($s1)
.L80241AE0:
/* 824DA0 80241AE0 0C00F9EB */  jal       kill_enemy
/* 824DA4 80241AE4 03C0202D */   daddu    $a0, $fp, $zero
/* 824DA8 80241AE8 AE200084 */  sw        $zero, 0x84($s1)
.L80241AEC:
/* 824DAC 80241AEC 8FBF0044 */  lw        $ra, 0x44($sp)
/* 824DB0 80241AF0 8FBE0040 */  lw        $fp, 0x40($sp)
/* 824DB4 80241AF4 8FB7003C */  lw        $s7, 0x3c($sp)
/* 824DB8 80241AF8 8FB60038 */  lw        $s6, 0x38($sp)
/* 824DBC 80241AFC 8FB50034 */  lw        $s5, 0x34($sp)
/* 824DC0 80241B00 8FB40030 */  lw        $s4, 0x30($sp)
/* 824DC4 80241B04 8FB3002C */  lw        $s3, 0x2c($sp)
/* 824DC8 80241B08 8FB20028 */  lw        $s2, 0x28($sp)
/* 824DCC 80241B0C 8FB10024 */  lw        $s1, 0x24($sp)
/* 824DD0 80241B10 8FB00020 */  lw        $s0, 0x20($sp)
/* 824DD4 80241B14 24020002 */  addiu     $v0, $zero, 2
/* 824DD8 80241B18 03E00008 */  jr        $ra
/* 824DDC 80241B1C 27BD0048 */   addiu    $sp, $sp, 0x48
