.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241AA0
/* D3C070 80241AA0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D3C074 80241AA4 AFB00010 */  sw        $s0, 0x10($sp)
/* D3C078 80241AA8 0080802D */  daddu     $s0, $a0, $zero
/* D3C07C 80241AAC AFBF0014 */  sw        $ra, 0x14($sp)
/* D3C080 80241AB0 8E0300A8 */  lw        $v1, 0xa8($s0)
/* D3C084 80241AB4 8E020088 */  lw        $v0, 0x88($s0)
/* D3C088 80241AB8 00621821 */  addu      $v1, $v1, $v0
/* D3C08C 80241ABC 04610004 */  bgez      $v1, .L80241AD0
/* D3C090 80241AC0 AE0300A8 */   sw       $v1, 0xa8($s0)
/* D3C094 80241AC4 3C020002 */  lui       $v0, 2
/* D3C098 80241AC8 080906B8 */  j         .L80241AE0
/* D3C09C 80241ACC 00621021 */   addu     $v0, $v1, $v0
.L80241AD0:
/* D3C0A0 80241AD0 3C040002 */  lui       $a0, 2
/* D3C0A4 80241AD4 0083102A */  slt       $v0, $a0, $v1
/* D3C0A8 80241AD8 10400002 */  beqz      $v0, .L80241AE4
/* D3C0AC 80241ADC 00641023 */   subu     $v0, $v1, $a0
.L80241AE0:
/* D3C0B0 80241AE0 AE0200A8 */  sw        $v0, 0xa8($s0)
.L80241AE4:
/* D3C0B4 80241AE4 8E0300AC */  lw        $v1, 0xac($s0)
/* D3C0B8 80241AE8 8E02008C */  lw        $v0, 0x8c($s0)
/* D3C0BC 80241AEC 00621821 */  addu      $v1, $v1, $v0
/* D3C0C0 80241AF0 04610004 */  bgez      $v1, .L80241B04
/* D3C0C4 80241AF4 AE0300AC */   sw       $v1, 0xac($s0)
/* D3C0C8 80241AF8 3C020002 */  lui       $v0, 2
/* D3C0CC 80241AFC 080906C5 */  j         .L80241B14
/* D3C0D0 80241B00 00621021 */   addu     $v0, $v1, $v0
.L80241B04:
/* D3C0D4 80241B04 3C040002 */  lui       $a0, 2
/* D3C0D8 80241B08 0083102A */  slt       $v0, $a0, $v1
/* D3C0DC 80241B0C 10400002 */  beqz      $v0, .L80241B18
/* D3C0E0 80241B10 00641023 */   subu     $v0, $v1, $a0
.L80241B14:
/* D3C0E4 80241B14 AE0200AC */  sw        $v0, 0xac($s0)
.L80241B18:
/* D3C0E8 80241B18 8E0300B0 */  lw        $v1, 0xb0($s0)
/* D3C0EC 80241B1C 8E020090 */  lw        $v0, 0x90($s0)
/* D3C0F0 80241B20 00621821 */  addu      $v1, $v1, $v0
/* D3C0F4 80241B24 04610004 */  bgez      $v1, .L80241B38
/* D3C0F8 80241B28 AE0300B0 */   sw       $v1, 0xb0($s0)
/* D3C0FC 80241B2C 3C020002 */  lui       $v0, 2
/* D3C100 80241B30 080906D2 */  j         .L80241B48
/* D3C104 80241B34 00621021 */   addu     $v0, $v1, $v0
.L80241B38:
/* D3C108 80241B38 3C040002 */  lui       $a0, 2
/* D3C10C 80241B3C 0083102A */  slt       $v0, $a0, $v1
/* D3C110 80241B40 10400002 */  beqz      $v0, .L80241B4C
/* D3C114 80241B44 00641023 */   subu     $v0, $v1, $a0
.L80241B48:
/* D3C118 80241B48 AE0200B0 */  sw        $v0, 0xb0($s0)
.L80241B4C:
/* D3C11C 80241B4C 8E0300B4 */  lw        $v1, 0xb4($s0)
/* D3C120 80241B50 8E020094 */  lw        $v0, 0x94($s0)
/* D3C124 80241B54 00621821 */  addu      $v1, $v1, $v0
/* D3C128 80241B58 04610004 */  bgez      $v1, .L80241B6C
/* D3C12C 80241B5C AE0300B4 */   sw       $v1, 0xb4($s0)
/* D3C130 80241B60 3C020002 */  lui       $v0, 2
/* D3C134 80241B64 080906DF */  j         .L80241B7C
/* D3C138 80241B68 00621021 */   addu     $v0, $v1, $v0
.L80241B6C:
/* D3C13C 80241B6C 3C040002 */  lui       $a0, 2
/* D3C140 80241B70 0083102A */  slt       $v0, $a0, $v1
/* D3C144 80241B74 10400002 */  beqz      $v0, .L80241B80
/* D3C148 80241B78 00641023 */   subu     $v0, $v1, $a0
.L80241B7C:
/* D3C14C 80241B7C AE0200B4 */  sw        $v0, 0xb4($s0)
.L80241B80:
/* D3C150 80241B80 8E040084 */  lw        $a0, 0x84($s0)
/* D3C154 80241B84 0C046F07 */  jal       set_main_pan_u
/* D3C158 80241B88 8E0500A8 */   lw       $a1, 0xa8($s0)
/* D3C15C 80241B8C 8E040084 */  lw        $a0, 0x84($s0)
/* D3C160 80241B90 0C046F0D */  jal       set_main_pan_v
/* D3C164 80241B94 8E0500AC */   lw       $a1, 0xac($s0)
/* D3C168 80241B98 8E040084 */  lw        $a0, 0x84($s0)
/* D3C16C 80241B9C 0C046F13 */  jal       set_aux_pan_u
/* D3C170 80241BA0 8E0500B0 */   lw       $a1, 0xb0($s0)
/* D3C174 80241BA4 8E040084 */  lw        $a0, 0x84($s0)
/* D3C178 80241BA8 0C046F19 */  jal       set_aux_pan_v
/* D3C17C 80241BAC 8E0500B4 */   lw       $a1, 0xb4($s0)
/* D3C180 80241BB0 8FBF0014 */  lw        $ra, 0x14($sp)
/* D3C184 80241BB4 8FB00010 */  lw        $s0, 0x10($sp)
/* D3C188 80241BB8 0000102D */  daddu     $v0, $zero, $zero
/* D3C18C 80241BBC 03E00008 */  jr        $ra
/* D3C190 80241BC0 27BD0018 */   addiu    $sp, $sp, 0x18
