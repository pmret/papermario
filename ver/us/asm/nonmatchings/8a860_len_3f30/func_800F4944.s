.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_8010C8E0
.word L800F4994_8DE44, L800F49B0_8DE60, L800F49E4_8DE94, L800F4A18_8DEC8, L800F4A4C_8DEFC, L800F4A80_8DF30, L800F4AA0_8DF50, L800F4ABC_8DF6C, L800F4B0C_8DFBC, L800F4B40_8DFF0, L800F4B5C_8E00C, L800F4B90_8E040, L800F4BC4_8E074, L800F4AD8_8DF88, 0, 0

.section .text

glabel func_800F4944
/* 8DDF4 800F4944 3C028011 */  lui       $v0, %hi(D_8010D68E)
/* 8DDF8 800F4948 8042D68E */  lb        $v0, %lo(D_8010D68E)($v0)
/* 8DDFC 800F494C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 8DE00 800F4950 AFB00018 */  sw        $s0, 0x18($sp)
/* 8DE04 800F4954 00A0802D */  daddu     $s0, $a1, $zero
/* 8DE08 800F4958 AFB1001C */  sw        $s1, 0x1c($sp)
/* 8DE0C 800F495C 24D10007 */  addiu     $s1, $a2, 7
/* 8DE10 800F4960 104000A9 */  beqz      $v0, .L800F4C08
/* 8DE14 800F4964 AFBF0020 */   sw       $ra, 0x20($sp)
/* 8DE18 800F4968 3C028011 */  lui       $v0, %hi(D_8010D69C)
/* 8DE1C 800F496C 8C42D69C */  lw        $v0, %lo(D_8010D69C)($v0)
/* 8DE20 800F4970 8C430318 */  lw        $v1, 0x318($v0)
/* 8DE24 800F4974 2C62000E */  sltiu     $v0, $v1, 0xe
/* 8DE28 800F4978 104000A3 */  beqz      $v0, .L800F4C08
/* 8DE2C 800F497C 00031080 */   sll      $v0, $v1, 2
/* 8DE30 800F4980 3C018011 */  lui       $at, %hi(jtbl_8010C8E0)
/* 8DE34 800F4984 00220821 */  addu      $at, $at, $v0
/* 8DE38 800F4988 8C22C8E0 */  lw        $v0, %lo(jtbl_8010C8E0)($at)
/* 8DE3C 800F498C 00400008 */  jr        $v0
/* 8DE40 800F4990 00000000 */   nop
glabel L800F4994_8DE44
/* 8DE44 800F4994 3C04001D */  lui       $a0, 0x1d
/* 8DE48 800F4998 34840061 */  ori       $a0, $a0, 0x61
/* 8DE4C 800F499C 0C04991D */  jal       get_string_width
/* 8DE50 800F49A0 0000282D */   daddu    $a1, $zero, $zero
/* 8DE54 800F49A4 3C04001D */  lui       $a0, 0x1d
/* 8DE58 800F49A8 0803D2F7 */  j         .L800F4BDC
/* 8DE5C 800F49AC 34840061 */   ori      $a0, $a0, 0x61
glabel L800F49B0_8DE60
/* 8DE60 800F49B0 3C04001D */  lui       $a0, 0x1d
/* 8DE64 800F49B4 34840063 */  ori       $a0, $a0, 0x63
/* 8DE68 800F49B8 0C04991D */  jal       get_string_width
/* 8DE6C 800F49BC 0000282D */   daddu    $a1, $zero, $zero
/* 8DE70 800F49C0 3C04001D */  lui       $a0, 0x1d
/* 8DE74 800F49C4 34840063 */  ori       $a0, $a0, 0x63
/* 8DE78 800F49C8 26050048 */  addiu     $a1, $s0, 0x48
/* 8DE7C 800F49CC 00021FC2 */  srl       $v1, $v0, 0x1f
/* 8DE80 800F49D0 00621821 */  addu      $v1, $v1, $v0
/* 8DE84 800F49D4 00031843 */  sra       $v1, $v1, 1
/* 8DE88 800F49D8 00A32823 */  subu      $a1, $a1, $v1
/* 8DE8C 800F49DC 0803D2FD */  j         .L800F4BF4
/* 8DE90 800F49E0 2626FFFC */   addiu    $a2, $s1, -4
glabel L800F49E4_8DE94
/* 8DE94 800F49E4 3C04001D */  lui       $a0, 0x1d
/* 8DE98 800F49E8 34840064 */  ori       $a0, $a0, 0x64
/* 8DE9C 800F49EC 0C04991D */  jal       get_string_width
/* 8DEA0 800F49F0 0000282D */   daddu    $a1, $zero, $zero
/* 8DEA4 800F49F4 3C04001D */  lui       $a0, 0x1d
/* 8DEA8 800F49F8 34840064 */  ori       $a0, $a0, 0x64
/* 8DEAC 800F49FC 26050048 */  addiu     $a1, $s0, 0x48
/* 8DEB0 800F4A00 00021FC2 */  srl       $v1, $v0, 0x1f
/* 8DEB4 800F4A04 00621821 */  addu      $v1, $v1, $v0
/* 8DEB8 800F4A08 00031843 */  sra       $v1, $v1, 1
/* 8DEBC 800F4A0C 00A32823 */  subu      $a1, $a1, $v1
/* 8DEC0 800F4A10 0803D2FD */  j         .L800F4BF4
/* 8DEC4 800F4A14 2626FFFC */   addiu    $a2, $s1, -4
glabel L800F4A18_8DEC8
/* 8DEC8 800F4A18 3C04001D */  lui       $a0, 0x1d
/* 8DECC 800F4A1C 34840070 */  ori       $a0, $a0, 0x70
/* 8DED0 800F4A20 0C04991D */  jal       get_string_width
/* 8DED4 800F4A24 0000282D */   daddu    $a1, $zero, $zero
/* 8DED8 800F4A28 3C04001D */  lui       $a0, 0x1d
/* 8DEDC 800F4A2C 34840070 */  ori       $a0, $a0, 0x70
/* 8DEE0 800F4A30 26050040 */  addiu     $a1, $s0, 0x40
/* 8DEE4 800F4A34 00021FC2 */  srl       $v1, $v0, 0x1f
/* 8DEE8 800F4A38 00621821 */  addu      $v1, $v1, $v0
/* 8DEEC 800F4A3C 00031843 */  sra       $v1, $v1, 1
/* 8DEF0 800F4A40 00A32823 */  subu      $a1, $a1, $v1
/* 8DEF4 800F4A44 0803D2FD */  j         .L800F4BF4
/* 8DEF8 800F4A48 2626FFFC */   addiu    $a2, $s1, -4
glabel L800F4A4C_8DEFC
/* 8DEFC 800F4A4C 3C04001D */  lui       $a0, 0x1d
/* 8DF00 800F4A50 3484006A */  ori       $a0, $a0, 0x6a
/* 8DF04 800F4A54 0C04991D */  jal       get_string_width
/* 8DF08 800F4A58 0000282D */   daddu    $a1, $zero, $zero
/* 8DF0C 800F4A5C 3C04001D */  lui       $a0, 0x1d
/* 8DF10 800F4A60 3484006A */  ori       $a0, $a0, 0x6a
/* 8DF14 800F4A64 26050044 */  addiu     $a1, $s0, 0x44
/* 8DF18 800F4A68 00021FC2 */  srl       $v1, $v0, 0x1f
/* 8DF1C 800F4A6C 00621821 */  addu      $v1, $v1, $v0
/* 8DF20 800F4A70 00031843 */  sra       $v1, $v1, 1
/* 8DF24 800F4A74 00A32823 */  subu      $a1, $a1, $v1
/* 8DF28 800F4A78 0803D2FD */  j         .L800F4BF4
/* 8DF2C 800F4A7C 2626FFFC */   addiu    $a2, $s1, -4
glabel L800F4A80_8DF30
/* 8DF30 800F4A80 3C04001D */  lui       $a0, 0x1d
/* 8DF34 800F4A84 34840065 */  ori       $a0, $a0, 0x65
/* 8DF38 800F4A88 0C04991D */  jal       get_string_width
/* 8DF3C 800F4A8C 0000282D */   daddu    $a1, $zero, $zero
/* 8DF40 800F4A90 3C04001D */  lui       $a0, 0x1d
/* 8DF44 800F4A94 34840065 */  ori       $a0, $a0, 0x65
/* 8DF48 800F4A98 0803D2F8 */  j         .L800F4BE0
/* 8DF4C 800F4A9C 2605003C */   addiu    $a1, $s0, 0x3c
glabel L800F4AA0_8DF50
/* 8DF50 800F4AA0 3C04001D */  lui       $a0, 0x1d
/* 8DF54 800F4AA4 34840066 */  ori       $a0, $a0, 0x66
/* 8DF58 800F4AA8 0C04991D */  jal       get_string_width
/* 8DF5C 800F4AAC 0000282D */   daddu    $a1, $zero, $zero
/* 8DF60 800F4AB0 3C04001D */  lui       $a0, 0x1d
/* 8DF64 800F4AB4 0803D2F7 */  j         .L800F4BDC
/* 8DF68 800F4AB8 34840066 */   ori      $a0, $a0, 0x66
glabel L800F4ABC_8DF6C
/* 8DF6C 800F4ABC 3C04001D */  lui       $a0, 0x1d
/* 8DF70 800F4AC0 34840067 */  ori       $a0, $a0, 0x67
/* 8DF74 800F4AC4 0C04991D */  jal       get_string_width
/* 8DF78 800F4AC8 0000282D */   daddu    $a1, $zero, $zero
/* 8DF7C 800F4ACC 3C04001D */  lui       $a0, 0x1d
/* 8DF80 800F4AD0 0803D2F7 */  j         .L800F4BDC
/* 8DF84 800F4AD4 34840067 */   ori      $a0, $a0, 0x67
glabel L800F4AD8_8DF88
/* 8DF88 800F4AD8 3C04001D */  lui       $a0, 0x1d
/* 8DF8C 800F4ADC 3484006F */  ori       $a0, $a0, 0x6f
/* 8DF90 800F4AE0 0C04991D */  jal       get_string_width
/* 8DF94 800F4AE4 0000282D */   daddu    $a1, $zero, $zero
/* 8DF98 800F4AE8 3C04001D */  lui       $a0, 0x1d
/* 8DF9C 800F4AEC 3484006F */  ori       $a0, $a0, 0x6f
/* 8DFA0 800F4AF0 26050048 */  addiu     $a1, $s0, 0x48
/* 8DFA4 800F4AF4 00021FC2 */  srl       $v1, $v0, 0x1f
/* 8DFA8 800F4AF8 00621821 */  addu      $v1, $v1, $v0
/* 8DFAC 800F4AFC 00031843 */  sra       $v1, $v1, 1
/* 8DFB0 800F4B00 00A32823 */  subu      $a1, $a1, $v1
/* 8DFB4 800F4B04 0803D2FD */  j         .L800F4BF4
/* 8DFB8 800F4B08 2626FFFC */   addiu    $a2, $s1, -4
glabel L800F4B0C_8DFBC
/* 8DFBC 800F4B0C 3C04001D */  lui       $a0, 0x1d
/* 8DFC0 800F4B10 3484006D */  ori       $a0, $a0, 0x6d
/* 8DFC4 800F4B14 0C04991D */  jal       get_string_width
/* 8DFC8 800F4B18 0000282D */   daddu    $a1, $zero, $zero
/* 8DFCC 800F4B1C 3C04001D */  lui       $a0, 0x1d
/* 8DFD0 800F4B20 3484006D */  ori       $a0, $a0, 0x6d
/* 8DFD4 800F4B24 26050038 */  addiu     $a1, $s0, 0x38
/* 8DFD8 800F4B28 00021FC2 */  srl       $v1, $v0, 0x1f
/* 8DFDC 800F4B2C 00621821 */  addu      $v1, $v1, $v0
/* 8DFE0 800F4B30 00031843 */  sra       $v1, $v1, 1
/* 8DFE4 800F4B34 00A32823 */  subu      $a1, $a1, $v1
/* 8DFE8 800F4B38 0803D2FD */  j         .L800F4BF4
/* 8DFEC 800F4B3C 2626FFFC */   addiu    $a2, $s1, -4
glabel L800F4B40_8DFF0
/* 8DFF0 800F4B40 3C04001D */  lui       $a0, 0x1d
/* 8DFF4 800F4B44 348400D6 */  ori       $a0, $a0, 0xd6
/* 8DFF8 800F4B48 0C04991D */  jal       get_string_width
/* 8DFFC 800F4B4C 0000282D */   daddu    $a1, $zero, $zero
/* 8E000 800F4B50 3C04001D */  lui       $a0, 0x1d
/* 8E004 800F4B54 0803D2F7 */  j         .L800F4BDC
/* 8E008 800F4B58 348400D6 */   ori      $a0, $a0, 0xd6
glabel L800F4B5C_8E00C
/* 8E00C 800F4B5C 3C04001D */  lui       $a0, 0x1d
/* 8E010 800F4B60 3484006C */  ori       $a0, $a0, 0x6c
/* 8E014 800F4B64 0C04991D */  jal       get_string_width
/* 8E018 800F4B68 0000282D */   daddu    $a1, $zero, $zero
/* 8E01C 800F4B6C 3C04001D */  lui       $a0, 0x1d
/* 8E020 800F4B70 3484006C */  ori       $a0, $a0, 0x6c
/* 8E024 800F4B74 26050040 */  addiu     $a1, $s0, 0x40
/* 8E028 800F4B78 00021FC2 */  srl       $v1, $v0, 0x1f
/* 8E02C 800F4B7C 00621821 */  addu      $v1, $v1, $v0
/* 8E030 800F4B80 00031843 */  sra       $v1, $v1, 1
/* 8E034 800F4B84 00A32823 */  subu      $a1, $a1, $v1
/* 8E038 800F4B88 0803D2FD */  j         .L800F4BF4
/* 8E03C 800F4B8C 2626FFFC */   addiu    $a2, $s1, -4
glabel L800F4B90_8E040
/* 8E040 800F4B90 3C04001D */  lui       $a0, 0x1d
/* 8E044 800F4B94 3484006D */  ori       $a0, $a0, 0x6d
/* 8E048 800F4B98 0C04991D */  jal       get_string_width
/* 8E04C 800F4B9C 0000282D */   daddu    $a1, $zero, $zero
/* 8E050 800F4BA0 3C04001D */  lui       $a0, 0x1d
/* 8E054 800F4BA4 3484006D */  ori       $a0, $a0, 0x6d
/* 8E058 800F4BA8 26050040 */  addiu     $a1, $s0, 0x40
/* 8E05C 800F4BAC 00021FC2 */  srl       $v1, $v0, 0x1f
/* 8E060 800F4BB0 00621821 */  addu      $v1, $v1, $v0
/* 8E064 800F4BB4 00031843 */  sra       $v1, $v1, 1
/* 8E068 800F4BB8 00A32823 */  subu      $a1, $a1, $v1
/* 8E06C 800F4BBC 0803D2FD */  j         .L800F4BF4
/* 8E070 800F4BC0 2626FFFC */   addiu    $a2, $s1, -4
glabel L800F4BC4_8E074
/* 8E074 800F4BC4 3C04001D */  lui       $a0, 0x1d
/* 8E078 800F4BC8 34840062 */  ori       $a0, $a0, 0x62
/* 8E07C 800F4BCC 0C04991D */  jal       get_string_width
/* 8E080 800F4BD0 0000282D */   daddu    $a1, $zero, $zero
/* 8E084 800F4BD4 3C04001D */  lui       $a0, 0x1d
/* 8E088 800F4BD8 34840062 */  ori       $a0, $a0, 0x62
.L800F4BDC:
/* 8E08C 800F4BDC 26050048 */  addiu     $a1, $s0, 0x48
.L800F4BE0:
/* 8E090 800F4BE0 00021FC2 */  srl       $v1, $v0, 0x1f
/* 8E094 800F4BE4 00621821 */  addu      $v1, $v1, $v0
/* 8E098 800F4BE8 00031843 */  sra       $v1, $v1, 1
/* 8E09C 800F4BEC 00A32823 */  subu      $a1, $a1, $v1
/* 8E0A0 800F4BF0 0220302D */  daddu     $a2, $s1, $zero
.L800F4BF4:
/* 8E0A4 800F4BF4 240700FF */  addiu     $a3, $zero, 0xff
/* 8E0A8 800F4BF8 2402000F */  addiu     $v0, $zero, 0xf
/* 8E0AC 800F4BFC AFA20010 */  sw        $v0, 0x10($sp)
/* 8E0B0 800F4C00 0C04993B */  jal       draw_string
/* 8E0B4 800F4C04 AFA00014 */   sw       $zero, 0x14($sp)
.L800F4C08:
/* 8E0B8 800F4C08 8FBF0020 */  lw        $ra, 0x20($sp)
/* 8E0BC 800F4C0C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 8E0C0 800F4C10 8FB00018 */  lw        $s0, 0x18($sp)
/* 8E0C4 800F4C14 03E00008 */  jr        $ra
/* 8E0C8 800F4C18 27BD0028 */   addiu    $sp, $sp, 0x28
