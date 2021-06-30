.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B54_8EC974
/* 8EC974 80240B54 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 8EC978 80240B58 AFB40020 */  sw        $s4, 0x20($sp)
/* 8EC97C 80240B5C 0080A02D */  daddu     $s4, $a0, $zero
/* 8EC980 80240B60 AFB7002C */  sw        $s7, 0x2c($sp)
/* 8EC984 80240B64 3C178025 */  lui       $s7, %hi(D_80253060)
/* 8EC988 80240B68 26F73060 */  addiu     $s7, $s7, %lo(D_80253060)
/* 8EC98C 80240B6C AFBF0034 */  sw        $ra, 0x34($sp)
/* 8EC990 80240B70 AFBE0030 */  sw        $fp, 0x30($sp)
/* 8EC994 80240B74 AFB60028 */  sw        $s6, 0x28($sp)
/* 8EC998 80240B78 AFB50024 */  sw        $s5, 0x24($sp)
/* 8EC99C 80240B7C AFB3001C */  sw        $s3, 0x1c($sp)
/* 8EC9A0 80240B80 AFB20018 */  sw        $s2, 0x18($sp)
/* 8EC9A4 80240B84 AFB10014 */  sw        $s1, 0x14($sp)
/* 8EC9A8 80240B88 10A00002 */  beqz      $a1, .L80240B94
/* 8EC9AC 80240B8C AFB00010 */   sw       $s0, 0x10($sp)
/* 8EC9B0 80240B90 AE800070 */  sw        $zero, 0x70($s4)
.L80240B94:
/* 8EC9B4 80240B94 8E930070 */  lw        $s3, 0x70($s4)
/* 8EC9B8 80240B98 12600005 */  beqz      $s3, .L80240BB0
/* 8EC9BC 80240B9C 24020001 */   addiu    $v0, $zero, 1
/* 8EC9C0 80240BA0 12620041 */  beq       $s3, $v0, .L80240CA8
/* 8EC9C4 80240BA4 0000102D */   daddu    $v0, $zero, $zero
/* 8EC9C8 80240BA8 0809035D */  j         .L80240D74
/* 8EC9CC 80240BAC 00000000 */   nop
.L80240BB0:
/* 8EC9D0 80240BB0 0000A82D */  daddu     $s5, $zero, $zero
/* 8EC9D4 80240BB4 02A0902D */  daddu     $s2, $s5, $zero
/* 8EC9D8 80240BB8 24160001 */  addiu     $s6, $zero, 1
/* 8EC9DC 80240BBC 3C1E8008 */  lui       $fp, %hi(D_80082388)
/* 8EC9E0 80240BC0 27DE2388 */  addiu     $fp, $fp, %lo(D_80082388)
/* 8EC9E4 80240BC4 3C138024 */  lui       $s3, %hi(D_80244FA0_8F0DC0)
/* 8EC9E8 80240BC8 26734FA0 */  addiu     $s3, $s3, %lo(D_80244FA0_8F0DC0)
/* 8EC9EC 80240BCC 02E0882D */  daddu     $s1, $s7, $zero
.L80240BD0:
/* 8EC9F0 80240BD0 0000202D */  daddu     $a0, $zero, $zero
/* 8EC9F4 80240BD4 3C05F5DE */  lui       $a1, 0xf5de
/* 8EC9F8 80240BD8 0C0B1EAF */  jal       get_variable
/* 8EC9FC 80240BDC 34A50180 */   ori      $a1, $a1, 0x180
/* 8ECA00 80240BE0 8E630000 */  lw        $v1, ($s3)
/* 8ECA04 80240BE4 0043102A */  slt       $v0, $v0, $v1
/* 8ECA08 80240BE8 54400019 */  bnel      $v0, $zero, .L80240C50
/* 8ECA0C 80240BEC 26520001 */   addiu    $s2, $s2, 1
/* 8ECA10 80240BF0 0240802D */  daddu     $s0, $s2, $zero
/* 8ECA14 80240BF4 3C068008 */  lui       $a2, %hi(D_80082358)
/* 8ECA18 80240BF8 24C62358 */  addiu     $a2, $a2, %lo(D_80082358)
/* 8ECA1C 80240BFC AE260000 */  sw        $a2, ($s1)
/* 8ECA20 80240C00 AE320108 */  sw        $s2, 0x108($s1)
/* 8ECA24 80240C04 AE36018C */  sw        $s6, 0x18c($s1)
/* 8ECA28 80240C08 AE200084 */  sw        $zero, 0x84($s1)
/* 8ECA2C 80240C0C 06410002 */  bgez      $s2, .L80240C18
/* 8ECA30 80240C10 AE200294 */   sw       $zero, 0x294($s1)
/* 8ECA34 80240C14 26500007 */  addiu     $s0, $s2, 7
.L80240C18:
/* 8ECA38 80240C18 001080C3 */  sra       $s0, $s0, 3
/* 8ECA3C 80240C1C 0C05154E */  jal       get_global_byte
/* 8ECA40 80240C20 2604000C */   addiu    $a0, $s0, 0xc
/* 8ECA44 80240C24 001080C0 */  sll       $s0, $s0, 3
/* 8ECA48 80240C28 02508023 */  subu      $s0, $s2, $s0
/* 8ECA4C 80240C2C 02168004 */  sllv      $s0, $s6, $s0
/* 8ECA50 80240C30 00502824 */  and       $a1, $v0, $s0
/* 8ECA54 80240C34 10A00003 */  beqz      $a1, .L80240C44
/* 8ECA58 80240C38 AE200210 */   sw       $zero, 0x210($s1)
/* 8ECA5C 80240C3C AE360210 */  sw        $s6, 0x210($s1)
/* 8ECA60 80240C40 AE3E0000 */  sw        $fp, ($s1)
.L80240C44:
/* 8ECA64 80240C44 26310004 */  addiu     $s1, $s1, 4
/* 8ECA68 80240C48 26B50001 */  addiu     $s5, $s5, 1
/* 8ECA6C 80240C4C 26520001 */  addiu     $s2, $s2, 1
.L80240C50:
/* 8ECA70 80240C50 2A42000C */  slti      $v0, $s2, 0xc
/* 8ECA74 80240C54 1440FFDE */  bnez      $v0, .L80240BD0
/* 8ECA78 80240C58 26730004 */   addiu    $s3, $s3, 4
/* 8ECA7C 80240C5C 16A00004 */  bnez      $s5, .L80240C70
/* 8ECA80 80240C60 2402000A */   addiu    $v0, $zero, 0xa
/* 8ECA84 80240C64 AE800084 */  sw        $zero, 0x84($s4)
/* 8ECA88 80240C68 0809035D */  j         .L80240D74
/* 8ECA8C 80240C6C 24020002 */   addiu    $v0, $zero, 2
.L80240C70:
/* 8ECA90 80240C70 AEE20318 */  sw        $v0, 0x318($s7)
/* 8ECA94 80240C74 AEF50324 */  sw        $s5, 0x324($s7)
/* 8ECA98 80240C78 8E82007C */  lw        $v0, 0x7c($s4)
/* 8ECA9C 80240C7C 02E0202D */  daddu     $a0, $s7, $zero
/* 8ECAA0 80240C80 0C03D390 */  jal       btl_create_popup_menu
/* 8ECAA4 80240C84 AC820328 */   sw       $v0, 0x328($a0)
/* 8ECAA8 80240C88 0C03A631 */  jal       func_800E98C4
/* 8ECAAC 80240C8C 00000000 */   nop
/* 8ECAB0 80240C90 0C03A5EE */  jal       close_status_menu
/* 8ECAB4 80240C94 00000000 */   nop
/* 8ECAB8 80240C98 24020001 */  addiu     $v0, $zero, 1
/* 8ECABC 80240C9C AE800074 */  sw        $zero, 0x74($s4)
/* 8ECAC0 80240CA0 0809035C */  j         .L80240D70
/* 8ECAC4 80240CA4 AE820070 */   sw       $v0, 0x70($s4)
.L80240CA8:
/* 8ECAC8 80240CA8 8E820074 */  lw        $v0, 0x74($s4)
/* 8ECACC 80240CAC 14400008 */  bnez      $v0, .L80240CD0
/* 8ECAD0 80240CB0 24420001 */   addiu    $v0, $v0, 1
/* 8ECAD4 80240CB4 86E2032C */  lh        $v0, 0x32c($s7)
/* 8ECAD8 80240CB8 1040002D */  beqz      $v0, .L80240D70
/* 8ECADC 80240CBC AE820078 */   sw       $v0, 0x78($s4)
/* 8ECAE0 80240CC0 0C03C4EC */  jal       hide_popup_menu
/* 8ECAE4 80240CC4 00000000 */   nop
/* 8ECAE8 80240CC8 8E820074 */  lw        $v0, 0x74($s4)
/* 8ECAEC 80240CCC 24420001 */  addiu     $v0, $v0, 1
.L80240CD0:
/* 8ECAF0 80240CD0 AE820074 */  sw        $v0, 0x74($s4)
/* 8ECAF4 80240CD4 2842000F */  slti      $v0, $v0, 0xf
/* 8ECAF8 80240CD8 14400026 */  bnez      $v0, .L80240D74
/* 8ECAFC 80240CDC 0000102D */   daddu    $v0, $zero, $zero
/* 8ECB00 80240CE0 0C03C54E */  jal       destroy_popup_menu
/* 8ECB04 80240CE4 00000000 */   nop
/* 8ECB08 80240CE8 8E830078 */  lw        $v1, 0x78($s4)
/* 8ECB0C 80240CEC 240200FF */  addiu     $v0, $zero, 0xff
/* 8ECB10 80240CF0 14620005 */  bne       $v1, $v0, .L80240D08
/* 8ECB14 80240CF4 2463FFFF */   addiu    $v1, $v1, -1
/* 8ECB18 80240CF8 2402FFFF */  addiu     $v0, $zero, -1
/* 8ECB1C 80240CFC AE820084 */  sw        $v0, 0x84($s4)
/* 8ECB20 80240D00 0809035D */  j         .L80240D74
/* 8ECB24 80240D04 24020002 */   addiu    $v0, $zero, 2
.L80240D08:
/* 8ECB28 80240D08 8E820078 */  lw        $v0, 0x78($s4)
/* 8ECB2C 80240D0C AE83007C */  sw        $v1, 0x7c($s4)
/* 8ECB30 80240D10 2442FFFF */  addiu     $v0, $v0, -1
/* 8ECB34 80240D14 00021080 */  sll       $v0, $v0, 2
/* 8ECB38 80240D18 00571021 */  addu      $v0, $v0, $s7
/* 8ECB3C 80240D1C 8C510108 */  lw        $s1, 0x108($v0)
/* 8ECB40 80240D20 00111080 */  sll       $v0, $s1, 2
/* 8ECB44 80240D24 3C018024 */  lui       $at, %hi(D_80244FD0_8F0DF0)
/* 8ECB48 80240D28 00220821 */  addu      $at, $at, $v0
/* 8ECB4C 80240D2C 8C224FD0 */  lw        $v0, %lo(D_80244FD0_8F0DF0)($at)
/* 8ECB50 80240D30 0220802D */  daddu     $s0, $s1, $zero
/* 8ECB54 80240D34 06210002 */  bgez      $s1, .L80240D40
/* 8ECB58 80240D38 AE820084 */   sw       $v0, 0x84($s4)
/* 8ECB5C 80240D3C 26300007 */  addiu     $s0, $s1, 7
.L80240D40:
/* 8ECB60 80240D40 001080C3 */  sra       $s0, $s0, 3
/* 8ECB64 80240D44 2612000C */  addiu     $s2, $s0, 0xc
/* 8ECB68 80240D48 0C05154E */  jal       get_global_byte
/* 8ECB6C 80240D4C 0240202D */   daddu    $a0, $s2, $zero
/* 8ECB70 80240D50 001080C0 */  sll       $s0, $s0, 3
/* 8ECB74 80240D54 02308023 */  subu      $s0, $s1, $s0
/* 8ECB78 80240D58 02138004 */  sllv      $s0, $s3, $s0
/* 8ECB7C 80240D5C 00502825 */  or        $a1, $v0, $s0
/* 8ECB80 80240D60 0C051548 */  jal       set_global_byte
/* 8ECB84 80240D64 0240202D */   daddu    $a0, $s2, $zero
/* 8ECB88 80240D68 0809035D */  j         .L80240D74
/* 8ECB8C 80240D6C 24020002 */   addiu    $v0, $zero, 2
.L80240D70:
/* 8ECB90 80240D70 0000102D */  daddu     $v0, $zero, $zero
.L80240D74:
/* 8ECB94 80240D74 8FBF0034 */  lw        $ra, 0x34($sp)
/* 8ECB98 80240D78 8FBE0030 */  lw        $fp, 0x30($sp)
/* 8ECB9C 80240D7C 8FB7002C */  lw        $s7, 0x2c($sp)
/* 8ECBA0 80240D80 8FB60028 */  lw        $s6, 0x28($sp)
/* 8ECBA4 80240D84 8FB50024 */  lw        $s5, 0x24($sp)
/* 8ECBA8 80240D88 8FB40020 */  lw        $s4, 0x20($sp)
/* 8ECBAC 80240D8C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 8ECBB0 80240D90 8FB20018 */  lw        $s2, 0x18($sp)
/* 8ECBB4 80240D94 8FB10014 */  lw        $s1, 0x14($sp)
/* 8ECBB8 80240D98 8FB00010 */  lw        $s0, 0x10($sp)
/* 8ECBBC 80240D9C 03E00008 */  jr        $ra
/* 8ECBC0 80240DA0 27BD0038 */   addiu    $sp, $sp, 0x38
