.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003B62C
/* 16A2C 8003B62C 3084FFFF */  andi      $a0, $a0, 0xffff
/* 16A30 8003B630 000412C2 */  srl       $v0, $a0, 0xb
/* 16A34 8003B634 240700FF */  addiu     $a3, $zero, 0xff
/* 16A38 8003B638 00E63823 */  subu      $a3, $a3, $a2
/* 16A3C 8003B63C 00470018 */  mult      $v0, $a3
/* 16A40 8003B640 00004012 */  mflo      $t0
/* 16A44 8003B644 30A3FFFF */  andi      $v1, $a1, 0xffff
/* 16A48 8003B648 000312C2 */  srl       $v0, $v1, 0xb
/* 16A4C 8003B64C 00460018 */  mult      $v0, $a2
/* 16A50 8003B650 3C098080 */  lui       $t1, 0x8080
/* 16A54 8003B654 00005012 */  mflo      $t2
/* 16A58 8003B658 35298081 */  ori       $t1, $t1, 0x8081
/* 16A5C 8003B65C 010A4021 */  addu      $t0, $t0, $t2
/* 16A60 8003B660 01090018 */  mult      $t0, $t1
/* 16A64 8003B664 00006010 */  mfhi      $t4
/* 16A68 8003B668 00041182 */  srl       $v0, $a0, 6
/* 16A6C 8003B66C 3042001F */  andi      $v0, $v0, 0x1f
/* 16A70 8003B670 00470018 */  mult      $v0, $a3
/* 16A74 8003B674 00005012 */  mflo      $t2
/* 16A78 8003B678 00031182 */  srl       $v0, $v1, 6
/* 16A7C 8003B67C 3042001F */  andi      $v0, $v0, 0x1f
/* 16A80 8003B680 00460018 */  mult      $v0, $a2
/* 16A84 8003B684 00001012 */  mflo      $v0
/* 16A88 8003B688 00042042 */  srl       $a0, $a0, 1
/* 16A8C 8003B68C 3084001F */  andi      $a0, $a0, 0x1f
/* 16A90 8003B690 00870018 */  mult      $a0, $a3
/* 16A94 8003B694 00003812 */  mflo      $a3
/* 16A98 8003B698 00031842 */  srl       $v1, $v1, 1
/* 16A9C 8003B69C 3063001F */  andi      $v1, $v1, 0x1f
/* 16AA0 8003B6A0 00660018 */  mult      $v1, $a2
/* 16AA4 8003B6A4 30A50001 */  andi      $a1, $a1, 1
/* 16AA8 8003B6A8 01882021 */  addu      $a0, $t4, $t0
/* 16AAC 8003B6AC 01421021 */  addu      $v0, $t2, $v0
/* 16AB0 8003B6B0 00006812 */  mflo      $t5
/* 16AB4 8003B6B4 000421C3 */  sra       $a0, $a0, 7
/* 16AB8 8003B6B8 000847C3 */  sra       $t0, $t0, 0x1f
/* 16ABC 8003B6BC 00490018 */  mult      $v0, $t1
/* 16AC0 8003B6C0 00882023 */  subu      $a0, $a0, $t0
/* 16AC4 8003B6C4 308400FF */  andi      $a0, $a0, 0xff
/* 16AC8 8003B6C8 000422C0 */  sll       $a0, $a0, 0xb
/* 16ACC 8003B6CC 00ED3021 */  addu      $a2, $a3, $t5
/* 16AD0 8003B6D0 00001810 */  mfhi      $v1
/* 16AD4 8003B6D4 00621821 */  addu      $v1, $v1, $v0
/* 16AD8 8003B6D8 000319C3 */  sra       $v1, $v1, 7
/* 16ADC 8003B6DC 000217C3 */  sra       $v0, $v0, 0x1f
/* 16AE0 8003B6E0 00C90018 */  mult      $a2, $t1
/* 16AE4 8003B6E4 00621823 */  subu      $v1, $v1, $v0
/* 16AE8 8003B6E8 306300FF */  andi      $v1, $v1, 0xff
/* 16AEC 8003B6EC 00031980 */  sll       $v1, $v1, 6
/* 16AF0 8003B6F0 00832025 */  or        $a0, $a0, $v1
/* 16AF4 8003B6F4 00003810 */  mfhi      $a3
/* 16AF8 8003B6F8 00E61021 */  addu      $v0, $a3, $a2
/* 16AFC 8003B6FC 000211C3 */  sra       $v0, $v0, 7
/* 16B00 8003B700 000637C3 */  sra       $a2, $a2, 0x1f
/* 16B04 8003B704 00461023 */  subu      $v0, $v0, $a2
/* 16B08 8003B708 304200FF */  andi      $v0, $v0, 0xff
/* 16B0C 8003B70C 00021040 */  sll       $v0, $v0, 1
/* 16B10 8003B710 00822025 */  or        $a0, $a0, $v0
/* 16B14 8003B714 00A42825 */  or        $a1, $a1, $a0
/* 16B18 8003B718 03E00008 */  jr        $ra
/* 16B1C 8003B71C 30A2FFFF */   andi     $v0, $a1, 0xffff
