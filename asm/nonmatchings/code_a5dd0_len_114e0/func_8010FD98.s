.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8010FD98
/* A6498 8010FD98 00A0382D */  daddu     $a3, $a1, $zero
/* A649C 8010FD9C 28E200FF */  slti      $v0, $a3, 0xff
/* A64A0 8010FDA0 14400016 */  bnez      $v0, .L8010FDFC
/* A64A4 8010FDA4 3C06FCFF */   lui      $a2, 0xfcff
/* A64A8 8010FDA8 3C07E200 */  lui       $a3, 0xe200
/* A64AC 8010FDAC 34E7001C */  ori       $a3, $a3, 0x1c
/* A64B0 8010FDB0 3C050055 */  lui       $a1, 0x55
/* A64B4 8010FDB4 34A52078 */  ori       $a1, $a1, 0x2078
/* A64B8 8010FDB8 3C08FC12 */  lui       $t0, 0xfc12
/* A64BC 8010FDBC 35081824 */  ori       $t0, $t0, 0x1824
/* A64C0 8010FDC0 3C06FF33 */  lui       $a2, 0xff33
/* A64C4 8010FDC4 3C04800A */  lui       $a0, 0x800a
/* A64C8 8010FDC8 2484A66C */  addiu     $a0, $a0, -0x5994
/* A64CC 8010FDCC 8C820000 */  lw        $v0, ($a0)
/* A64D0 8010FDD0 34C6FFFF */  ori       $a2, $a2, 0xffff
/* A64D4 8010FDD4 0040182D */  daddu     $v1, $v0, $zero
/* A64D8 8010FDD8 24420008 */  addiu     $v0, $v0, 8
/* A64DC 8010FDDC AC820000 */  sw        $v0, ($a0)
/* A64E0 8010FDE0 AC670000 */  sw        $a3, ($v1)
/* A64E4 8010FDE4 AC650004 */  sw        $a1, 4($v1)
/* A64E8 8010FDE8 24430008 */  addiu     $v1, $v0, 8
/* A64EC 8010FDEC AC830000 */  sw        $v1, ($a0)
/* A64F0 8010FDF0 AC480000 */  sw        $t0, ($v0)
/* A64F4 8010FDF4 03E00008 */  jr        $ra
/* A64F8 8010FDF8 AC460004 */   sw       $a2, 4($v0)
.L8010FDFC:
/* A64FC 8010FDFC 34C6B3FF */  ori       $a2, $a2, 0xb3ff
/* A6500 8010FE00 3C05FF2C */  lui       $a1, 0xff2c
/* A6504 8010FE04 3C04800A */  lui       $a0, 0x800a
/* A6508 8010FE08 2484A66C */  addiu     $a0, $a0, -0x5994
/* A650C 8010FE0C 8C820000 */  lw        $v0, ($a0)
/* A6510 8010FE10 34A5FE7F */  ori       $a1, $a1, 0xfe7f
/* A6514 8010FE14 0040182D */  daddu     $v1, $v0, $zero
/* A6518 8010FE18 24420008 */  addiu     $v0, $v0, 8
/* A651C 8010FE1C AC820000 */  sw        $v0, ($a0)
/* A6520 8010FE20 AC660000 */  sw        $a2, ($v1)
/* A6524 8010FE24 AC650004 */  sw        $a1, 4($v1)
/* A6528 8010FE28 24430008 */  addiu     $v1, $v0, 8
/* A652C 8010FE2C AC830000 */  sw        $v1, ($a0)
/* A6530 8010FE30 3C03FA00 */  lui       $v1, 0xfa00
/* A6534 8010FE34 AC430000 */  sw        $v1, ($v0)
/* A6538 8010FE38 30E300FF */  andi      $v1, $a3, 0xff
/* A653C 8010FE3C 03E00008 */  jr        $ra
/* A6540 8010FE40 AC430004 */   sw       $v1, 4($v0)
