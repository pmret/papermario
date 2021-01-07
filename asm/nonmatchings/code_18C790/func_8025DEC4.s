.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8025DEC4
/* 18C7A4 8025DEC4 3C0651EB */  lui       $a2, 0x51eb
/* 18C7A8 8025DEC8 3C05800E */  lui       $a1, %hi(gBattleStatus)
/* 18C7AC 8025DECC 24A5C070 */  addiu     $a1, $a1, %lo(gBattleStatus)
/* 18C7B0 8025DED0 90A30078 */  lbu       $v1, 0x78($a1)
/* 18C7B4 8025DED4 34C6851F */  ori       $a2, $a2, 0x851f
/* 18C7B8 8025DED8 00031E00 */  sll       $v1, $v1, 0x18
/* 18C7BC 8025DEDC 00031603 */  sra       $v0, $v1, 0x18
/* 18C7C0 8025DEE0 00460018 */  mult      $v0, $a2
/* 18C7C4 8025DEE4 0080382D */  daddu     $a3, $a0, $zero
/* 18C7C8 8025DEE8 00031FC3 */  sra       $v1, $v1, 0x1f
/* 18C7CC 8025DEEC 00004010 */  mfhi      $t0
/* 18C7D0 8025DEF0 00081143 */  sra       $v0, $t0, 5
/* 18C7D4 8025DEF4 00431023 */  subu      $v0, $v0, $v1
/* 18C7D8 8025DEF8 00021600 */  sll       $v0, $v0, 0x18
/* 18C7DC 8025DEFC 00021603 */  sra       $v0, $v0, 0x18
/* 18C7E0 8025DF00 ACE200AC */  sw        $v0, 0xac($a3)
/* 18C7E4 8025DF04 90A20078 */  lbu       $v0, 0x78($a1)
/* 18C7E8 8025DF08 00021600 */  sll       $v0, $v0, 0x18
/* 18C7EC 8025DF0C 00022603 */  sra       $a0, $v0, 0x18
/* 18C7F0 8025DF10 00860018 */  mult      $a0, $a2
/* 18C7F4 8025DF14 3C066666 */  lui       $a2, 0x6666
/* 18C7F8 8025DF18 34C66667 */  ori       $a2, $a2, 0x6667
/* 18C7FC 8025DF1C 000217C3 */  sra       $v0, $v0, 0x1f
/* 18C800 8025DF20 00004010 */  mfhi      $t0
/* 18C804 8025DF24 00081943 */  sra       $v1, $t0, 5
/* 18C808 8025DF28 00621823 */  subu      $v1, $v1, $v0
/* 18C80C 8025DF2C 00031040 */  sll       $v0, $v1, 1
/* 18C810 8025DF30 00431021 */  addu      $v0, $v0, $v1
/* 18C814 8025DF34 000210C0 */  sll       $v0, $v0, 3
/* 18C818 8025DF38 00431021 */  addu      $v0, $v0, $v1
/* 18C81C 8025DF3C 00021080 */  sll       $v0, $v0, 2
/* 18C820 8025DF40 00822023 */  subu      $a0, $a0, $v0
/* 18C824 8025DF44 00042600 */  sll       $a0, $a0, 0x18
/* 18C828 8025DF48 00041603 */  sra       $v0, $a0, 0x18
/* 18C82C 8025DF4C 00460018 */  mult      $v0, $a2
/* 18C830 8025DF50 000427C3 */  sra       $a0, $a0, 0x1f
/* 18C834 8025DF54 00004010 */  mfhi      $t0
/* 18C838 8025DF58 00081083 */  sra       $v0, $t0, 2
/* 18C83C 8025DF5C 00441023 */  subu      $v0, $v0, $a0
/* 18C840 8025DF60 00021600 */  sll       $v0, $v0, 0x18
/* 18C844 8025DF64 00021603 */  sra       $v0, $v0, 0x18
/* 18C848 8025DF68 ACE200B0 */  sw        $v0, 0xb0($a3)
/* 18C84C 8025DF6C 90A20078 */  lbu       $v0, 0x78($a1)
/* 18C850 8025DF70 00021600 */  sll       $v0, $v0, 0x18
/* 18C854 8025DF74 00022603 */  sra       $a0, $v0, 0x18
/* 18C858 8025DF78 00860018 */  mult      $a0, $a2
/* 18C85C 8025DF7C 0000282D */  daddu     $a1, $zero, $zero
/* 18C860 8025DF80 000217C3 */  sra       $v0, $v0, 0x1f
/* 18C864 8025DF84 00004010 */  mfhi      $t0
/* 18C868 8025DF88 00081883 */  sra       $v1, $t0, 2
/* 18C86C 8025DF8C 00621823 */  subu      $v1, $v1, $v0
/* 18C870 8025DF90 00031080 */  sll       $v0, $v1, 2
/* 18C874 8025DF94 00431021 */  addu      $v0, $v0, $v1
/* 18C878 8025DF98 00021040 */  sll       $v0, $v0, 1
/* 18C87C 8025DF9C 00822023 */  subu      $a0, $a0, $v0
/* 18C880 8025DFA0 00042600 */  sll       $a0, $a0, 0x18
/* 18C884 8025DFA4 8CE200AC */  lw        $v0, 0xac($a3)
/* 18C888 8025DFA8 00042603 */  sra       $a0, $a0, 0x18
/* 18C88C 8025DFAC 18400007 */  blez      $v0, .L8025DFCC
/* 18C890 8025DFB0 ACE400B4 */   sw       $a0, 0xb4($a3)
/* 18C894 8025DFB4 00021080 */  sll       $v0, $v0, 2
/* 18C898 8025DFB8 3C018028 */  lui       $at, %hi(D_80284188)
/* 18C89C 8025DFBC 00220821 */  addu      $at, $at, $v0
/* 18C8A0 8025DFC0 8C224188 */  lw        $v0, %lo(D_80284188)($at)
/* 18C8A4 8025DFC4 080977F5 */  j         .L8025DFD4
/* 18C8A8 8025DFC8 24050001 */   addiu    $a1, $zero, 1
.L8025DFCC:
/* 18C8AC 8025DFCC 3C028028 */  lui       $v0, %hi(D_802841B0)
/* 18C8B0 8025DFD0 8C4241B0 */  lw        $v0, %lo(D_802841B0)($v0)
.L8025DFD4:
/* 18C8B4 8025DFD4 ACE200AC */  sw        $v0, 0xac($a3)
/* 18C8B8 8025DFD8 8CE200B0 */  lw        $v0, 0xb0($a3)
/* 18C8BC 8025DFDC 5C400004 */  bgtzl     $v0, .L8025DFF0
/* 18C8C0 8025DFE0 00021080 */   sll      $v0, $v0, 2
/* 18C8C4 8025DFE4 10A00007 */  beqz      $a1, .L8025E004
/* 18C8C8 8025DFE8 00000000 */   nop      
/* 18C8CC 8025DFEC 00021080 */  sll       $v0, $v0, 2
.L8025DFF0:
/* 18C8D0 8025DFF0 3C018028 */  lui       $at, %hi(D_80284188)
/* 18C8D4 8025DFF4 00220821 */  addu      $at, $at, $v0
/* 18C8D8 8025DFF8 8C224188 */  lw        $v0, %lo(D_80284188)($at)
/* 18C8DC 8025DFFC 08097804 */  j         .L8025E010
/* 18C8E0 8025E000 ACE200B0 */   sw       $v0, 0xb0($a3)
.L8025E004:
/* 18C8E4 8025E004 3C028028 */  lui       $v0, %hi(D_802841B0)
/* 18C8E8 8025E008 8C4241B0 */  lw        $v0, %lo(D_802841B0)($v0)
/* 18C8EC 8025E00C ACE200B0 */  sw        $v0, 0xb0($a3)
.L8025E010:
/* 18C8F0 8025E010 8CE200B4 */  lw        $v0, 0xb4($a3)
/* 18C8F4 8025E014 00021080 */  sll       $v0, $v0, 2
/* 18C8F8 8025E018 3C018028 */  lui       $at, %hi(D_80284188)
/* 18C8FC 8025E01C 00220821 */  addu      $at, $at, $v0
/* 18C900 8025E020 8C224188 */  lw        $v0, %lo(D_80284188)($at)
/* 18C904 8025E024 ACE200B4 */  sw        $v0, 0xb4($a3)
/* 18C908 8025E028 03E00008 */  jr        $ra
/* 18C90C 8025E02C 24020002 */   addiu    $v0, $zero, 2
