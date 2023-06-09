// SPDX-License-Identifier: Apache-2.0
// SPDX-FileCopyrightText: Gabriel Marcano, 2023

#ifndef AM1815_H_
#define AM1815_H_

#include <spi.h>

#include <stdint.h>

/** Structure representing the AM1815 RTC */
struct am1815
{
	struct spi *spi;
};

/** Initializes the RTC structure.
 *
 * @param[out] rtc RTC object to initialize
 * @param[in,out] spi The SPI object to use for communication with the
 *  physical RTC. It should already be initialized.
 */
void am1815_init(struct am1815 *rtc, struct spi *spi);

/** Reads a register from the RTC.
 *
 * @param[in] rtc RTC to read the register from.
 * @param[in] addr RTC register address to read from.
 *
 * @returns The value of the register.
 */
uint8_t am1815_read_register(struct am1815 *rtc, uint8_t addr);

/** Writes a value to a register on the RTC.
 *
 * @param[in,out] rtc RTC to write to.
 * @param[in] addr Register address to write to.
 * @param[in] data Data to write to the register.
 */
void am1815_write_register(struct am1815 *rtc, uint8_t addr, uint8_t data);

/** Enables the trickle charging of the backup battery on the RTC.
 *
 * FIXME what are the settings?
 *
 * @param[in,out] rtc RTC to enable trickle charging of backup battery on.
 */
void am1815_enable_trickle(struct am1815 *rtc);

/** Disables the trickle charging of the backup battery on the RTC.
 *
 * @param[in,out] rtc RTC to disable trickle charging of backup battery of.
 */
void am1815_disable_trickle(struct am1815 *rtc);

/** Reads the time on the RTC.
 *
 * @param[in] rtc RTC to read the time of.
 *
 * @returns The RTC's time in seconds and microseconds. Note that the AM1815
 *  has at best centisecond resolution.
 */
struct timeval am1815_read_time(struct am1815 *rtc);

/** Reads the alarm time on the RTC.
 * 
 * @param[in] rtc RTC to read the time of.
 * 
 * @returns The RTC's alarm time in seconds and microseconds. Since there is no year,
 * we set the year to 0 (i.e, 0 years since 1900). Note that the AM1815 has at best
 * centiseconds resolution.
*/
struct timeval am1815_read_alarm(struct am1815 *rtc);

/** Writes the alarm time on the RTC.
 * 
 * @param[in, out] rtc RTC to write the alarm time of.
 * @param[in] atime The time in seconds and microseconds that we want to set the alarm to.
*/
void am1815_write_alarm(struct am1815 *rtc, struct timeval *atime);

#endif//AM1815_H_
