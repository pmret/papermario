.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_80243010_A670A0
.word L80241BEC_A65C7C, L80241BF8_A65C88, L80241BF8_A65C88, L80241BF8_A65C88, L80241BF8_A65C88, L80241BF8_A65C88, L80241BF8_A65C88, L80241BF8_A65C88, L80241BEC_A65C7C, L80241BF8_A65C88, L80241BEC_A65C7C, L80241BF8_A65C88, L80241BEC_A65C7C, L80241BF8_A65C88, L80241BEC_A65C7C, L80241BF8_A65C88, L80241BF8_A65C88, L80241BF8_A65C88, L80241BEC_A65C7C, L80241BF8_A65C88, L80241BEC_A65C7C, 0, 0, 0

.section .text

glabel func_802417E0_A65870
/* A65870 802417E0 27BDFF90 */  addiu     $sp, $sp, -0x70
/* A65874 802417E4 AFB3005C */  sw        $s3, 0x5c($sp)
/* A65878 802417E8 0080982D */  daddu     $s3, $a0, $zero
/* A6587C 802417EC AFBF0068 */  sw        $ra, 0x68($sp)
/* A65880 802417F0 AFB50064 */  sw        $s5, 0x64($sp)
/* A65884 802417F4 AFB40060 */  sw        $s4, 0x60($sp)
/* A65888 802417F8 AFB20058 */  sw        $s2, 0x58($sp)
/* A6588C 802417FC AFB10054 */  sw        $s1, 0x54($sp)
/* A65890 80241800 AFB00050 */  sw        $s0, 0x50($sp)
/* A65894 80241804 8E710148 */  lw        $s1, 0x148($s3)
/* A65898 80241808 86240008 */  lh        $a0, 8($s1)
/* A6589C 8024180C 0C00EABB */  jal       get_npc_unsafe
/* A658A0 80241810 00A0802D */   daddu    $s0, $a1, $zero
/* A658A4 80241814 8E63000C */  lw        $v1, 0xc($s3)
/* A658A8 80241818 0260202D */  daddu     $a0, $s3, $zero
/* A658AC 8024181C 8C650000 */  lw        $a1, ($v1)
/* A658B0 80241820 0C0B1EAF */  jal       get_variable
/* A658B4 80241824 0040902D */   daddu    $s2, $v0, $zero
/* A658B8 80241828 AFA00028 */  sw        $zero, 0x28($sp)
/* A658BC 8024182C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A658C0 80241830 8C630030 */  lw        $v1, 0x30($v1)
/* A658C4 80241834 AFA3002C */  sw        $v1, 0x2c($sp)
/* A658C8 80241838 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A658CC 8024183C 8C63001C */  lw        $v1, 0x1c($v1)
/* A658D0 80241840 AFA30030 */  sw        $v1, 0x30($sp)
/* A658D4 80241844 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A658D8 80241848 8C630024 */  lw        $v1, 0x24($v1)
/* A658DC 8024184C AFA30034 */  sw        $v1, 0x34($sp)
/* A658E0 80241850 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A658E4 80241854 8C630028 */  lw        $v1, 0x28($v1)
/* A658E8 80241858 27B50028 */  addiu     $s5, $sp, 0x28
/* A658EC 8024185C AFA30038 */  sw        $v1, 0x38($sp)
/* A658F0 80241860 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A658F4 80241864 3C0142C8 */  lui       $at, 0x42c8
/* A658F8 80241868 44810000 */  mtc1      $at, $f0
/* A658FC 8024186C 8C63002C */  lw        $v1, 0x2c($v1)
/* A65900 80241870 0040A02D */  daddu     $s4, $v0, $zero
/* A65904 80241874 E7A00040 */  swc1      $f0, 0x40($sp)
/* A65908 80241878 A7A00044 */  sh        $zero, 0x44($sp)
/* A6590C 8024187C 12000009 */  beqz      $s0, .L802418A4
/* A65910 80241880 AFA3003C */   sw       $v1, 0x3c($sp)
/* A65914 80241884 864300A8 */  lh        $v1, 0xa8($s2)
/* A65918 80241888 8E2200B0 */  lw        $v0, 0xb0($s1)
/* A6591C 8024188C AE20008C */  sw        $zero, 0x8c($s1)
/* A65920 80241890 A22000B5 */  sb        $zero, 0xb5($s1)
/* A65924 80241894 34420008 */  ori       $v0, $v0, 8
/* A65928 80241898 AE230084 */  sw        $v1, 0x84($s1)
/* A6592C 8024189C 0809062D */  j         .L802418B4
/* A65930 802418A0 AE2200B0 */   sw       $v0, 0xb0($s1)
.L802418A4:
/* A65934 802418A4 8E2200B0 */  lw        $v0, 0xb0($s1)
/* A65938 802418A8 30420004 */  andi      $v0, $v0, 4
/* A6593C 802418AC 10400047 */  beqz      $v0, .L802419CC
/* A65940 802418B0 00000000 */   nop
.L802418B4:
/* A65944 802418B4 AE600070 */  sw        $zero, 0x70($s3)
/* A65948 802418B8 A640008E */  sh        $zero, 0x8e($s2)
/* A6594C 802418BC 8E2300CC */  lw        $v1, 0xcc($s1)
/* A65950 802418C0 2404F7FF */  addiu     $a0, $zero, -0x801
/* A65954 802418C4 A2200007 */  sb        $zero, 7($s1)
/* A65958 802418C8 8E420000 */  lw        $v0, ($s2)
/* A6595C 802418CC 8C630000 */  lw        $v1, ($v1)
/* A65960 802418D0 00441024 */  and       $v0, $v0, $a0
/* A65964 802418D4 AE420000 */  sw        $v0, ($s2)
/* A65968 802418D8 AE430028 */  sw        $v1, 0x28($s2)
/* A6596C 802418DC 96220086 */  lhu       $v0, 0x86($s1)
/* A65970 802418E0 A64200A8 */  sh        $v0, 0xa8($s2)
/* A65974 802418E4 8E2200D0 */  lw        $v0, 0xd0($s1)
/* A65978 802418E8 AE200090 */  sw        $zero, 0x90($s1)
/* A6597C 802418EC 8C420034 */  lw        $v0, 0x34($v0)
/* A65980 802418F0 14400006 */  bnez      $v0, .L8024190C
/* A65984 802418F4 2403FDFF */   addiu    $v1, $zero, -0x201
/* A65988 802418F8 8E420000 */  lw        $v0, ($s2)
/* A6598C 802418FC 2403FFF7 */  addiu     $v1, $zero, -9
/* A65990 80241900 34420200 */  ori       $v0, $v0, 0x200
/* A65994 80241904 08090646 */  j         .L80241918
/* A65998 80241908 00431024 */   and      $v0, $v0, $v1
.L8024190C:
/* A6599C 8024190C 8E420000 */  lw        $v0, ($s2)
/* A659A0 80241910 00431024 */  and       $v0, $v0, $v1
/* A659A4 80241914 34420008 */  ori       $v0, $v0, 8
.L80241918:
/* A659A8 80241918 AE420000 */  sw        $v0, ($s2)
/* A659AC 8024191C 8E2200B0 */  lw        $v0, 0xb0($s1)
/* A659B0 80241920 30420004 */  andi      $v0, $v0, 4
/* A659B4 80241924 1040001E */  beqz      $v0, .L802419A0
/* A659B8 80241928 24040002 */   addiu    $a0, $zero, 2
/* A659BC 8024192C 0240282D */  daddu     $a1, $s2, $zero
/* A659C0 80241930 0000302D */  daddu     $a2, $zero, $zero
/* A659C4 80241934 24020063 */  addiu     $v0, $zero, 0x63
/* A659C8 80241938 AE620070 */  sw        $v0, 0x70($s3)
/* A659CC 8024193C AE600074 */  sw        $zero, 0x74($s3)
/* A659D0 80241940 864300A8 */  lh        $v1, 0xa8($s2)
/* A659D4 80241944 3C013F80 */  lui       $at, 0x3f80
/* A659D8 80241948 44810000 */  mtc1      $at, $f0
/* A659DC 8024194C 3C014000 */  lui       $at, 0x4000
/* A659E0 80241950 44811000 */  mtc1      $at, $f2
/* A659E4 80241954 3C01C1A0 */  lui       $at, 0xc1a0
/* A659E8 80241958 44812000 */  mtc1      $at, $f4
/* A659EC 8024195C 24020028 */  addiu     $v0, $zero, 0x28
/* A659F0 80241960 AFA2001C */  sw        $v0, 0x1c($sp)
/* A659F4 80241964 44833000 */  mtc1      $v1, $f6
/* A659F8 80241968 00000000 */  nop
/* A659FC 8024196C 468031A0 */  cvt.s.w   $f6, $f6
/* A65A00 80241970 44073000 */  mfc1      $a3, $f6
/* A65A04 80241974 27A20048 */  addiu     $v0, $sp, 0x48
/* A65A08 80241978 AFA20020 */  sw        $v0, 0x20($sp)
/* A65A0C 8024197C E7A00010 */  swc1      $f0, 0x10($sp)
/* A65A10 80241980 E7A20014 */  swc1      $f2, 0x14($sp)
/* A65A14 80241984 0C01BFA4 */  jal       fx_emote
/* A65A18 80241988 E7A40018 */   swc1     $f4, 0x18($sp)
/* A65A1C 8024198C 8E2200B0 */  lw        $v0, 0xb0($s1)
/* A65A20 80241990 2403FFFB */  addiu     $v1, $zero, -5
/* A65A24 80241994 00431024 */  and       $v0, $v0, $v1
/* A65A28 80241998 08090673 */  j         .L802419CC
/* A65A2C 8024199C AE2200B0 */   sw       $v0, 0xb0($s1)
.L802419A0:
/* A65A30 802419A0 8E220000 */  lw        $v0, ($s1)
/* A65A34 802419A4 3C034000 */  lui       $v1, 0x4000
/* A65A38 802419A8 00431024 */  and       $v0, $v0, $v1
/* A65A3C 802419AC 10400007 */  beqz      $v0, .L802419CC
/* A65A40 802419B0 3C03BFFF */   lui      $v1, 0xbfff
/* A65A44 802419B4 2402000C */  addiu     $v0, $zero, 0xc
/* A65A48 802419B8 AE620070 */  sw        $v0, 0x70($s3)
/* A65A4C 802419BC 8E220000 */  lw        $v0, ($s1)
/* A65A50 802419C0 3463FFFF */  ori       $v1, $v1, 0xffff
/* A65A54 802419C4 00431024 */  and       $v0, $v0, $v1
/* A65A58 802419C8 AE220000 */  sw        $v0, ($s1)
.L802419CC:
/* A65A5C 802419CC 8E220090 */  lw        $v0, 0x90($s1)
/* A65A60 802419D0 1840000C */  blez      $v0, .L80241A04
/* A65A64 802419D4 2442FFFF */   addiu    $v0, $v0, -1
/* A65A68 802419D8 14400087 */  bnez      $v0, L80241BF8_A65C88
/* A65A6C 802419DC AE220090 */   sw       $v0, 0x90($s1)
/* A65A70 802419E0 3C03FFAA */  lui       $v1, 0xffaa
/* A65A74 802419E4 8E420028 */  lw        $v0, 0x28($s2)
/* A65A78 802419E8 3463FFD2 */  ori       $v1, $v1, 0xffd2
/* A65A7C 802419EC 00431021 */  addu      $v0, $v0, $v1
/* A65A80 802419F0 2C420002 */  sltiu     $v0, $v0, 2
/* A65A84 802419F4 10400003 */  beqz      $v0, .L80241A04
/* A65A88 802419F8 3C020055 */   lui      $v0, 0x55
/* A65A8C 802419FC 3442000C */  ori       $v0, $v0, 0xc
/* A65A90 80241A00 AE420028 */  sw        $v0, 0x28($s2)
.L80241A04:
/* A65A94 80241A04 8E630070 */  lw        $v1, 0x70($s3)
/* A65A98 80241A08 2402000C */  addiu     $v0, $zero, 0xc
/* A65A9C 80241A0C 10620048 */  beq       $v1, $v0, .L80241B30
/* A65AA0 80241A10 2862000D */   slti     $v0, $v1, 0xd
/* A65AA4 80241A14 1040000F */  beqz      $v0, .L80241A54
/* A65AA8 80241A18 24100001 */   addiu    $s0, $zero, 1
/* A65AAC 80241A1C 1070001E */  beq       $v1, $s0, .L80241A98
/* A65AB0 80241A20 28620002 */   slti     $v0, $v1, 2
/* A65AB4 80241A24 10400005 */  beqz      $v0, .L80241A3C
/* A65AB8 80241A28 24020002 */   addiu    $v0, $zero, 2
/* A65ABC 80241A2C 10600015 */  beqz      $v1, .L80241A84
/* A65AC0 80241A30 0260202D */   daddu    $a0, $s3, $zero
/* A65AC4 80241A34 080906E3 */  j         .L80241B8C
/* A65AC8 80241A38 00000000 */   nop
.L80241A3C:
/* A65ACC 80241A3C 1062001C */  beq       $v1, $v0, .L80241AB0
/* A65AD0 80241A40 24020003 */   addiu    $v0, $zero, 3
/* A65AD4 80241A44 10620035 */  beq       $v1, $v0, .L80241B1C
/* A65AD8 80241A48 0260202D */   daddu    $a0, $s3, $zero
/* A65ADC 80241A4C 080906E3 */  j         .L80241B8C
/* A65AE0 80241A50 00000000 */   nop
.L80241A54:
/* A65AE4 80241A54 2402000E */  addiu     $v0, $zero, 0xe
/* A65AE8 80241A58 1062003F */  beq       $v1, $v0, .L80241B58
/* A65AEC 80241A5C 0062102A */   slt      $v0, $v1, $v0
/* A65AF0 80241A60 14400038 */  bnez      $v0, .L80241B44
/* A65AF4 80241A64 0260202D */   daddu    $a0, $s3, $zero
/* A65AF8 80241A68 2402000F */  addiu     $v0, $zero, 0xf
/* A65AFC 80241A6C 10620040 */  beq       $v1, $v0, .L80241B70
/* A65B00 80241A70 24020063 */   addiu    $v0, $zero, 0x63
/* A65B04 80241A74 10620043 */  beq       $v1, $v0, .L80241B84
/* A65B08 80241A78 00000000 */   nop
/* A65B0C 80241A7C 080906E3 */  j         .L80241B8C
/* A65B10 80241A80 00000000 */   nop
.L80241A84:
/* A65B14 80241A84 0280282D */  daddu     $a1, $s4, $zero
/* A65B18 80241A88 0C012568 */  jal       func_800495A0
/* A65B1C 80241A8C 02A0302D */   daddu    $a2, $s5, $zero
/* A65B20 80241A90 96220086 */  lhu       $v0, 0x86($s1)
/* A65B24 80241A94 A64200A8 */  sh        $v0, 0xa8($s2)
.L80241A98:
/* A65B28 80241A98 0260202D */  daddu     $a0, $s3, $zero
/* A65B2C 80241A9C 0280282D */  daddu     $a1, $s4, $zero
/* A65B30 80241AA0 0C0125AE */  jal       func_800496B8
/* A65B34 80241AA4 02A0302D */   daddu    $a2, $s5, $zero
/* A65B38 80241AA8 080906E3 */  j         .L80241B8C
/* A65B3C 80241AAC 00000000 */   nop
.L80241AB0:
/* A65B40 80241AB0 0260202D */  daddu     $a0, $s3, $zero
/* A65B44 80241AB4 0280282D */  daddu     $a1, $s4, $zero
/* A65B48 80241AB8 0C0126D1 */  jal       base_UnkNpcAIFunc1
/* A65B4C 80241ABC 02A0302D */   daddu    $a2, $s5, $zero
/* A65B50 80241AC0 8E230088 */  lw        $v1, 0x88($s1)
/* A65B54 80241AC4 24020006 */  addiu     $v0, $zero, 6
/* A65B58 80241AC8 14620014 */  bne       $v1, $v0, .L80241B1C
/* A65B5C 80241ACC 0260202D */   daddu    $a0, $s3, $zero
/* A65B60 80241AD0 0C00A67F */  jal       rand_int
/* A65B64 80241AD4 24040064 */   addiu    $a0, $zero, 0x64
/* A65B68 80241AD8 28420021 */  slti      $v0, $v0, 0x21
/* A65B6C 80241ADC 5040000F */  beql      $v0, $zero, .L80241B1C
/* A65B70 80241AE0 0260202D */   daddu    $a0, $s3, $zero
/* A65B74 80241AE4 8E22008C */  lw        $v0, 0x8c($s1)
/* A65B78 80241AE8 10400005 */  beqz      $v0, .L80241B00
/* A65B7C 80241AEC 3C020055 */   lui      $v0, 0x55
/* A65B80 80241AF0 3442002F */  ori       $v0, $v0, 0x2f
/* A65B84 80241AF4 AE20008C */  sw        $zero, 0x8c($s1)
/* A65B88 80241AF8 080906C3 */  j         .L80241B0C
/* A65B8C 80241AFC A22000B5 */   sb       $zero, 0xb5($s1)
.L80241B00:
/* A65B90 80241B00 3442002E */  ori       $v0, $v0, 0x2e
/* A65B94 80241B04 AE30008C */  sw        $s0, 0x8c($s1)
/* A65B98 80241B08 A23000B5 */  sb        $s0, 0xb5($s1)
.L80241B0C:
/* A65B9C 80241B0C AE420028 */  sw        $v0, 0x28($s2)
/* A65BA0 80241B10 24020007 */  addiu     $v0, $zero, 7
/* A65BA4 80241B14 080906FE */  j         L80241BF8_A65C88
/* A65BA8 80241B18 AE220090 */   sw       $v0, 0x90($s1)
.L80241B1C:
/* A65BAC 80241B1C 0280282D */  daddu     $a1, $s4, $zero
/* A65BB0 80241B20 0C012701 */  jal       func_80049C04
/* A65BB4 80241B24 02A0302D */   daddu    $a2, $s5, $zero
/* A65BB8 80241B28 080906E3 */  j         .L80241B8C
/* A65BBC 80241B2C 00000000 */   nop
.L80241B30:
/* A65BC0 80241B30 0260202D */  daddu     $a0, $s3, $zero
/* A65BC4 80241B34 0280282D */  daddu     $a1, $s4, $zero
/* A65BC8 80241B38 0C090513 */  jal       kpa_51_set_script_owner_npc_anim
/* A65BCC 80241B3C 02A0302D */   daddu    $a2, $s5, $zero
/* A65BD0 80241B40 0260202D */  daddu     $a0, $s3, $zero
.L80241B44:
/* A65BD4 80241B44 0280282D */  daddu     $a1, $s4, $zero
/* A65BD8 80241B48 0C090532 */  jal       kpa_51_UnkDistFunc
/* A65BDC 80241B4C 02A0302D */   daddu    $a2, $s5, $zero
/* A65BE0 80241B50 080906E3 */  j         .L80241B8C
/* A65BE4 80241B54 00000000 */   nop
.L80241B58:
/* A65BE8 80241B58 0260202D */  daddu     $a0, $s3, $zero
/* A65BEC 80241B5C 0280282D */  daddu     $a1, $s4, $zero
/* A65BF0 80241B60 0C09057F */  jal       kpa_51_UnkNpcAIFunc12
/* A65BF4 80241B64 02A0302D */   daddu    $a2, $s5, $zero
/* A65BF8 80241B68 080906E3 */  j         .L80241B8C
/* A65BFC 80241B6C 00000000 */   nop
.L80241B70:
/* A65C00 80241B70 0280282D */  daddu     $a1, $s4, $zero
/* A65C04 80241B74 0C0905D8 */  jal       kpa_51_set_script_owner_npc_col_height
/* A65C08 80241B78 02A0302D */   daddu    $a2, $s5, $zero
/* A65C0C 80241B7C 080906E3 */  j         .L80241B8C
/* A65C10 80241B80 00000000 */   nop
.L80241B84:
/* A65C14 80241B84 0C0129CF */  jal       func_8004A73C
/* A65C18 80241B88 0260202D */   daddu    $a0, $s3, $zero
.L80241B8C:
/* A65C1C 80241B8C 8E230088 */  lw        $v1, 0x88($s1)
/* A65C20 80241B90 24020006 */  addiu     $v0, $zero, 6
/* A65C24 80241B94 14620019 */  bne       $v1, $v0, .L80241BFC
/* A65C28 80241B98 0000102D */   daddu    $v0, $zero, $zero
/* A65C2C 80241B9C 8E22008C */  lw        $v0, 0x8c($s1)
/* A65C30 80241BA0 10400003 */  beqz      $v0, .L80241BB0
/* A65C34 80241BA4 24020001 */   addiu    $v0, $zero, 1
/* A65C38 80241BA8 080906ED */  j         .L80241BB4
/* A65C3C 80241BAC A22200B5 */   sb       $v0, 0xb5($s1)
.L80241BB0:
/* A65C40 80241BB0 A22000B5 */  sb        $zero, 0xb5($s1)
.L80241BB4:
/* A65C44 80241BB4 8E22008C */  lw        $v0, 0x8c($s1)
/* A65C48 80241BB8 1040000F */  beqz      $v0, L80241BF8_A65C88
/* A65C4C 80241BBC 3C03FFAA */   lui      $v1, 0xffaa
/* A65C50 80241BC0 8E420028 */  lw        $v0, 0x28($s2)
/* A65C54 80241BC4 3463FFFC */  ori       $v1, $v1, 0xfffc
/* A65C58 80241BC8 00431821 */  addu      $v1, $v0, $v1
/* A65C5C 80241BCC 2C620015 */  sltiu     $v0, $v1, 0x15
/* A65C60 80241BD0 10400009 */  beqz      $v0, L80241BF8_A65C88
/* A65C64 80241BD4 00031080 */   sll      $v0, $v1, 2
/* A65C68 80241BD8 3C018024 */  lui       $at, %hi(jtbl_80243010_A670A0)
/* A65C6C 80241BDC 00220821 */  addu      $at, $at, $v0
/* A65C70 80241BE0 8C223010 */  lw        $v0, %lo(jtbl_80243010_A670A0)($at)
/* A65C74 80241BE4 00400008 */  jr        $v0
/* A65C78 80241BE8 00000000 */   nop
glabel L80241BEC_A65C7C
/* A65C7C 80241BEC 8E420028 */  lw        $v0, 0x28($s2)
/* A65C80 80241BF0 24420001 */  addiu     $v0, $v0, 1
/* A65C84 80241BF4 AE420028 */  sw        $v0, 0x28($s2)
glabel L80241BF8_A65C88
/* A65C88 80241BF8 0000102D */  daddu     $v0, $zero, $zero
.L80241BFC:
/* A65C8C 80241BFC 8FBF0068 */  lw        $ra, 0x68($sp)
/* A65C90 80241C00 8FB50064 */  lw        $s5, 0x64($sp)
/* A65C94 80241C04 8FB40060 */  lw        $s4, 0x60($sp)
/* A65C98 80241C08 8FB3005C */  lw        $s3, 0x5c($sp)
/* A65C9C 80241C0C 8FB20058 */  lw        $s2, 0x58($sp)
/* A65CA0 80241C10 8FB10054 */  lw        $s1, 0x54($sp)
/* A65CA4 80241C14 8FB00050 */  lw        $s0, 0x50($sp)
/* A65CA8 80241C18 03E00008 */  jr        $ra
/* A65CAC 80241C1C 27BD0070 */   addiu    $sp, $sp, 0x70
